#include "LedDriver.h"
#include "ArduinoWrapper.h"

LedDriver::LedDriver(IArduino *arduino) {
    _arduino = arduino;
}

void LedDriver::initPins(uint8_t redPin, uint8_t greenPin, uint8_t bluePin) {
    _redPin = redPin;
    _greenPin = greenPin;
    _bluePin = bluePin;

    _arduino->ledcSetup(Channels::Red, 5000, 8);
    _arduino->ledcAttachPin(_redPin, Channels::Red);
    _arduino->ledcSetup(Channels::Green, 5000, 8);
    _arduino->ledcAttachPin(_greenPin, Channels::Green);
    _arduino->ledcSetup(Channels::Blue, 5000, 8);
    _arduino->ledcAttachPin(_bluePin, Channels::Blue);
}

void LedDriver::showColor(uint32_t color) {
    int r = (color >> (8*2)) & 0xff;
    int g = (color >> (8*1)) & 0xff;
    int b = (color >> (8*0)) & 0xff;

    _arduino->ledcWrite(Channels::Red, 256 - r);
    _arduino->ledcWrite(Channels::Green, 256 - g);
    _arduino->ledcWrite(Channels::Blue, 256 - b);
}
