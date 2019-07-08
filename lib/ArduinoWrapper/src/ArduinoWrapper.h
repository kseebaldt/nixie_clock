#ifndef _ARDUINOWRAPPER_H_
#define _ARDUINOWRAPPER_H_

#ifdef ARDUINO
    #include "Arduino.h"
#else
    #include "FakeArduino.h"
#endif

class IArduino {
    public:
        virtual void pinMode(uint8_t, uint8_t) = 0;
        virtual void digitalWrite(uint8_t, uint8_t) = 0;
        virtual int digitalRead(uint8_t) = 0;
        virtual void delay(unsigned long) = 0;
        virtual unsigned long millis(void) = 0;
        virtual void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val) = 0;
};

class ArduinoWrapper : public IArduino {
    public:
        virtual void pinMode(uint8_t, uint8_t);
        virtual void digitalWrite(uint8_t, uint8_t);
        virtual int digitalRead(uint8_t);
        virtual void delay(unsigned long);
        virtual unsigned long millis(void);
        virtual void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val);
   
    // private:
    //     struct FakeArduino;
};

extern ArduinoWrapper arduino;

#endif /* _ARDUINOWRAPPER_H_ */
