#include "Clock.h"

uint16_t Clock::time() {
    int hour = (_timeinfo.tm_hour % 12);
    hour = hour == 0 ? 12 : hour;
    return hour * 100 + _timeinfo.tm_min;
}

uint16_t Clock::time24() {
    return _timeinfo.tm_hour * 100 + _timeinfo.tm_min;
}

uint16_t Clock::date() {
    return (_timeinfo.tm_mon + 1) * 100 + _timeinfo.tm_mday;
}

uint16_t Clock::year() {
    return _timeinfo.tm_year + 1900;
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
        _mode = TIME24;
        break;
    case TIME24:
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
    case TIME24:
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
    case TIME24:
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
