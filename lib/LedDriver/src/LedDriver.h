#ifndef _LED_DRIVER_H_
#define _LED_DRIVER_H_

#include "ArduinoWrapper.h"

class LedDriver {
    public:
        LedDriver(IArduino *arduinio);

        void initPins(uint8_t redPin, uint8_t greenPin, uint8_t bluePin);

        void showColor(uint32_t value);

        enum Channels {
            Red = 0,
            Green = 1,
            Blue = 2
        };

    private:
        uint8_t _redPin;
        uint8_t _greenPin;
        uint8_t _bluePin;

        IArduino *_arduino;
};

#endif /* _BCDDRIVER_H_ */
