#define private public

#include <Clock.h>
#include <unity.h>

#include <stdio.h>

namespace Test_Clock {

    void test_setDateTime(void) {
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

    void test_time_1digithour(void) {
        Clock clock;

        tm timeinfo;
        timeinfo.tm_hour = 3;
        timeinfo.tm_min = 45;

        clock.setDateTime(timeinfo);

        tm currentTime = clock.now();        

        TEST_ASSERT_EQUAL(345, clock.time());
    }

    void test_time_2digithour(void) {
        Clock clock;

        tm timeinfo;
        timeinfo.tm_hour = 12;
        timeinfo.tm_min = 45;

        clock.setDateTime(timeinfo);

        TEST_ASSERT_EQUAL(1245, clock.time());
    }

    void test_date_1digitmonth(void) {
        Clock clock;

        tm timeinfo;
        timeinfo.tm_mon = 5;
        timeinfo.tm_mday = 12;

        clock.setDateTime(timeinfo);

        TEST_ASSERT_EQUAL(612, clock.date());
    }

    void test_date_2digitmonth(void) {
        Clock clock;

        tm timeinfo;
        timeinfo.tm_mon = 10;
        timeinfo.tm_mday = 12;

        clock.setDateTime(timeinfo);

        TEST_ASSERT_EQUAL(1112, clock.date());
    }

    void test_date_1digitday(void) {
        Clock clock;

        tm timeinfo;
        timeinfo.tm_mon = 5;
        timeinfo.tm_mday = 8;

        clock.setDateTime(timeinfo);

        TEST_ASSERT_EQUAL(608, clock.date());
    }

    void test_year(void) {
        Clock clock;

        tm timeinfo;
        timeinfo.tm_year = 119;

        clock.setDateTime(timeinfo);

        TEST_ASSERT_EQUAL(2019, clock.year());
    }

    void test_display_TimeMode(void) {
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

    void test_display_DateMode(void) {
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

    void test_display_YearMode(void) {
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

    void test_nextMode(void) {
        Clock clock;

        TEST_ASSERT_EQUAL(TIME, clock.mode());

        clock.nextMode();
        TEST_ASSERT_EQUAL(DATE, clock.mode());

        clock.nextMode();
        TEST_ASSERT_EQUAL(YEAR, clock.mode());

        clock.nextMode();
        TEST_ASSERT_EQUAL(TIME, clock.mode());
    }

    void test_displayFlags_time_shows_CL0_CL1(void) {
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

    void test_displayFlags_time_showsNoneOnOddSeconds(void) {
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

    void test_displayFlags_date_shows_CL1(void) {
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

    void test_displayFlags_year_showsNone(void) {
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

    void runTests() {
        RUN_TEST(test_setDateTime);
        RUN_TEST(test_time_1digithour);
        RUN_TEST(test_time_2digithour);
        RUN_TEST(test_date_1digitmonth);
        RUN_TEST(test_date_2digitmonth);
        RUN_TEST(test_date_1digitday);
        RUN_TEST(test_year);
        RUN_TEST(test_display_TimeMode);
        RUN_TEST(test_display_DateMode);
        RUN_TEST(test_display_YearMode);

        RUN_TEST(test_nextMode);
        RUN_TEST(test_displayFlags_time_shows_CL0_CL1);
        RUN_TEST(test_displayFlags_time_showsNoneOnOddSeconds);
        RUN_TEST(test_displayFlags_date_shows_CL1);
        RUN_TEST(test_displayFlags_year_showsNone);
    }
}
