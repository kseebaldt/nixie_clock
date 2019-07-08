#ifndef _DISPLAY_DRIVER_H_
#define _DISPLAY_DRIVER_H_

#include "ArduinoWrapper.h"

class DisplayDriver {
    public:
        DisplayDriver(IArduino *arduinio);

        void initPins(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin);

        void display(uint16_t value);

    private:
        uint8_t _dataPin;
        uint8_t _clockPin;
        uint8_t _latchPin;

        IArduino *_arduino;
};

#endif /* _BCDDRIVER_H_ */
