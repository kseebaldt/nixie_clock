#include <unity.h>

#include "LedDriver.h"
#include "ArduinoWrapper.h"
#include "fakeit.hpp"

using namespace fakeit;

namespace Test_LedDriver {
    Mock<IArduino> mock;
    IArduino &arduino = mock.get();
    LedDriver driver(&arduino);

    void test_initPins() {
        mock.Reset();

        Fake(Method(mock, ledcSetup));
        Fake(Method(mock, ledcAttachPin));
        driver.initPins(5, 7, 9);

        Verify(Method(mock, ledcSetup).Using(LedDriver::Channels::Red, 5000, 8));
        Verify(Method(mock, ledcSetup).Using(LedDriver::Channels::Green, 5000, 8));
        Verify(Method(mock, ledcSetup).Using(LedDriver::Channels::Blue, 5000, 8));

        Verify(Method(mock, ledcAttachPin).Using(5, LedDriver::Channels::Red));
        Verify(Method(mock, ledcAttachPin).Using(7, LedDriver::Channels::Green));
        Verify(Method(mock, ledcAttachPin).Using(9, LedDriver::Channels::Blue));
    }

    void test_showColor_Off() {
        driver.showColor(0);

        Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Red, 256));
        Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Green, 256));
        Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Blue, 256));
    }

    void test_showColor_Red() {
        driver.showColor(0x00FF0000);

        Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Red, 0));
        Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Green, 256));
        Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Blue, 256));
    }

    void test_showColor_Green() {
        driver.showColor(0x0000FF00);

        Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Red, 256));
        Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Green, 0));
        Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Blue, 256));
    }

    void test_showColor_Blue() {
        driver.showColor(0x000000FF);

        Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Red, 256));
        Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Green, 256));
        Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Blue, 0));
    }

    void test_showColor_RGB() {
        driver.showColor(0x004080C0);

        Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Red, 192));
        Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Green, 128));
        Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Blue, 64));
    }   

    void runTests() {
        RUN_TEST(test_initPins);
        // RUN_TEST(test_showColor_Red);
        // RUN_TEST(test_showColor_Green);
        // RUN_TEST(test_showColor_Blue);
        // RUN_TEST(test_showColor_RGB);
    }
}