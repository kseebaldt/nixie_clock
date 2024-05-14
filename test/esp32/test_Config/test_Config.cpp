#include <unity.h>

#include "Storage.h"
#include "Config.h"

#include <map>

#define TEST_ASSERT_EQUAL_STR(expected, actual) TEST_ASSERT_EQUAL_STRING((expected), (actual.c_str()))

struct FakeStorage : public Storage, StorageFunctions
{
    std::map<std::string, std::string> stringData;
    std::map<std::string, uint32_t> intData;

    bool clear()
    {
        stringData.clear();
        intData.clear();
        return true;
    }

    bool remove(std::string key)
    {
        stringData.erase(key);
        intData.erase(key);
        return true;
    }

    void putUInt(std::string key, uint32_t value)
    {
        intData[key] = value;
    }

    uint32_t getUInt(std::string key, uint32_t defaultValue = 0)
    {
        if (intData.count(key) == 0)
        {
            return defaultValue;
        }
        return intData[key];
    }

    void putString(std::string key, std::string value)
    {
        stringData[key] = value;
    }

    std::string getString(std::string key, std::string defaultValue = "")
    {
        if (stringData.count(key) == 0)
        {
            return defaultValue;
        }
        return stringData[key];
    }

    bool run(std::function<void(StorageFunctions &)> func)
    {
        func(*this);
        return true;
    }
};

void setUp(void)
{
}

void tearDown(void)
{
}

void test_init_uses_default_values(void)
{
    FakeStorage storage;
    Config config(storage);

    config.init();

    TEST_ASSERT_EQUAL_STR("nixie-clock", config.name());
    TEST_ASSERT_EQUAL_STR("", config.ssid());
    TEST_ASSERT_EQUAL_STR("", config.password());
    TEST_ASSERT_EQUAL_STR("CST6CDT,M3.2.0,M11.1.0", config.timeZone());
    TEST_ASSERT_EQUAL(0x00C800C8, config.ledColor());
}

void test_init_reads_values_from_storage(void)
{
    FakeStorage storage;
    storage.putString("name", "myname");
    storage.putString("ssid", "myssid");
    storage.putString("password", "mypassword");
    storage.putString("timezone", "mytimezone");
    storage.putUInt("ledcolor", 0x00123456);

    Config config(storage);

    config.init();

    TEST_ASSERT_EQUAL_STR("myname", config.name());
    TEST_ASSERT_EQUAL_STR("myssid", config.ssid());
    TEST_ASSERT_EQUAL_STR("mypassword", config.password());
    TEST_ASSERT_EQUAL_STR("mytimezone", config.timeZone());
    TEST_ASSERT_EQUAL(0x00123456, config.ledColor());
}

void test_setName(void)
{
    FakeStorage storage;
    Config config(storage);

    bool called = false;
    config.notifyOnChange([&called](Config &config, Config::Types type)
                          {
        called = true;
        TEST_ASSERT_EQUAL(Config::Types::NAME, type); });

    config.setName("new-name");

    TEST_ASSERT_EQUAL_STR("new-name", config.name());
    TEST_ASSERT_EQUAL_STR("new-name", storage.getString("name"));
    TEST_ASSERT_TRUE(called);
}

void test_setSsid(void)
{
    FakeStorage storage;
    Config config(storage);

    bool called = false;
    config.notifyOnChange([&called](Config &config, Config::Types type)
                          {
        called = true;
        TEST_ASSERT_EQUAL(Config::Types::SSID, type); });

    config.setSsid("new-ssid");

    TEST_ASSERT_EQUAL_STR("new-ssid", config.ssid());
    TEST_ASSERT_EQUAL_STR("new-ssid", storage.getString("ssid"));
    TEST_ASSERT_TRUE(called);
}

void test_setPassword(void)
{
    FakeStorage storage;
    Config config(storage);

    bool called = false;
    config.notifyOnChange([&called](Config &config, Config::Types type)
                          {
        called = true;
        TEST_ASSERT_EQUAL(Config::Types::PASSWORD, type); });

    config.setPassword("new-password");

    TEST_ASSERT_EQUAL_STR("new-password", config.password());
    TEST_ASSERT_EQUAL_STR("new-password", storage.getString("password"));
    TEST_ASSERT_TRUE(called);
}

void test_setTimeZone(void)
{
    FakeStorage storage;
    Config config(storage);

    bool called = false;
    config.notifyOnChange([&called](Config &config, Config::Types type)
                          {
        called = true;
        TEST_ASSERT_EQUAL(Config::Types::TIME_ZONE, type); });

    config.setTimeZone("new-timezone");

    TEST_ASSERT_EQUAL_STR("new-timezone", config.timeZone());
    TEST_ASSERT_EQUAL_STR("new-timezone", storage.getString("timezone"));
    TEST_ASSERT_TRUE(called);
}

void test_setLedColor(void)
{
    FakeStorage storage;
    Config config(storage);

    bool called = false;
    config.notifyOnChange([&called](Config &config, Config::Types type)
                          {
        called = true;
        TEST_ASSERT_EQUAL(Config::Types::LED_COLOR, type); });

    config.setLedColor(0x00654321);

    TEST_ASSERT_EQUAL(0x00654321, config.ledColor());
    TEST_ASSERT_EQUAL(0x00654321, storage.getUInt("ledcolor"));
    TEST_ASSERT_TRUE(called);
}

void RUN_UNITY_TESTS()
{
    UNITY_BEGIN();

    RUN_TEST(test_init_uses_default_values);
    RUN_TEST(test_init_reads_values_from_storage);
    RUN_TEST(test_setName);
    RUN_TEST(test_setSsid);
    RUN_TEST(test_setPassword);
    RUN_TEST(test_setTimeZone);
    RUN_TEST(test_setLedColor);

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