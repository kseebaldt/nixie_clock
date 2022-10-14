#include <unity.h>

#define private public

#include <Clock.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_setDateTime(void)
{
    Clock clock;

    tm timeinfo;
    timeinfo.tm_year = 119;
    timeinfo.tm_mon = 5;
    timeinfo.tm_mday = 12;
    timeinfo.tm_hour = 3;
    timeinfo.tm_min = 45;
    timeinfo.tm_sec = 56;

    clock.setDateTime(timeinfo);

    tm currentTime = clock.now();

    TEST_ASSERT_EQUAL(119, currentTime.tm_year);
    TEST_ASSERT_EQUAL(5, currentTime.tm_mon);
    TEST_ASSERT_EQUAL(12, currentTime.tm_mday);
    TEST_ASSERT_EQUAL(3, currentTime.tm_hour);
    TEST_ASSERT_EQUAL(45, currentTime.tm_min);
    TEST_ASSERT_EQUAL(56, currentTime.tm_sec);
}

void test_time_shows_1_digit_hour(void)
{
    Clock clock;

    tm timeinfo;
    timeinfo.tm_hour = 3;
    timeinfo.tm_min = 45;

    clock.setDateTime(timeinfo);

    tm currentTime = clock.now();

    TEST_ASSERT_EQUAL(345, clock.time());
}

void test_time_shows_2_digit_hour(void)
{
    Clock clock;

    tm timeinfo;
    timeinfo.tm_hour = 12;
    timeinfo.tm_min = 45;

    clock.setDateTime(timeinfo);

    TEST_ASSERT_EQUAL(1245, clock.time());
}

void test_time_shows_midnight(void)
{
    Clock clock;

    tm timeinfo;
    timeinfo.tm_hour = 0;
    timeinfo.tm_min = 45;

    clock.setDateTime(timeinfo);

    TEST_ASSERT_EQUAL(1245, clock.time());
}

void test_time_shows_2_digit_hour_PM(void)
{
    Clock clock;

    tm timeinfo;
    timeinfo.tm_hour = 14;
    timeinfo.tm_min = 45;

    clock.setDateTime(timeinfo);

    TEST_ASSERT_EQUAL(245, clock.time());
}

void test_time24_shows_1_digit_hour(void)
{
    Clock clock;

    tm timeinfo;
    timeinfo.tm_hour = 3;
    timeinfo.tm_min = 45;

    clock.setDateTime(timeinfo);

    tm currentTime = clock.now();

    TEST_ASSERT_EQUAL(345, clock.time24());
}

void test_time24_shows_2_digit_hour(void)
{
    Clock clock;

    tm timeinfo;
    timeinfo.tm_hour = 12;
    timeinfo.tm_min = 45;

    clock.setDateTime(timeinfo);

    TEST_ASSERT_EQUAL(1245, clock.time24());
}

void test_time24_shows_midnight(void)
{
    Clock clock;

    tm timeinfo;
    timeinfo.tm_hour = 0;
    timeinfo.tm_min = 45;

    clock.setDateTime(timeinfo);

    TEST_ASSERT_EQUAL(45, clock.time24());
}

void test_time24_shows_2_digit_hour_PM()
{
    Clock clock;

    tm timeinfo;
    timeinfo.tm_hour = 14;
    timeinfo.tm_min = 45;

    clock.setDateTime(timeinfo);

    TEST_ASSERT_EQUAL(1445, clock.time24());
}

void test_date_shows_1_digit_month(void)
{
    Clock clock;

    tm timeinfo;
    timeinfo.tm_mon = 5;
    timeinfo.tm_mday = 12;

    clock.setDateTime(timeinfo);

    TEST_ASSERT_EQUAL(612, clock.date());
}

void test_date_shows_2_digit_month(void)
{
    Clock clock;

    tm timeinfo;
    timeinfo.tm_mon = 10;
    timeinfo.tm_mday = 12;

    clock.setDateTime(timeinfo);

    TEST_ASSERT_EQUAL(1112, clock.date());
}

void test_date_shows_1_digit_day(void)
{
    Clock clock;

    tm timeinfo;
    timeinfo.tm_mon = 5;
    timeinfo.tm_mday = 8;

    clock.setDateTime(timeinfo);

    TEST_ASSERT_EQUAL(608, clock.date());
}

void test_year(void)
{
    Clock clock;

    tm timeinfo;
    timeinfo.tm_year = 119;

    clock.setDateTime(timeinfo);

    TEST_ASSERT_EQUAL(2019, clock.year());
}

void test_display_shows_time_in_Time_mode(void)
{
    Clock clock;

    tm timeinfo;
    timeinfo.tm_year = 119;
    timeinfo.tm_mon = 5;
    timeinfo.tm_mday = 8;
    timeinfo.tm_hour = 12;
    timeinfo.tm_min = 45;
    timeinfo.tm_sec = 56;

    clock.setDateTime(timeinfo);

    TEST_ASSERT_EQUAL(1245, clock.displayValue());
}

void test_display_shows_date_in_Date_mode(void)
{
    Clock clock;

    tm timeinfo;
    timeinfo.tm_year = 119;
    timeinfo.tm_mon = 5;
    timeinfo.tm_mday = 8;
    timeinfo.tm_hour = 12;
    timeinfo.tm_min = 45;
    timeinfo.tm_sec = 56;

    clock.setDateTime(timeinfo);
    clock.setMode(DATE);

    TEST_ASSERT_EQUAL(608, clock.displayValue());
}

void test_display_shows_year_in_Year_mode(void)
{
    Clock clock;

    tm timeinfo;
    timeinfo.tm_year = 119;
    timeinfo.tm_mon = 5;
    timeinfo.tm_mday = 8;
    timeinfo.tm_hour = 12;
    timeinfo.tm_min = 45;
    timeinfo.tm_sec = 56;

    clock.setDateTime(timeinfo);
    clock.setMode(YEAR);

    TEST_ASSERT_EQUAL(2019, clock.displayValue());
}

void test_nextMode_cycles_through_modes(void)
{
    Clock clock;

    TEST_ASSERT_EQUAL(TIME, clock.mode());

    clock.nextMode();
    TEST_ASSERT_EQUAL(TIME24, clock.mode());

    clock.nextMode();
    TEST_ASSERT_EQUAL(DATE, clock.mode());

    clock.nextMode();
    TEST_ASSERT_EQUAL(YEAR, clock.mode());

    clock.nextMode();
    TEST_ASSERT_EQUAL(TIME, clock.mode());
}

void test_displayFlags_in_time_mode_shows_CL0_and_CL1(void)
{
    Clock clock;

    tm timeinfo;
    timeinfo.tm_year = 119;
    timeinfo.tm_mon = 5;
    timeinfo.tm_mday = 8;
    timeinfo.tm_hour = 12;
    timeinfo.tm_min = 45;
    timeinfo.tm_sec = 56;

    clock.setDateTime(timeinfo);

    TEST_ASSERT_EQUAL(3, clock.displayFlags());
}

void test_displayFlags_in_time_mode_hides_CL0_and_CL1_on_odd_seconds(void)
{
    Clock clock;

    tm timeinfo;
    timeinfo.tm_year = 119;
    timeinfo.tm_mon = 5;
    timeinfo.tm_mday = 8;
    timeinfo.tm_hour = 12;
    timeinfo.tm_min = 45;
    timeinfo.tm_sec = 57;

    clock.setDateTime(timeinfo);

    TEST_ASSERT_EQUAL(0, clock.displayFlags());
}

void test_displayFlags_in_date_mode_shows_CL1(void)
{
    Clock clock;

    tm timeinfo;
    timeinfo.tm_year = 119;
    timeinfo.tm_mon = 5;
    timeinfo.tm_mday = 8;
    timeinfo.tm_hour = 12;
    timeinfo.tm_min = 45;
    timeinfo.tm_sec = 56;

    clock.setDateTime(timeinfo);
    clock.setMode(DATE);

    TEST_ASSERT_EQUAL(2, clock.displayFlags());
}

void test_displayFlags_in_date_mode_hides_CL0_and_CL1(void)
{
    Clock clock;

    tm timeinfo;
    timeinfo.tm_year = 119;
    timeinfo.tm_mon = 5;
    timeinfo.tm_mday = 8;
    timeinfo.tm_hour = 12;
    timeinfo.tm_min = 45;
    timeinfo.tm_sec = 56;

    clock.setDateTime(timeinfo);
    clock.setMode(YEAR);

    TEST_ASSERT_EQUAL(0, clock.displayFlags());
}

void RUN_UNITY_TESTS()
{
    UNITY_BEGIN();

    RUN_TEST(test_setDateTime);
    RUN_TEST(test_time_shows_1_digit_hour);
    RUN_TEST(test_time_shows_2_digit_hour);
    RUN_TEST(test_time_shows_midnight);
    RUN_TEST(test_time_shows_2_digit_hour_PM);
    RUN_TEST(test_time24_shows_1_digit_hour);
    RUN_TEST(test_time24_shows_2_digit_hour);
    RUN_TEST(test_time24_shows_midnight);
    RUN_TEST(test_time24_shows_2_digit_hour_PM);
    RUN_TEST(test_date_shows_1_digit_month);
    RUN_TEST(test_date_shows_2_digit_month);
    RUN_TEST(test_date_shows_1_digit_day);
    RUN_TEST(test_year);
    RUN_TEST(test_display_shows_time_in_Time_mode);
    RUN_TEST(test_display_shows_date_in_Date_mode);
    RUN_TEST(test_display_shows_year_in_Year_mode);
    RUN_TEST(test_nextMode_cycles_through_modes);
    RUN_TEST(test_displayFlags_in_time_mode_shows_CL0_and_CL1);
    RUN_TEST(test_displayFlags_in_time_mode_hides_CL0_and_CL1_on_odd_seconds);
    RUN_TEST(test_displayFlags_in_date_mode_shows_CL1);
    RUN_TEST(test_displayFlags_in_date_mode_hides_CL0_and_CL1);

    UNITY_END();
}

#ifdef ARDUINO

#include <Arduino.h>
void setup()
{
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);

    RUN_UNITY_TESTS();
}

void loop()
{
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(500);
}

#else

int main(int argc, char **argv)
{
    RUN_UNITY_TESTS();
    return 0;
}

#endif