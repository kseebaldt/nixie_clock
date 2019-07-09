#include "NVStorage.h"

#ifdef ESP32

#include <Arduino.h>
#include "nvs.h"

const char * nvs_errors[] = { "OTHER", "NOT_INITIALIZED", "NOT_FOUND", "TYPE_MISMATCH", "READ_ONLY", "NOT_ENOUGH_SPACE", "INVALID_NAME", "INVALID_HANDLE", "REMOVE_FAILED", "KEY_TOO_LONG", "PAGE_FULL", "INVALID_STATE", "INVALID_LENGHT"};
#define nvs_error(e) (((e)>ESP_ERR_NVS_BASE)?nvs_errors[(e)&~(ESP_ERR_NVS_BASE)]:nvs_errors[0])

NVStorage::NVStorage(std::string name) : _name(name) {}

bool NVStorage::run(std::function<void (StorageFunctions& f)> func)
{
    uint32_t handle;

    esp_err_t err = nvs_open(_name.c_str(), NVS_READWRITE, &handle);
    if(err) {
        log_e("nvs_open failed: %s", nvs_error(err));
        return false;
    }

    Functions f(handle);
    func(f);

    nvs_close(handle);
    return true;
}

/*
 * Clear all keys in opened preferences
 * */

bool NVStorage::Functions::clear() {
    esp_err_t err = nvs_erase_all(_handle);
    if(err) {
        log_e("nvs_erase_all fail: %s", nvs_error(err));
        return false;
    }
    return true;
}

bool NVStorage::Functions::remove(std::string key) {
    esp_err_t err = nvs_erase_key(_handle, key.c_str());
    if(err){
        log_e("nvs_erase_key fail: %s %s", key.c_str(), nvs_error(err));
        return false;
    }
    return true;
}

void NVStorage::Functions::putUInt(std::string key, uint32_t value) {
    esp_err_t err = nvs_set_u32(_handle, key.c_str(), value);

    if(err) {
        log_e("nvs_set_u32 fail: %s %s", key.c_str(), nvs_error(err));
        return;
    }
    err = nvs_commit(_handle);
    if(err) {
        log_e("nvs_commit fail: %s %s", key.c_str(), nvs_error(err));
    }
    return;
}

uint32_t NVStorage::Functions::getUInt(std::string key, const uint32_t defaultValue) {
    uint32_t value = defaultValue;

    esp_err_t err = nvs_get_u32(_handle, key.c_str(), &value);
    if(err) {
        log_v("nvs_get_u32 fail: %s %s", key.c_str(), nvs_error(err));
    }
    return value;
}

void NVStorage::Functions::putString(std::string key, std::string value){
    esp_err_t err = nvs_set_str(_handle, key.c_str(), value.c_str());
    if(err){
        log_e("nvs_set_str fail: %s %s", key.c_str(), nvs_error(err));
        return;
    }
    err = nvs_commit(_handle);
    if(err){
        log_e("nvs_commit fail: %s %s", key.c_str(), nvs_error(err));
    }
}

std::string NVStorage::Functions::getString(std::string key, const std::string defaultValue) {
    char * value = NULL;
    size_t len = 0;

    esp_err_t err = nvs_get_str(_handle, key.c_str(), value, &len);
    if(err){
        log_e("nvs_get_str len fail: %s %s", key.c_str(), nvs_error(err));
        return defaultValue;
    }

    char buf[len];
    value = buf;
    err = nvs_get_str(_handle, key.c_str(), value, &len);
    if(err) {
        log_e("nvs_get_str fail: %s %s", key.c_str(), nvs_error(err));
        return defaultValue;
    }
    return std::string(buf);
}

#endif