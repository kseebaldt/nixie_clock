#include "ArduinoWrapper.h"

ArduinoWrapper arduino;

#ifdef ARDUINO

void ArduinoWrapper::pinMode(uint8_t pin, uint8_t mode) {
    ::pinMode(pin, mode);
}

void ArduinoWrapper::digitalWrite(uint8_t pin, uint8_t val) {
    ::digitalWrite(pin, val);
}

int ArduinoWrapper::digitalRead(uint8_t pin) {
    return ::digitalRead(pin);
}

void ArduinoWrapper::delay(unsigned long millis) {
    ::delay(millis);
}

unsigned long ArduinoWrapper::millis(void) {
    return ::millis();
}

void ArduinoWrapper::shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val) {
    ::shiftOut(dataPin, clockPin, bitOrder, val);
}

double ArduinoWrapper::ledcSetup(uint8_t channel, double freq, uint8_t resolution_bits) {
    return ::ledcSetup(channel, freq, resolution_bits);
}

void ArduinoWrapper::ledcWrite(uint8_t channel, uint32_t duty) {
    ::ledcWrite(channel, duty);
}

void ArduinoWrapper::ledcAttachPin(uint8_t pin, uint8_t channel) {
    ::ledcAttachPin(pin, channel);
}

#else

void ArduinoWrapper::pinMode(uint8_t pin, uint8_t mode) {}
void ArduinoWrapper::digitalWrite(uint8_t pin, uint8_t val) {}
int ArduinoWrapper::digitalRead(uint8_t pin) { return 0; }
void ArduinoWrapper::delay(unsigned long millis) {}
unsigned long ArduinoWrapper::millis(void) { return 0; }
void ArduinoWrapper::shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val) {}
double ArduinoWrapper::ledcSetup(uint8_t channel, double freq, uint8_t resolution_bits) { return 0.0; }
void ArduinoWrapper::ledcWrite(uint8_t channel, uint32_t duty) {}
void ArduinoWrapper::ledcAttachPin(uint8_t pin, uint8_t channel) {}

#endif