#include <Arduino.h>

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
uint8_t pos = 0;
int count = 0;

void setup() {
    // Serial.begin(115200);

    pinMode(LATCH_PIN, OUTPUT);
    pinMode(CLOCK_PIN, OUTPUT);
    pinMode(DATA_PIN, OUTPUT);
  
    pinMode(CL0_PIN, OUTPUT);
    pinMode(CL1_PIN, OUTPUT);

    ledcSetup(R_LED_CHANNEL, 5000, 8);
    ledcAttachPin(R_LED_PIN, R_LED_CHANNEL);
    ledcSetup(G_LED_CHANNEL, 5000, 8);
    ledcAttachPin(G_LED_PIN, G_LED_CHANNEL);
    ledcSetup(B_LED_CHANNEL, 5000, 8);
    ledcAttachPin(B_LED_PIN, B_LED_CHANNEL);

    // setenv("TZ", TZ_INFO, 1);
    // tzset();
}

int ledCount = 0;

void loop() {

    ledcWrite(R_LED_CHANNEL, 256 - 200);
    ledcWrite(G_LED_CHANNEL, 256);
    ledcWrite(B_LED_CHANNEL, 256 - 200);

    // if (ledCount < 4) {
    //   ledcWrite(R_LED_CHANNEL, (ledCount % 4) * 32 + 31);
    // }
    // if (ledCount > 3 && ledCount < 8) {
    //   ledcWrite(R_LED_CHANNEL, ((ledCount-4) % 4) * 32 + 31);
    // }
    // if (ledCount > 7) {
    //   ledcWrite(R_LED_CHANNEL, ((ledCount-8) % 4) * 32 + 31);
    // }

    // ledcWrite(G_LED_CHANNEL, 40);
    // ledcWrite(B_LED_CHANNEL, 190);

//    getLocalTime(&timeinfo, 100);
//    Serial.println(&timeinfo, "%Y-%m-%d %H:%M:%S  %Z");

  // put your main code here, to run repeatedly:
   digitalWrite(LATCH_PIN, LOW);

  uint16_t data1 = digits[0] + digits[1] * 16;
  uint16_t data2 = digits[2] + digits[3] * 16;
  
   shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, data2); 
   shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, data1);
      
   digitalWrite(LATCH_PIN, HIGH);

   if (count < 4) {
    digitalWrite(CL0_PIN, HIGH);
    digitalWrite(CL1_PIN, HIGH);
   } else {
    digitalWrite(CL0_PIN, LOW);
    digitalWrite(CL1_PIN, LOW);
   }

   for (int i = 0; i < 4; ++i) {
     digits[i] = (digits[i] + 1) % 10;
   }

    pos = (pos + 1) % 40;
    count = (count + 1) % 8;
    delay(250);
}
