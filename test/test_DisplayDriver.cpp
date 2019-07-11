#include "catch.hpp"
#include "fakeit.hpp"

#include "DisplayDriver.h"
#include "ArduinoWrapper.h"

using namespace fakeit;

TEST_CASE("DisplayDriver", "[display_driver]") {
    Mock<IArduino> mock;
    IArduino &arduino = mock.get();
    DisplayDriver driver(&arduino);

    Fake(Method(mock, pinMode));
    driver.initPins(3, 4, 5);

    SECTION("initPins sets pinMode") {
        Verify(Method(mock, pinMode).Using(3, OUTPUT));
        Verify(Method(mock, pinMode).Using(4, OUTPUT));
        Verify(Method(mock, pinMode).Using(5, OUTPUT));

        SUCCEED();
    }

    mock.Reset();

    SECTION("display writes to latch pins") {
        Fake(Method(mock, digitalWrite));
        Fake(Method(mock, shiftOut));

        driver.display(1234);

        Verify(
            Method(mock, digitalWrite).Using(5, LOW) + 
            Method(mock, shiftOut) + 
            Method(mock, shiftOut) + 
            Method(mock, digitalWrite).Using(5, HIGH)
        );

        SUCCEED();  
    }

    SECTION("display shifts bytes") {
        Fake(Method(mock, digitalWrite));
        Fake(Method(mock, shiftOut));

        driver.display(1234);

        Verify(
            Method(mock, shiftOut).Using(3, 4, MSBFIRST, 67) +
            Method(mock, shiftOut).Using(3, 4, MSBFIRST, 33)
        );  

        SUCCEED();     
    }
}