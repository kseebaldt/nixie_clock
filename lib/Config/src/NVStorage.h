#ifndef _NVSTORAGE_H_
#define _NVSTORAGE_H_

#include "Storage.h"
#include <string>

class NVStorage : public Storage {
    public:
        NVStorage(std::string name);
        bool run(std::function<void (StorageFunctions& f)> func);

    private:
        struct Functions : public StorageFunctions {
            uint32_t _handle;

            Functions(uint32_t handle) : _handle(handle) {}

            virtual bool clear();
            virtual bool remove(std::string key);
        
            virtual void putUInt(std::string key, uint32_t value);
            virtual uint32_t getUInt(std::string key, uint32_t defaultValue = 0);

            virtual void putString(std::string key, std::string value);
            virtual std::string getString(std::string key, std::string defaultValue = "");
        };

        std::string _name;
};

#endif