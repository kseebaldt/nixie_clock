#include <unity.h>

namespace Test_DisplayDriver {
    void runTests(void);
}

namespace Test_Clock {
    void runTests(void);
}

namespace Test_Config {
    void runTests(void);
}

void process() {
    UNITY_BEGIN();

    Test_DisplayDriver::runTests();
    Test_Clock::runTests();
    Test_Config::runTests();

    UNITY_END();
}

#ifdef ARDUINO

#include <Arduino.h>
void setup() {
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);

    process();
}

void loop() {
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(500);
}

#else

int main(int argc, char **argv) {
    process();
    return 0;
}

#endif