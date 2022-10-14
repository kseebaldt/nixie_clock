#include <Arduino.h>
#include <unity.h>

#include "LedDriver.h"
#include "ArduinoWrapper.h"

using namespace fakeit;

Mock<IArduino> mock;
LedDriver *driver;

void setUp(void)
{
    mock.Reset();

    IArduino &arduino = mock.get();
    driver = new LedDriver(&arduino);

    Fake(Method(mock, ledcWrite));
    Fake(Method(mock, ledcSetup));
    Fake(Method(mock, ledcAttachPin));

    driver->initPins(5, 7, 9);
}

void tearDown(void)
{
    delete driver;
}

void test_initPins_sets_up_led_pins(void)
{
    Verify(Method(mock, ledcSetup).Using(LedDriver::Channels::Red, 5000, 8));
    Verify(Method(mock, ledcSetup).Using(LedDriver::Channels::Green, 5000, 8));
    Verify(Method(mock, ledcSetup).Using(LedDriver::Channels::Blue, 5000, 8));

    Verify(Method(mock, ledcAttachPin).Using(5, LedDriver::Channels::Red));
    Verify(Method(mock, ledcAttachPin).Using(7, LedDriver::Channels::Green));
    Verify(Method(mock, ledcAttachPin).Using(9, LedDriver::Channels::Blue));
}

void test_showColor_Off_write_to_leds(void)
{
    driver->showColor(0);

    Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Red, 256));
    Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Green, 256));
    Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Blue, 256));
}

void test_showColor_Red_write_to_leds(void)
{
    driver->showColor(0x00FF0000);

    Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Red, 1));
    Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Green, 256));
    Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Blue, 256));
}

void test_showColor_Green_write_to_leds(void)
{
    driver->showColor(0x0000FF00);

    Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Red, 256));
    Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Green, 1));
    Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Blue, 256));
}

void test_showColor_Blue_write_to_leds(void)
{
    driver->showColor(0x000000FF);

    Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Red, 256));
    Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Green, 256));
    Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Blue, 1));
}

void test_showColor_RGB_write_to_leds(void)
{
    driver->showColor(0x004080C0);

    Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Red, 192));
    Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Green, 128));
    Verify(Method(mock, ledcWrite).Using(LedDriver::Channels::Blue, 64));
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();

    RUN_TEST(test_initPins_sets_up_led_pins);
    RUN_TEST(test_showColor_Off_write_to_leds);
    RUN_TEST(test_showColor_Red_write_to_leds);
    RUN_TEST(test_showColor_Green_write_to_leds);
    RUN_TEST(test_showColor_Blue_write_to_leds);
    RUN_TEST(test_showColor_RGB_write_to_leds);

    return UNITY_END();
}