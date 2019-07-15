#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <functional>
#include "ArduinoWrapper.h"

class Button {
    public:
        Button(IArduino *arduino);
        void init(uint8_t pin, uint16_t debounceDelay = 50);
        void tick();

        uint8_t state() const { return _state; }
        bool isLongPress() const { return _isLongPress; }

        void onPress(std::function<void (Button &b)> callback, uint16_t repeatTime = 0);
        void setRepeatTime(uint16_t repeatTime);

    private:
        IArduino* _arduino;

        uint8_t _pin;
        uint8_t _state;
        uint8_t _lastState;
        unsigned long _lastDebounceTime = 0;
        uint16_t _debounceDelay;
        unsigned long _lastCallBackTime = 0;
        std::function<void (Button& button)> _callback;
        uint16_t _repeatTime;
        bool _isLongPress = false;
};

#endif
