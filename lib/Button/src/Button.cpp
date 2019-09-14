#include "Button.h"

Button::Button(IArduino *arduino) : _arduino(arduino) {}

void Button::init(uint8_t pin, uint16_t debounceDelay) {
    _pin = pin;
    _debounceDelay = debounceDelay;
    _state = HIGH;
    _lastState = HIGH;
    _lastDebounceTime = 0;

    _arduino->pinMode(_pin, INPUT_PULLUP);
}

void Button::onPress(std::function<void (Button &b)> callback, uint16_t repeatTime) {
    _callback = callback;
    _repeatTime = repeatTime;
}

void Button::setRepeatTime(uint16_t repeatTime) {
    _repeatTime = repeatTime;
}

void Button::tick() {
    unsigned long now = _arduino->millis();

    int reading = _arduino->digitalRead(_pin);
    
    if (reading != _lastState) {
        _lastDebounceTime = now;
    }

    if ((now - _lastDebounceTime) > _debounceDelay) {
        if (reading != _state) {
            _state = reading;
            _lastCallBackTime = 0;
            _isLongPress = false;
        }
    }

    if (_state == LOW && _callback != NULL) {
        if (_lastCallBackTime == 0 ||
            (_repeatTime != 0 && now - _lastCallBackTime >= _repeatTime)) {
            _callback(*this);
            _isLongPress = _lastCallBackTime != 0;
            _lastCallBackTime = now;
        }
    }

    _lastState = reading;
}