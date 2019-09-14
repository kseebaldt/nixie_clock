#include <Arduino.h>

#include <WiFi.h>
#include "lwip/apps/sntp.h"
#include <ArduinoOTA.h>

#include "ArduinoWrapper.h"
#include "DisplayDriver.h"
#include "LedDriver.h"
#include "Clock.h"
#include "BLE_Server.h"
#include "NVStorage.h"
#include "Config.h"
#include "Button.h"
#include "DS3231.h"

#define DATA_PIN 16
#define CLOCK_PIN 17
#define LATCH_PIN 18

#define DISPLAY_MODE_PIN 19

#define CL0_PIN 4
#define CL1_PIN 2

#define R_LED_PIN 25
#define G_LED_PIN 26
#define B_LED_PIN 27

#define I2C_SCL_PIN 22
#define I2C_SDA_PIN 21

#define IS_SET(byte,bit) (((byte) & (1UL << (bit))) >> (bit))

const char* NTP_SERVER = "pool.ntp.org";

DisplayDriver driver(&arduino);
LedDriver ledDriver(&arduino);
Button button(&arduino);
Clock _clock;

NVStorage storage("nixie-clock");
Config config(storage);
BLE::Server bleServer(config);
DS3231 rtc;

void WiFiGotIP(WiFiEvent_t event, WiFiEventInfo_t info)
{
    if(!sntp_enabled()){
        configTzTime(config.timeZone().c_str(), NTP_SERVER);
    }

  ArduinoOTA
    .onStart([]() {
      String type;
      if (ArduinoOTA.getCommand() == U_FLASH)
        type = "sketch";
      else // U_SPIFFS
        type = "filesystem";

      // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
      Serial.println("Start updating " + type);
    })
    .onEnd([]() {
      Serial.println("\nEnd");
    })
    .onProgress([](unsigned int progress, unsigned int total) {
      Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    })
    .onError([](ota_error_t error) {
      Serial.printf("Error[%u]: ", error);
      if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
      else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
      else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
      else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
      else if (error == OTA_END_ERROR) Serial.println("End Failed");
    });

    ArduinoOTA.begin();    
}

void configChanged(Config& config, Config::Types type) {
    switch(type) {
        case Config::Types::TIME_ZONE:
            setenv("TZ", config.timeZone().c_str(), 1);
            tzset();
            break;
        case Config::Types::SSID:
        case Config::Types::PASSWORD:
            WiFi.disconnect();
            WiFi.begin(config.ssid().c_str(), config.password().c_str());
            break;
        default:
            break;
    }
}

void setup() {
    Serial.begin(115200);

    config.init();
    bleServer.init();
    rtc.begin();

    // set clock from rtc
    tm timeinfo = rtc.now();
    time_t t = mktime(&timeinfo);
    struct timeval now = { .tv_sec = t };
    settimeofday(&now, NULL);

    driver.initPins(DATA_PIN, CLOCK_PIN, LATCH_PIN);
    ledDriver.initPins(R_LED_PIN, G_LED_PIN, B_LED_PIN);
    button.init(DISPLAY_MODE_PIN, 200);
    button.onPress([] (Button& button) {
        _clock.nextMode();
    });

    pinMode(CL0_PIN, OUTPUT);
    pinMode(CL1_PIN, OUTPUT);

    setenv("TZ", config.timeZone().c_str(), 1);
    tzset();

    WiFi.onEvent(WiFiGotIP, WiFiEvent_t::SYSTEM_EVENT_STA_GOT_IP);
    WiFi.begin(config.ssid().c_str(), config.password().c_str());
}

void loop() {
    ArduinoOTA.handle();

    button.tick();
    _clock.tick();

    tm timeinfo;
    time_t now;
    ::time(&now);
    ::gmtime_r(&now, &timeinfo);
    if (timeinfo.tm_year > 100) {
      rtc.adjust(timeinfo);
    }

    bleServer.currentTimeService().update(_clock.now());

    driver.display(_clock.displayValue());
    ledDriver.showColor(config.ledColor());

    uint8_t displayFlags = _clock.displayFlags();

    arduino.digitalWrite(CL0_PIN, IS_SET(displayFlags, 0));
    arduino.digitalWrite(CL1_PIN, IS_SET(displayFlags, 1));

    delay(100);
}
