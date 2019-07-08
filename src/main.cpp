#include <Arduino.h>
#include "ArduinoWrapper.h"
#include "DisplayDriver.h"

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

const char* TZ_INFO    = "CST6CDT5,M3.2.0/02:00:00,M11.1.0/02:00:00";
struct tm timeinfo;

uint8_t digits[4] = {1, 3, 5, 7};

DisplayDriver driver(&arduino);

void setup() {
    // Serial.begin(115200);

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

    // setenv("TZ", TZ_INFO, 1);
    // tzset();
}

void loop() {
  //  getLocalTime(&timeinfo, 100);
  //  Serial.println(&timeinfo, "%Y-%m-%d %H:%M:%S  %Z");

    // put your main code here, to run repeatedly:
//    driver.display(digits[0] + digits[1] * 10 + digits[2] * 100 + digits[3] * 1000);
    driver.display(1234);

    unsigned long now = millis();

    digitalWrite(CL0_PIN, now % 2000 < 1000);
    digitalWrite(CL1_PIN, now % 2000 < 1000);

   for (int i = 0; i < 4; ++i) {
     digits[i] = (digits[i] + 1) % 10;
   }

    delay(100);
}
