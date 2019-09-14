#ifndef _DS3231_H_
#define _DS3231_H_

#include <time.h>

class DS3231 {
    public:
        bool begin();
        bool lostPower();
        void adjust(const tm& timeinfo);
        tm now();
        float getTemperature();
};

#endif
