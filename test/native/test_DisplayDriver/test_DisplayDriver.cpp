#include <Arduino.h>
#include <unity.h>

#include "DisplayDriver.h"
#include "ArduinoWrapper.h"

using namespace fakeit;

Mock<IArduino> mock;
DisplayDriver *driver;

void setUp(void)
{
    mock.Reset();

    IArduino &arduino = mock.get();
    driver = new DisplayDriver(&arduino);

    Fake(Method(mock, pinMode));
    driver->initPins(3, 4, 5);
}

void tearDown(void)
{
    delete driver;
}

void test_initPins_sets_pinMode(void)
{
    Verify(Method(mock, pinMode).Using(3, OUTPUT));
    Verify(Method(mock, pinMode).Using(4, OUTPUT));
    Verify(Method(mock, pinMode).Using(5, OUTPUT));

    Fake(Method(mock, digitalWrite));
    Fake(Method(mock, shiftOut));
}

void test_display_writes_to_latch_pins(void)
{
    Fake(Method(mock, digitalWrite));
    Fake(Method(mock, shiftOut));

    driver->display(1234);

    Verify(
        Method(mock, digitalWrite).Using(5, LOW) +
        Method(mock, shiftOut) +
        Method(mock, shiftOut) +
        Method(mock, digitalWrite).Using(5, HIGH));
}

void test_display_shifts_bytes(void)
{
    Fake(Method(mock, digitalWrite));
    Fake(Method(mock, shiftOut));

    driver->display(1234);

    Verify(
        Method(mock, shiftOut).Using(3, 4, MSBFIRST, 67) +
        Method(mock, shiftOut).Using(3, 4, MSBFIRST, 33));
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();

    RUN_TEST(test_initPins_sets_pinMode);
    RUN_TEST(test_display_writes_to_latch_pins);
    RUN_TEST(test_display_shifts_bytes);

    return UNITY_END();
}