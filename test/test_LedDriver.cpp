#include "catch.hpp"
#include "fakeit.hpp"

#include "LedDriver.h"
#include "ArduinoWrapper.h"

using namespace fakeit;

TEST_CASE("LedDriver", "[led_driver]") {
    Mock<IArduino> mock;
    IArduino &arduino = mock.get();
    LedDriver driver(&arduino);

    Fake(Method(mock, ledcSetup));
    Fake(Method(mock, ledcAttachPin));

    driver.initPins(5, 7, 9);

    SECTION("initPins sets up led pins") {
        Verify(Method(mock, ledcSetup).Using(LedDriver::Channels::Red, 5000, 8));
        Verify(Method(mock, ledcSetup).Using(LedDriver::Channels::Green, 5000, 8));
        Verify(Method(mock, ledcSetup).Using(LedDriver::Channels::Blue, 5000, 8));

        Verify(Method(mock, ledcAttachPin).Using(5, LedDriver::Channels::Red));
        Verify(Method(mock, ledcAttachPin).Using(7, LedDriver::Channels::Green));
        Verify(Method(mock, ledcAttachPin).Using(9, LedDriver::Channels::Blue));

        SUCCEED();
    }
    mock.Reset();
    Fake(Method(mock, ledcWrite));

    SECTION("showColor Off write to leds") {
        driver.showColor(0);

        Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Red, 256));
        Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Green, 256));
        Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Blue, 256));

        SUCCEED();
    }

    SECTION("showColor Red write to leds") {
        driver.showColor(0x00FF0000);

        Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Red, 1));
        Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Green, 256));
        Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Blue, 256));
    
        SUCCEED();
    }

    SECTION("showColor Green write to leds") {
        driver.showColor(0x0000FF00);

        Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Red, 256));
        Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Green, 1));
        Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Blue, 256));

        SUCCEED();
    }

    SECTION("showColor Blue write to leds") {
        driver.showColor(0x000000FF);

        Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Red, 256));
        Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Green, 256));
        Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Blue, 1));

        SUCCEED();
    }

    SECTION("showColor RGB write to leds") {
        driver.showColor(0x004080C0);

        Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Red, 192));
        Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Green, 128));
        Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Blue, 64));

        SUCCEED();
    }
}