#include <unity.h>

#include "DisplayDriver.h"
#include "ArduinoWrapper.h"
#include "fakeit.hpp"

using namespace fakeit;

namespace Test_DisplayDriver {
    Mock<IArduino> mock;
    IArduino &arduino = mock.get();
    DisplayDriver driver(&arduino);

    void test_initPins() {
        mock.Reset();

        Fake(Method(mock, pinMode));
        driver.initPins(5, 7, 9);

        Verify(Method(mock, pinMode).Using(5, OUTPUT));
        Verify(Method(mock, pinMode).Using(7, OUTPUT));
        Verify(Method(mock, pinMode).Using(9, OUTPUT));
    }

    void test_display_writesToLatchPins() {
        Fake(Method(mock, pinMode));

        driver.initPins(3, 4, 5);
        mock.Reset();

        Fake(Method(mock, digitalWrite));
        Fake(Method(mock, shiftOut));

        driver.display(1234);

        Verify(
            Method(mock, digitalWrite).Using(5, LOW) + 
            Method(mock, shiftOut) + 
            Method(mock, shiftOut) + 
            Method(mock, digitalWrite).Using(5, HIGH)
        );
    }

    void test_display_shiftsBytes() {
        Fake(Method(mock, pinMode));

        driver.initPins(3, 4, 5);
        mock.Reset();

        Fake(Method(mock, digitalWrite));
        Fake(Method(mock, shiftOut));

        driver.display(1234);

        Verify(
            Method(mock, shiftOut).Using(3, 4, MSBFIRST, 67) +
            Method(mock, shiftOut).Using(3, 4, MSBFIRST, 33)
        );
    }

    void runTests() {
        RUN_TEST(test_initPins);
        RUN_TEST(test_display_writesToLatchPins);
        RUN_TEST(test_display_shiftsBytes);
    }
}