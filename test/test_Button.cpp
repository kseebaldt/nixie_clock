#include "catch.hpp"
#include "fakeit.hpp"

#define private public

#include "ArduinoWrapper.h"
#include <Button.h>

using namespace fakeit;

TEST_CASE("Init", "[button]") {
    Mock<IArduino> mock;
    IArduino &arduino = mock.get();
    Button button(&arduino);

    int callCount = 0;

    Fake(Method(mock, pinMode));
    button.init(5);

    SECTION("initPins sets pinMode") {
        Verify(Method(mock, pinMode).Using(5, INPUT_PULLUP));
        SUCCEED();
    }
    
    mock.Reset();

    SECTION("tick() does not change state before delay") {
        When(Method(mock, digitalRead)).AlwaysReturn(LOW);

        When(Method(mock, millis)).Return(0);
        button.tick();
        REQUIRE(button.state() == HIGH);

        When(Method(mock, millis)).Return(50);
        button.tick();

        REQUIRE(button.state() == HIGH);
        SUCCEED();
    }

    SECTION("tick() changes state after delay", "[button]") {
        When(Method(mock, digitalRead)).AlwaysReturn(LOW);

        When(Method(mock, millis)).Return(0);
        button.tick();

        When(Method(mock, millis)).Return(51);
        button.tick();

        REQUIRE(button.state() == LOW);
        SUCCEED();
    }

    SECTION("tick() does not revert state before delay", "[button]") {
        When(Method(mock, digitalRead)).AlwaysReturn(LOW);

        When(Method(mock, millis)).Return(0);
        button.tick();

        When(Method(mock, millis)).Return(51);
        button.tick();

        REQUIRE(button.state() == LOW);

        When(Method(mock, digitalRead)).AlwaysReturn(HIGH);

        When(Method(mock, millis)).Return(60);
        button.tick();

        When(Method(mock, millis)).Return(110);
        button.tick();

        REQUIRE(button.state() == LOW);
    }

    SECTION("tick() reverts state after delay", "[button]") {
        When(Method(mock, millis)).Return(0);

        When(Method(mock, digitalRead)).AlwaysReturn(LOW);
        button.tick();

        When(Method(mock, millis)).Return(51);
        button.tick();

        REQUIRE(button.state() == LOW);

        When(Method(mock, digitalRead)).AlwaysReturn(HIGH);

        When(Method(mock, millis)).Return(60);
        button.tick();

        When(Method(mock, millis)).Return(111);
        button.tick();

        REQUIRE(button.state() == HIGH);
    }

    SECTION("tick() calls callback after delay", "[button]") {
        callCount = 0;
        button.onPress([&callCount](Button &b) {
            ++callCount;
        });

        When(Method(mock, digitalRead)).AlwaysReturn(LOW);

        When(Method(mock, millis)).Return(0);
        button.tick();

        When(Method(mock, millis)).Return(51);

        button.tick();

        REQUIRE(callCount == 1);
        REQUIRE(!button.isLongPress());
    }

    SECTION("tick() calls callback again after repeatTime", "[button]") {
        callCount = 0;
        button.onPress([&callCount](Button &b) {
            ++callCount;
        }, 100);

        When(Method(mock, digitalRead)).AlwaysReturn(LOW);

        When(Method(mock, millis)).Return(0);
        button.tick();

        When(Method(mock, millis)).Return(51);
        button.tick();

        When(Method(mock, millis)).Return(151);
        button.tick();

        When(Method(mock, millis)).Return(152);
        button.tick();

        REQUIRE(callCount == 2);
    }

    SECTION("tick() is long press after repeatTime", "[button]") {
        callCount = 0;
        button.onPress([&callCount](Button &b) {
            ++callCount;
        }, 100);

        When(Method(mock, digitalRead)).AlwaysReturn(LOW);

        When(Method(mock, millis)).Return(0);
        button.tick();

        When(Method(mock, millis)).Return(51);
        button.tick();

        When(Method(mock, millis)).Return(151);
        button.tick();

        When(Method(mock, millis)).Return(152);
        button.tick();

        REQUIRE(callCount == 2);
        REQUIRE(button.isLongPress());
    }
}
