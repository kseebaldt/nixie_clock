#include <Arduino.h>
#include <unity.h>

#define private public

#include "ArduinoWrapper.h"
#include <Button.h>

using namespace fakeit;

Mock<IArduino> mock;
Button *button;

void setUp(void)
{
    mock.Reset();

    IArduino &arduino = mock.get();
    button = new Button(&arduino);

    Fake(Method(mock, pinMode));
    button->init(5);
}

void tearDown(void)
{
    delete button;
}

void test_initPins_sets_pinMode(void)
{
    Verify(Method(mock, pinMode).Using(5, INPUT_PULLUP));
}

void test_tick_does_not_change_state_before_delay(void)
{
    When(Method(mock, digitalRead)).AlwaysReturn(HIGH);

    When(Method(mock, millis)).Return(0);
    button->tick();
    TEST_ASSERT_EQUAL(HIGH, button->state());

    When(Method(mock, millis)).Return(50);
    button->tick();

    TEST_ASSERT_EQUAL(HIGH, button->state());
}

void test_tick_changes_state_after_delay(void)
{
    When(Method(mock, digitalRead)).AlwaysReturn(LOW);

    When(Method(mock, millis)).Return(0);
    button->tick();

    When(Method(mock, millis)).Return(51);
    button->tick();

    TEST_ASSERT_EQUAL(LOW, button->state());
}

void test_tick_does_not_revert_state_before_delay(void)
{
    When(Method(mock, digitalRead)).AlwaysReturn(LOW);

    When(Method(mock, millis)).Return(0);
    button->tick();

    When(Method(mock, millis)).Return(51);
    button->tick();

    TEST_ASSERT_EQUAL(LOW, button->state());

    When(Method(mock, digitalRead)).AlwaysReturn(HIGH);

    When(Method(mock, millis)).Return(60);
    button->tick();

    When(Method(mock, millis)).Return(110);
    button->tick();

    TEST_ASSERT_EQUAL(LOW, button->state());
}

void test_tick_reverts_state_after_delay(void)
{
    When(Method(mock, millis)).Return(0);

    When(Method(mock, digitalRead)).AlwaysReturn(LOW);
    button->tick();

    When(Method(mock, millis)).Return(51);
    button->tick();

    TEST_ASSERT_EQUAL(LOW, button->state());

    When(Method(mock, digitalRead)).AlwaysReturn(HIGH);

    When(Method(mock, millis)).Return(60);
    button->tick();

    When(Method(mock, millis)).Return(111);
    button->tick();

    TEST_ASSERT_EQUAL(HIGH, button->state());
}

void test_tick_calls_callback_after_delay(void)
{
    int callCount = 0;
    button->onPress([&callCount](Button &b)
                    { ++callCount; });

    When(Method(mock, digitalRead)).AlwaysReturn(LOW);

    When(Method(mock, millis)).Return(0);
    button->tick();

    When(Method(mock, millis)).Return(51);

    button->tick();

    TEST_ASSERT_EQUAL(1, callCount);
    TEST_ASSERT_TRUE(!button->isLongPress());
}

void test_tick_calls_callback_again_after_repeatTime(void)
{
    int callCount = 0;
    button->onPress([&callCount](Button &b)
                    { ++callCount; },
                    100);

    When(Method(mock, digitalRead)).AlwaysReturn(LOW);

    When(Method(mock, millis)).Return(0);
    button->tick();

    When(Method(mock, millis)).Return(51);
    button->tick();

    When(Method(mock, millis)).Return(151);
    button->tick();

    When(Method(mock, millis)).Return(152);
    button->tick();

    TEST_ASSERT_EQUAL(2, callCount);
}

void test_tick_is_long_press_after_repeatTime(void)
{
    int callCount = 0;
    button->onPress([&callCount](Button &b)
                    { ++callCount; },
                    100);

    When(Method(mock, digitalRead)).AlwaysReturn(LOW);

    When(Method(mock, millis)).Return(0);
    button->tick();

    When(Method(mock, millis)).Return(51);
    button->tick();

    When(Method(mock, millis)).Return(151);
    button->tick();

    When(Method(mock, millis)).Return(152);
    button->tick();

    TEST_ASSERT_EQUAL(2, callCount);
    TEST_ASSERT_TRUE(button->isLongPress());
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();

    RUN_TEST(test_initPins_sets_pinMode);
    RUN_TEST(test_tick_does_not_change_state_before_delay);
    RUN_TEST(test_tick_changes_state_after_delay);
    RUN_TEST(test_tick_does_not_revert_state_before_delay);
    RUN_TEST(test_tick_reverts_state_after_delay);
    RUN_TEST(test_tick_calls_callback_after_delay);
    RUN_TEST(test_tick_calls_callback_again_after_repeatTime);
    RUN_TEST(test_tick_is_long_press_after_repeatTime);

    return UNITY_END();
}