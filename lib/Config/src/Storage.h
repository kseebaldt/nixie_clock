#ifndef _STORAGE_H_
#define _STORAGE_H_

#include <string>
#include <functional>

struct StorageFunctions {
    virtual bool clear() = 0;
    virtual bool remove(std::string key) = 0;

    virtual void putUInt(std::string key, uint32_t value) = 0;
    virtual uint32_t getUInt(std::string key, uint32_t defaultValue = 0) = 0;

    virtual void putString(std::string key, std::string value) = 0;
    virtual std::string getString(std::string key, std::string defaultValue = "") = 0;
};

struct Storage {
    virtual bool run(std::function<void (StorageFunctions& f)> func) = 0;
};

#endif