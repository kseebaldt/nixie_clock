#ifndef _CLOCK_H_
#define _CLOCK_H_

#include <time.h>
#include <sys/time.h>
#include <stdint.h>

enum ClockMode {
    TIME,
    TIME24,
    DATE,
    YEAR
};

class Clock {
    public:
        void setDateTime(tm timeinfo);
        tm& now();

        void tick();

        uint16_t time();
        uint16_t time24();
        uint16_t date();
        uint16_t year();

        ClockMode mode() const       { return _mode; }
        void setMode(ClockMode mode);
        void nextMode();

        uint16_t displayValue();
        uint8_t displayFlags();
        void button1();

    private:
        ClockMode _mode = TIME;
        tm _timeinfo;
};

#endif
