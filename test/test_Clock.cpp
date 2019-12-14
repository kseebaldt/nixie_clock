#include "catch.hpp"

#define private public

#include <Clock.h>

TEST_CASE("setDateTime", "[clock]") {
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

    REQUIRE(currentTime.tm_year == 119);
    REQUIRE(currentTime.tm_mon == 5);
    REQUIRE(currentTime.tm_mday == 12);
    REQUIRE(currentTime.tm_hour == 3);
    REQUIRE(currentTime.tm_min == 45);
    REQUIRE(currentTime.tm_sec == 56);
}

 TEST_CASE("time shown 1 digit hour", "[clock]") {
    Clock clock;

    tm timeinfo;
    timeinfo.tm_hour = 3;
    timeinfo.tm_min = 45;

    clock.setDateTime(timeinfo);

    tm currentTime = clock.now();        

    REQUIRE(clock.time() == 345);
}

 TEST_CASE("time shows 2 digit hour", "[clock]") {
    Clock clock;

    tm timeinfo;
    timeinfo.tm_hour = 12;
    timeinfo.tm_min = 45;

    clock.setDateTime(timeinfo);

    REQUIRE(clock.time() == 1245);
}

 TEST_CASE("time shows midnight", "[clock]") {
    Clock clock;

    tm timeinfo;
    timeinfo.tm_hour = 0;
    timeinfo.tm_min = 45;

    clock.setDateTime(timeinfo);

    REQUIRE(clock.time() == 1245);
}

 TEST_CASE("time shows 2 digit hour PM", "[clock]") {
    Clock clock;

    tm timeinfo;
    timeinfo.tm_hour = 14;
    timeinfo.tm_min = 45;

    clock.setDateTime(timeinfo);

    REQUIRE(clock.time() == 245);
}

TEST_CASE("time24 shown 1 digit hour", "[clock]") {
    Clock clock;

    tm timeinfo;
    timeinfo.tm_hour = 3;
    timeinfo.tm_min = 45;

    clock.setDateTime(timeinfo);

    tm currentTime = clock.now();        

    REQUIRE(clock.time24() == 345);
}

 TEST_CASE("time24 shows 2 digit hour", "[clock]") {
    Clock clock;

    tm timeinfo;
    timeinfo.tm_hour = 12;
    timeinfo.tm_min = 45;

    clock.setDateTime(timeinfo);

    REQUIRE(clock.time24() == 1245);
}

 TEST_CASE("time24 shows midnight", "[clock]") {
    Clock clock;

    tm timeinfo;
    timeinfo.tm_hour = 0;
    timeinfo.tm_min = 45;

    clock.setDateTime(timeinfo);

    REQUIRE(clock.time24() == 45);
}

TEST_CASE("time24 shows 2 digit hour PM", "[clock]") {
    Clock clock;

    tm timeinfo;
    timeinfo.tm_hour = 14;
    timeinfo.tm_min = 45;

    clock.setDateTime(timeinfo);

    REQUIRE(clock.time24() == 1445);
}

TEST_CASE("date shows 1 digit month", "[clock]") {
    Clock clock;

    tm timeinfo;
    timeinfo.tm_mon = 5;
    timeinfo.tm_mday = 12;

    clock.setDateTime(timeinfo);

    REQUIRE(clock.date() == 612);
}

TEST_CASE("date shows 2 digit month", "[clock]") {
    Clock clock;

    tm timeinfo;
    timeinfo.tm_mon = 10;
    timeinfo.tm_mday = 12;

    clock.setDateTime(timeinfo);

    REQUIRE(clock.date() == 1112);
}

TEST_CASE("date shows 1 digit day", "[clock]") {
    Clock clock;

    tm timeinfo;
    timeinfo.tm_mon = 5;
    timeinfo.tm_mday = 8;

    clock.setDateTime(timeinfo);

    REQUIRE(clock.date() == 608);
}

TEST_CASE("year", "[clock]") {
    Clock clock;

    tm timeinfo;
    timeinfo.tm_year = 119;

    clock.setDateTime(timeinfo);

    REQUIRE(clock.year() == 2019);
}

TEST_CASE("display shows time in Time mode", "[clock]") {
    Clock clock;

    tm timeinfo;
    timeinfo.tm_year = 119;
    timeinfo.tm_mon = 5;
    timeinfo.tm_mday = 8;
    timeinfo.tm_hour = 12;
    timeinfo.tm_min = 45;
    timeinfo.tm_sec = 56;

    clock.setDateTime(timeinfo);

    REQUIRE(clock.displayValue() == 1245);
}

TEST_CASE("display shows date in Date mode", "[clock]") {
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

    REQUIRE(clock.displayValue() == 608);
}

TEST_CASE("display shows year in Year mode", "[clock]") {
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

    REQUIRE(clock.displayValue() == 2019);
}

TEST_CASE("nextMode cycles through modes", "[clock]") {
    Clock clock;

    REQUIRE(clock.mode() == TIME);

    clock.nextMode();
    REQUIRE(clock.mode() == TIME24);

    clock.nextMode();
    REQUIRE(clock.mode() == DATE);

    clock.nextMode();
    REQUIRE(clock.mode() == YEAR);

    clock.nextMode();
    REQUIRE(clock.mode() == TIME);
}

TEST_CASE("displayFlags in time mode shows CL0 & CL1", "[clock]") {
    Clock clock;

    tm timeinfo;
    timeinfo.tm_year = 119;
    timeinfo.tm_mon = 5;
    timeinfo.tm_mday = 8;
    timeinfo.tm_hour = 12;
    timeinfo.tm_min = 45;
    timeinfo.tm_sec = 56;

    clock.setDateTime(timeinfo);

    REQUIRE(clock.displayFlags() == 3);
}

TEST_CASE("displayFlags in time mode hides CL0 & CL1 on odd seconds", "[clock]") {
    Clock clock;

    tm timeinfo;
    timeinfo.tm_year = 119;
    timeinfo.tm_mon = 5;
    timeinfo.tm_mday = 8;
    timeinfo.tm_hour = 12;
    timeinfo.tm_min = 45;
    timeinfo.tm_sec = 57;

    clock.setDateTime(timeinfo);

    REQUIRE(clock.displayFlags() == 0);
}

TEST_CASE("displayFlags in date mode shows CL1", "[clock]") {
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

    REQUIRE(clock.displayFlags() == 2);
}

TEST_CASE("displayFlags in year mode hides CL0 & CL1", "[clock]") {
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

    REQUIRE(clock.displayFlags() == 0);
}
