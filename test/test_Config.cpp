#include "catch.hpp"

#include "Storage.h"
#include "Config.h"

#include <map>

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

TEST_CASE("init uses default values", "[config]") {
    FakeStorage storage;
    Config config(storage);

    config.init();

    CHECK(config.name() == "nixie-clock");
    CHECK(config.ssid() == "");
    CHECK(config.password() == "");
    CHECK(config.timeZone() == "CST6CDT,M3.2.0,M11.1.0");
    CHECK(config.ledColor() == 0x00C800C8);
}

TEST_CASE("init reads values from storage", "[config]") {
    FakeStorage storage;
    storage.putString("name", "myname");
    storage.putString("ssid", "myssid");
    storage.putString("password", "mypassword");
    storage.putString("timezone", "mytimezone");
    storage.putUInt("ledcolor", 0x00123456);

    Config config(storage);

    config.init();

    CHECK(config.name() == "myname");
    CHECK(config.ssid() == "myssid");
    CHECK(config.password() == "mypassword");
    CHECK(config.timeZone() == "mytimezone");
    CHECK(config.ledColor() == 0x00123456);
}

TEST_CASE("setName", "[config]") {
    FakeStorage storage;
    Config config(storage);

    bool called = false;
    config.notifyOnChange([&called] (Config& config, Config::Types type) {
        called = true;
        CHECK(type == Config::Types::NAME);
    });

    config.setName("new-name");

    CHECK(config.name() == "new-name");
    CHECK(storage.getString("name") == "new-name");
    CHECK(called);
}

TEST_CASE("setSsid", "[config]") {
    FakeStorage storage;
    Config config(storage);

    bool called = false;
    config.notifyOnChange([&called] (Config& config, Config::Types type) {
        called = true;
        CHECK(type == Config::Types::SSID);
    });

    config.setSsid("new-ssid");

    CHECK(config.ssid() == "new-ssid");
    CHECK(storage.getString("ssid") == "new-ssid");
    CHECK(called);
}

TEST_CASE("setPassword", "[config]") {
    FakeStorage storage;
    Config config(storage);

    bool called = false;
    config.notifyOnChange([&called] (Config& config, Config::Types type) {
        called = true;
        CHECK(type == Config::Types::PASSWORD);
    });        

    config.setPassword("new-password");

    CHECK(config.password() == "new-password");
    CHECK(storage.getString("password") == "new-password");
    CHECK(called);
}

TEST_CASE("setTimeZone", "[config]") {
    FakeStorage storage;
    Config config(storage);

    bool called = false;
    config.notifyOnChange([&called] (Config& config, Config::Types type) {
        called = true;
        CHECK(type == Config::Types::TIME_ZONE);
    });

    config.setTimeZone("new-timezone");

    CHECK(config.timeZone() == "new-timezone");
    CHECK(storage.getString("timezone") == "new-timezone");
    CHECK(called);
}

TEST_CASE("setLedColor", "[config]") {
    FakeStorage storage;
    Config config(storage);

    bool called = false;
    config.notifyOnChange([&called] (Config& config, Config::Types type) {
        called = true;
        CHECK(type == Config::Types::LED_COLOR);
    });

    config.setLedColor(0x00654321);

    CHECK(config.ledColor() == 0x00654321);
    CHECK(storage.getUInt("ledcolor") == 0x00654321);
    CHECK(called);
}
