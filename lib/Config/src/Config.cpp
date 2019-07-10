#include "Config.h"
#include <functional>

Config::Config(Storage& storage) : _storage(storage) {}

void Config::init() {
    _storage.run([this] (StorageFunctions& f) {
        _name = f.getString("name", "nixie-clock");
        _ssid = f.getString("ssid");
        _password = f.getString("password");
        _timeZone = f.getString("timezone", "CST6CDT,M3.2.0,M11.1.0");
        _ledColor = f.getUInt("ledcolor", 0x00C800C8);
    });
}

void Config::setName(std::string name) {
    _name = name;

    _storage.run([name] (StorageFunctions& f) {
        f.putString("name", name);
    });

    if (_callback) {
        _callback(*this, Types::NAME);
    }
}

void Config::setSsid(std::string ssid) {
    _ssid = ssid;

    _storage.run([ssid] (StorageFunctions& f) {
        f.putString("ssid", ssid);
    });

    if (_callback) {
        _callback(*this, Types::SSID);
    }
}

void Config::setPassword(std::string password) {
    _password = password;

    _storage.run([password] (StorageFunctions& f) {
        f.putString("password", password);
    });

    if (_callback) {
        _callback(*this, Types::PASSWORD);
    }
}

void Config::setTimeZone(std::string timeZone) {
    _timeZone = timeZone;

    _storage.run([timeZone] (StorageFunctions& f) {
        f.putString("timezone", timeZone);
    });

    if (_callback) {
        _callback(*this, Types::TIME_ZONE);
    }    
}

void Config::setLedColor(uint32_t color) {
    _ledColor = color;

    _storage.run([color] (StorageFunctions& f) {
        f.putUInt("ledcolor", color);
    });

    if (_callback) {
        _callback(*this, Types::LED_COLOR);
    }
}

void Config::notifyOnChange(std::function<void (Config& config, Types type)> func) {
    _callback = func;
}
