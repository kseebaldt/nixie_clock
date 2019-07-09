#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <string>
#include "Storage.h"

class Config {
    public:
        Config(Storage& storage);

        void init();

        std::string name() const { return _name; }
        std::string ssid() const { return _ssid; }
        std::string password() const { return _password; }
        std::string timeZone() const { return _timeZone; }
        uint32_t ledColor() const { return _ledColor; }

        void setName(std::string name);
        void setSsid(std::string ssid);
        void setPassword(std::string password);
        void setTimeZone(std::string timeZone);
        void setLedColor(uint32_t color);

    private:
        std::string _name;
        std::string _ssid;
        std::string _password;
        std::string _timeZone;
        uint32_t _ledColor;

        Storage& _storage;
};

#endif /* _CONFIG_H_ */
