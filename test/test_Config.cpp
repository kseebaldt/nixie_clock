#include <unity.h>

#include "Storage.h"
#include "Config.h"
#include "fakeit.hpp"

#include <map>

using namespace fakeit;

namespace Test_Config {

    struct FakeStorage : public Storage, StorageFunctions {
        std::map<std::string, std::string> stringData;
        std::map<std::string, uint32_t> intData;

        bool clear() {
            stringData.clear();
            intData.clear();
            return true;
        }

        bool remove(std::string key) {
            stringData.erase(key);
            intData.erase(key);
            return true;
        }

        void putUInt(std::string key, uint32_t value) {
            intData[key] = value;
        }

        uint32_t getUInt(std::string key, uint32_t defaultValue = 0) {
            if (intData.count(key) == 0) {
                return defaultValue;
            }
            return intData[key];
        }

        void putString(std::string key, std::string value) {
            stringData[key] = value;
        }

        std::string getString(std::string key, std::string defaultValue = "") {
            if (stringData.count(key) == 0) {
                return defaultValue;
            }
            return stringData[key];
        }

        bool run(std::function<void (StorageFunctions&)> func) {
            func(*this);
            return true;
        }
    };

    FakeStorage storage;

    void test_init_defaultValues() {
        Config config(storage);

        config.init();

        TEST_ASSERT_EQUAL_STRING("nixie-clock", config.name().c_str());
        TEST_ASSERT_EQUAL_STRING("", config.ssid().c_str());
        TEST_ASSERT_EQUAL_STRING("", config.password().c_str());
        TEST_ASSERT_EQUAL_STRING("CST6CDT,M3.2.0,M11.1.0", config.timeZone().c_str());
        TEST_ASSERT_EQUAL(0x00C800C8, config.ledColor());
    }

    void test_init_readsValuesFromStorage() {
        storage.putString("name", "myname");
        storage.putString("ssid", "myssid");
        storage.putString("password", "mypassword");
        storage.putString("timezone", "mytimezone");
        storage.putUInt("ledcolor", 0x00123456);

        Config config(storage);

        config.init();

        TEST_ASSERT_EQUAL_STRING("myname", config.name().c_str());
        TEST_ASSERT_EQUAL_STRING("myssid", config.ssid().c_str());
        TEST_ASSERT_EQUAL_STRING("mypassword", config.password().c_str());
        TEST_ASSERT_EQUAL_STRING("mytimezone", config.timeZone().c_str());
        TEST_ASSERT_EQUAL(0x00123456, config.ledColor());
    }

    void test_setName() {
        Config config(storage);

        config.setName("new-name");

        TEST_ASSERT_EQUAL_STRING("new-name", config.name().c_str());
        TEST_ASSERT_EQUAL_STRING("new-name", storage.getString("name").c_str());
    }

    void test_setSsid() {
        Config config(storage);

        config.setSsid("new-ssid");

        TEST_ASSERT_EQUAL_STRING("new-ssid", config.ssid().c_str());
        TEST_ASSERT_EQUAL_STRING("new-ssid", storage.getString("ssid").c_str());
    }

    void test_setPassword() {
        Config config(storage);

        config.setPassword("new-password");

        TEST_ASSERT_EQUAL_STRING("new-password", config.password().c_str());
        TEST_ASSERT_EQUAL_STRING("new-password", storage.getString("password").c_str());
    }

    void test_setTimeZone() {
        Config config(storage);

        config.setTimeZone("new-timezone");

        TEST_ASSERT_EQUAL_STRING("new-timezone", config.timeZone().c_str());
        TEST_ASSERT_EQUAL_STRING("new-timezone", storage.getString("timezone").c_str());
    }

    void test_setLedColor() {
        Config config(storage);

        config.setLedColor(0x00654321);

        TEST_ASSERT_EQUAL(0x00654321, config.ledColor());
        TEST_ASSERT_EQUAL(0x00654321, storage.getUInt("ledcolor"));
    }

    void runTests() {
        RUN_TEST(test_init_defaultValues);
        RUN_TEST(test_init_readsValuesFromStorage);
        RUN_TEST(test_setName);
        RUN_TEST(test_setSsid);
        RUN_TEST(test_setPassword);
        RUN_TEST(test_setTimeZone);
        RUN_TEST(test_setLedColor);
    }
}