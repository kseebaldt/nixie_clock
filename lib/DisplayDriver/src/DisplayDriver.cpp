#include "DisplayDriver.h"
#include "ArduinoWrapper.h"

DisplayDriver::DisplayDriver(IArduino *arduino) {
    _arduino = arduino;
}

void DisplayDriver::initPins(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin) {
    _dataPin = dataPin;
    _clockPin = clockPin;
    _latchPin = latchPin;

    _arduino->pinMode(_dataPin, OUTPUT);
    _arduino->pinMode(_clockPin, OUTPUT);
    _arduino->pinMode(_latchPin, OUTPUT);
}

void DisplayDriver::display(uint16_t value) {
    uint8_t first = (value / 10 % 10) + (value % 10  * 16);
    uint8_t second = (value / 1000) + (value / 100 % 10 * 16);

    _arduino->digitalWrite(_latchPin, LOW);
    _arduino->shiftOut(_dataPin, _clockPin, MSBFIRST, first); 
    _arduino->shiftOut(_dataPin, _clockPin, MSBFIRST, second);
    _arduino->digitalWrite(_latchPin, HIGH);
}
