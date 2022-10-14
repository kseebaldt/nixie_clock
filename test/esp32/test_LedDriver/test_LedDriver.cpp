#include <Arduino.h>
#include <unity.h>

#include "LedDriver.h"
#include "ArduinoWrapper.h"

LedDriver driver(&arduino);

void setUp(void)
{
}

void tearDown(void)
{
}

void test_showColor_Off_write_to_leds(void)
{
    driver.showColor(0);
    delay(1);

    TEST_ASSERT_EQUAL(256, ledcRead(LedDriver::Channels::Red));
    TEST_ASSERT_EQUAL(256, ledcRead(LedDriver::Channels::Green));
    TEST_ASSERT_EQUAL(256, ledcRead(LedDriver::Channels::Blue));
}

void test_showColor_Red_write_to_leds(void)
{
    driver.showColor(0x00FF0000);
    delay(1);

    TEST_ASSERT_EQUAL(1, ledcRead(LedDriver::Channels::Red));
    TEST_ASSERT_EQUAL(256, ledcRead(LedDriver::Channels::Green));
    TEST_ASSERT_EQUAL(256, ledcRead(LedDriver::Channels::Blue));
}

void test_showColor_Green_write_to_leds(void)
{
    driver.showColor(0x0000FF00);
    delay(1);

    TEST_ASSERT_EQUAL(256, ledcRead(LedDriver::Channels::Red));
    TEST_ASSERT_EQUAL(1, ledcRead(LedDriver::Channels::Green));
    TEST_ASSERT_EQUAL(256, ledcRead(LedDriver::Channels::Blue));
}

void test_showColor_Blue_write_to_leds(void)
{
    driver.showColor(0x000000FF);
    delay(1);

    TEST_ASSERT_EQUAL(256, ledcRead(LedDriver::Channels::Red));
    TEST_ASSERT_EQUAL(256, ledcRead(LedDriver::Channels::Green));
    TEST_ASSERT_EQUAL(1, ledcRead(LedDriver::Channels::Blue));
}

void test_showColor_RGB_write_to_leds(void)
{
    driver.showColor(0x004080C0);
    delay(1);

    TEST_ASSERT_EQUAL(192, ledcRead(LedDriver::Channels::Red));
    TEST_ASSERT_EQUAL(128, ledcRead(LedDriver::Channels::Green));
    TEST_ASSERT_EQUAL(64, ledcRead(LedDriver::Channels::Blue));
}

#include <Arduino.h>
void setup()
{
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);
    driver.initPins(25, 26, 27);

    UNITY_BEGIN();

    RUN_TEST(test_showColor_Off_write_to_leds);
    RUN_TEST(test_showColor_Red_write_to_leds);
    RUN_TEST(test_showColor_Green_write_to_leds);
    RUN_TEST(test_showColor_Blue_write_to_leds);
    RUN_TEST(test_showColor_RGB_write_to_leds);

    UNITY_END();
}

void loop()
{
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(500);
}
