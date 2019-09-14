#include "DS3231.h"
#include <Arduino.h>
#include <Wire.h>

#define DS3231_ADDRESS        0x68  ///< I2C address for DS3231
#define DS3231_CONTROL        0x0E  ///< Control register
#define DS3231_STATUSREG      0x0F  ///< Status register
#define DS3231_TEMPERATUREREG	0x11  ///< Temperature register (high byte - low byte is at 0x12), 10-bit temperature value

static uint8_t read_i2c_register(uint8_t addr, uint8_t reg) {
    Wire.beginTransmission(addr);
    Wire.write((byte)reg);
    Wire.endTransmission();

    Wire.requestFrom(addr, (byte)1);
    return Wire.read();
}

static void write_i2c_register(uint8_t addr, uint8_t reg, uint8_t val) {
    Wire.beginTransmission(addr);
    Wire.write((byte)reg);
    Wire.write((byte)val);
    Wire.endTransmission();
}

static uint8_t bcd2bin (uint8_t val) { return val - 6 * (val >> 4); }
static uint8_t bin2bcd (uint8_t val) { return val + 6 * (val / 10); }

bool DS3231::begin(void) {
    Wire.begin();
    return true;
}

bool DS3231::lostPower(void) {
    return (read_i2c_register(DS3231_ADDRESS, DS3231_STATUSREG) >> 7);
}

void DS3231::adjust(const tm& timeinfo) {
    Wire.beginTransmission(DS3231_ADDRESS);
    Wire.write((byte)0); // start at location 0
    Wire.write(bin2bcd(timeinfo.tm_sec));
    Wire.write(bin2bcd(timeinfo.tm_min));
    Wire.write(bin2bcd(timeinfo.tm_hour));
    Wire.write(bin2bcd(0));
    Wire.write(bin2bcd(timeinfo.tm_mday));
    Wire.write(bin2bcd(timeinfo.tm_mon));
    Wire.write(bin2bcd(timeinfo.tm_year));
    Wire.endTransmission();

    uint8_t statreg = read_i2c_register(DS3231_ADDRESS, DS3231_STATUSREG);
    statreg &= ~0x80; // flip OSF bit
    write_i2c_register(DS3231_ADDRESS, DS3231_STATUSREG, statreg);
}

tm DS3231::now() {
    Wire.beginTransmission(DS3231_ADDRESS);
    Wire.write((byte)0);
    Wire.endTransmission();

    tm timeinfo;

    Wire.requestFrom(DS3231_ADDRESS, 7);
    timeinfo.tm_sec = bcd2bin(Wire.read() & 0x7F);
    timeinfo.tm_min = bcd2bin(Wire.read());
    timeinfo.tm_hour = bcd2bin(Wire.read());
    Wire.read();
    timeinfo.tm_mday = bcd2bin(Wire.read());
    timeinfo.tm_mon = bcd2bin(Wire.read());
    timeinfo.tm_year = bcd2bin(Wire.read());

    return timeinfo;
}

float DS3231::getTemperature()
{
    uint8_t msb, lsb;
    Wire.beginTransmission(DS3231_ADDRESS);
    Wire.write(DS3231_TEMPERATUREREG);
    Wire.endTransmission();

    Wire.requestFrom(DS3231_ADDRESS, 2);
    msb = Wire.read();
    lsb = Wire.read();

    return (float) msb + (lsb >> 6) * 0.25f;
}