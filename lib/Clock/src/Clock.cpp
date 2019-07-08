#include "Clock.h"

uint16_t Clock::time() {
    return _timeinfo.tm_hour * 100 + _timeinfo.tm_min;
}

uint16_t Clock::date() {
    return _timeinfo.tm_mon * 100 + _timeinfo.tm_mday;
}

uint16_t Clock::year() {
    return _timeinfo.tm_year;
}

void Clock::setDateTime(tm timeinfo) {
    _timeinfo = timeinfo;
}

tm& Clock::now() {
    return _timeinfo;
}

void Clock::tick() {
    time_t now;
    ::time(&now);
    ::localtime_r(&now, &_timeinfo);
}

void Clock::setMode(ClockMode mode) {
    _mode = mode;
}

void Clock::nextMode() {
    switch (_mode)
    {
    case TIME:
        _mode = DATE;
        break;
    case DATE:
        _mode = YEAR;
        break;
    case YEAR:
        _mode = TIME;
        break;
    }
}

uint16_t Clock::displayValue() {
    switch (_mode)
    {
    case TIME:
        return time();
    case DATE:
        return date();
    case YEAR:
        return year();
    default:
        return time();
    }
}

uint8_t Clock::displayFlags() {
    uint8_t flags;
    switch (_mode)
    {
    case TIME:
        flags = _timeinfo.tm_sec % 2 == 0 ? 3 : 0;
        break;
    case DATE:
        flags = 2;
        break;
    case YEAR:
    default:
        flags = 0;
    }

    return flags;
}

void Clock::button1() {
    nextMode();
}
