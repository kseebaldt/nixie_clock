#include <Arduino.h>

#define DATA_PIN 16
#define CLOCK_PIN 18
#define LATCH_PIN 17

#define DISPLAY_MODE_PIN 19

#define CL1_PIN 25
#define CL2_PIN 26

#define R_LED_PIN 25
#define G_LED_PIN 26
#define B_LED_PIN 27

#define I2C_SCL_PIN 22
#define I2C_SDA_PIN 21

const char* TZ_INFO    = "CST6CDT5,M3.2.0/02:00:00,M11.1.0/02:00:00";
struct tm timeinfo;

void setup() {
    Serial.begin(115200);

    setenv("TZ", TZ_INFO, 1);
    tzset();
}

void loop() {
    getLocalTime(&timeinfo, 100);
    Serial.println(&timeinfo, "%Y-%m-%d %H:%M:%S  %Z");

    delay(1000);
}
