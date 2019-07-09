#include <Arduino.h>

#include <WiFi.h>
#include "lwip/apps/sntp.h"

#include "ArduinoWrapper.h"
#include "DisplayDriver.h"
#include "Clock.h"
#include "BLE_Server.h"
#include "NVStorage.h"
#include "Config.h"

#define DATA_PIN 16
#define CLOCK_PIN 17
#define LATCH_PIN 18

#define DISPLAY_MODE_PIN 19

#define CL0_PIN 2
#define CL1_PIN 4

#define R_LED_PIN 25
#define G_LED_PIN 26
#define B_LED_PIN 27
#define R_LED_CHANNEL 0
#define G_LED_CHANNEL 1
#define B_LED_CHANNEL 2

#define I2C_SCL_PIN 22
#define I2C_SDA_PIN 21

#define IS_SET(byte,bit) (((byte) & (1UL << (bit))) >> (bit))

const char* NTP_SERVER = "pool.ntp.org";

DisplayDriver driver(&arduino);
Clock _clock;

NVStorage storage("nixie-clock");
Config config(storage);
BLE::Server bleServer(config);

void WiFiGotIP(WiFiEvent_t event, WiFiEventInfo_t info)
{
    if(!sntp_enabled()){
        configTzTime(config.timeZone().c_str(), NTP_SERVER);
    }
}

void setup() {
    Serial.begin(115200);

    config.init();
    bleServer.init();

    driver.initPins(DATA_PIN, CLOCK_PIN, LATCH_PIN);
  
    pinMode(CL0_PIN, OUTPUT);
    pinMode(CL1_PIN, OUTPUT);

    ledcSetup(R_LED_CHANNEL, 5000, 8);
    ledcAttachPin(R_LED_PIN, R_LED_CHANNEL);
    ledcSetup(G_LED_CHANNEL, 5000, 8);
    ledcAttachPin(G_LED_PIN, G_LED_CHANNEL);
    ledcSetup(B_LED_CHANNEL, 5000, 8);
    ledcAttachPin(B_LED_PIN, B_LED_CHANNEL);

    ledcWrite(R_LED_CHANNEL, 256 - 100);
    ledcWrite(G_LED_CHANNEL, 256);
    ledcWrite(B_LED_CHANNEL, 256 - 100);

    setenv("TZ", config.timeZone().c_str(), 1);
    tzset();

    WiFi.onEvent(WiFiGotIP, WiFiEvent_t::SYSTEM_EVENT_STA_GOT_IP);
    WiFi.begin(config.ssid().c_str(), config.password().c_str());
}

void loop() {
    _clock.tick();
    bleServer.currentTimeService().update(_clock.now());

    Serial.println(&(_clock.now()), "%Y-%m-%d %H:%M:%S  %Z");

    driver.display(_clock.displayValue());

    uint8_t displayFlags = _clock.displayFlags();

    arduino.digitalWrite(CL0_PIN, IS_SET(displayFlags, 0));
    arduino.digitalWrite(CL1_PIN, IS_SET(displayFlags, 1));

    delay(100);
}
