#include "BLE_CurrentTimeService.h"

#include <Arduino.h>
#include <BLE2902.h>
#include <sys/time.h>
#include <time.h>

extern long int _timezone;
extern  char * tzname [2];

namespace BLE {
    typedef struct {
        uint16_t year;
        uint8_t  month;
        uint8_t  day;
        uint8_t  hours;
        uint8_t  minutes;
        uint8_t  seconds;
        uint8_t  dayOfWeek;
        uint8_t fractions256;
        uint8_t adjustReason;
    } CurrentTime;

    typedef struct {
        int8_t timeZone;
        uint8_t dstOffset;
    } LocalTimeInfo;

    CurrentTimeCallbacks::~CurrentTimeCallbacks() {}

    void CurrentTimeCallbacks::onRead(BLECharacteristic* pCharacteristic) {

    }

    void CurrentTimeCallbacks::onWrite(BLECharacteristic* pCharacteristic) {
        Serial.println("Current Time Written!");
        CurrentTime *currentTime = (CurrentTime *)pCharacteristic->getData();

        tm timeinfo;
        timeinfo.tm_year = currentTime->year - 1900;
        timeinfo.tm_mon = currentTime->month - 1;
        timeinfo.tm_mday = currentTime->day;
        timeinfo.tm_hour = currentTime->hours;
        timeinfo.tm_min = currentTime->minutes;
        timeinfo.tm_sec = currentTime->seconds;

        Serial.println(&timeinfo, "%Y-%m-%d %H:%M:%S");

        timeval newTime;
        newTime.tv_sec = mktime(&timeinfo);

        settimeofday(&newTime, NULL);
    }

    CurrentTimeService::CurrentTimeService() : 
        _uuid((uint16_t)0x1805),
        _currentTimeCharacteristic(BLEUUID((uint16_t)0x2A2B), BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE),
        _localTimeInfoCharacteristic(BLEUUID((uint16_t)0x2A0F), BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE) {

    }

    void CurrentTimeService::createService(BLEServer *server) {
        BLEService *service = server->createService(_uuid);
        _currentTimeCharacteristic.addDescriptor(new BLE2902());
        _currentTimeCharacteristic.setCallbacks(&_callbacks);
        service->addCharacteristic(&_currentTimeCharacteristic);
        service->addCharacteristic(&_localTimeInfoCharacteristic);
        service->start();
    }

    void CurrentTimeService::update(tm timeinfo) {
        CurrentTime currentTime = {
            .year = (uint16_t) (timeinfo.tm_year + 1900),
            .month = (uint8_t) (timeinfo.tm_mon + 1),
            .day = (uint8_t) timeinfo.tm_mday,
            .hours = (uint8_t) timeinfo.tm_hour,
            .minutes = (uint8_t) timeinfo.tm_min,
            .seconds = (uint8_t) timeinfo.tm_sec,
            .dayOfWeek = (uint8_t) (timeinfo.tm_wday == 0 ? 7 : timeinfo.tm_wday),
            .fractions256 = 0,
            .adjustReason = 0
        };

        char tzbuf[8];

        strftime(tzbuf, 8, "%Z", &timeinfo);

        LocalTimeInfo localTimeInfo = {
            .timeZone = -_timezone / 900,
            .dstOffset = strcmp(tzbuf, tzname[1]) == 0 ? 4 : 0
        };

        _currentTimeCharacteristic.setValue((uint8_t *)&currentTime, sizeof(CurrentTime));
        _localTimeInfoCharacteristic.setValue((uint8_t *)&localTimeInfo, sizeof(LocalTimeInfo));
    }
}