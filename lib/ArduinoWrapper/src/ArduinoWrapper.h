#ifndef _ARDUINOWRAPPER_H_
#define _ARDUINOWRAPPER_H_

#include <Arduino.h>

class IArduino
{
public:
    virtual void pinMode(uint8_t, uint8_t) = 0;
    virtual void digitalWrite(uint8_t, uint8_t) = 0;
    virtual int digitalRead(uint8_t) = 0;
    virtual void delay(unsigned long) = 0;
    virtual unsigned long millis(void) = 0;
    virtual void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val) = 0;

    virtual double ledcSetup(uint8_t channel, double freq, uint8_t resolution_bits) = 0;
    virtual void ledcWrite(uint8_t channel, uint32_t duty) = 0;
    virtual void ledcAttachPin(uint8_t pin, uint8_t channel) = 0;
};

class ArduinoWrapper : public IArduino
{
public:
    virtual void pinMode(uint8_t, uint8_t);
    virtual void digitalWrite(uint8_t, uint8_t);
    virtual int digitalRead(uint8_t);
    virtual void delay(unsigned long);
    virtual unsigned long millis(void);
    virtual void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val);

    virtual double ledcSetup(uint8_t channel, double freq, uint8_t resolution_bits);
    virtual void ledcWrite(uint8_t channel, uint32_t duty);
    virtual void ledcAttachPin(uint8_t pin, uint8_t channel);
};

extern ArduinoWrapper arduino;

#endif /* _ARDUINOWRAPPER_H_ */
