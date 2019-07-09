#include "BLE_ConfigService.h"

#include <Arduino.h>

namespace BLE {

    ConfigService::ConfigService(Config& config) : 
        _config(config),
        _uuid("8034861f-ea73-4fe9-890a-a4e59f10bae2"),
        _nameCharacteristic(BLEUUID("2727b1ce-03a9-49a6-ba88-34932abfc60a"), BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE),
        _ssidCharacteristic(BLEUUID("dd605bf1-4709-4fa6-809c-923a33173a1d"), BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE),
        _passwordCharacteristic(BLEUUID("7a4c74d6-beab-43c7-8b0d-3d5c658505c2"), BLECharacteristic::PROPERTY_WRITE),
        _timezoneCharacteristic(BLEUUID("4149e6e9-a083-4bfc-b562-5ac1bb5c30b6"), BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE),
        _ledColorCharacteristic(BLEUUID("eee14c3c-e774-40c8-9885-16b09c8fde0c"), BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE) {

    }

    void ConfigService::createService(BLEServer *server) {
        BLEService *service = server->createService(_uuid);

        _nameCharacteristic.setValue(_config.name());
        _ssidCharacteristic.setValue(_config.ssid());
        _passwordCharacteristic.setValue(_config.password());
        _timezoneCharacteristic.setValue(_config.timeZone());
        uint32_t c = _config.ledColor();
        _ledColorCharacteristic.setValue(c);

        _nameCharacteristic.setCallbacks(this);
        _ssidCharacteristic.setCallbacks(this);
        _passwordCharacteristic.setCallbacks(this);
        _timezoneCharacteristic.setCallbacks(this);
        _ledColorCharacteristic.setCallbacks(this);

        service->addCharacteristic(&_nameCharacteristic);
        service->addCharacteristic(&_ssidCharacteristic);
        service->addCharacteristic(&_passwordCharacteristic);
        service->addCharacteristic(&_timezoneCharacteristic);
        service->addCharacteristic(&_ledColorCharacteristic);
        service->start();
    }

    void ConfigService::onRead(BLECharacteristic* pCharacteristic) {

        if (pCharacteristic->getUUID().equals(_nameCharacteristic.getUUID())) {
            Serial.println("Reading name");
            pCharacteristic->setValue(_config.name());

        } else if (pCharacteristic->getUUID().equals(_ssidCharacteristic.getUUID())) {
            Serial.println("Reading ssid");
            pCharacteristic->setValue(_config.ssid());

        } else if (pCharacteristic->getUUID().equals(_passwordCharacteristic.getUUID())) {
            Serial.println("Reading password");
            pCharacteristic->setValue(_config.password());

        } else if (pCharacteristic->getUUID().equals(_timezoneCharacteristic.getUUID())) {
            Serial.println("Reading timezone");
            pCharacteristic->setValue(_config.timeZone());
        } else if (pCharacteristic->getUUID().equals(_ledColorCharacteristic.getUUID())) {
            Serial.println("Reading ledcolor");
            uint32_t c = _config.ledColor();
            pCharacteristic->setValue(c);
        }
        
    }

    void ConfigService::onWrite(BLECharacteristic* pCharacteristic) {
        if (pCharacteristic->getUUID().equals(_nameCharacteristic.getUUID())) {
            Serial.println("Writing name");
            _config.setName(pCharacteristic->getValue());

        } else if (pCharacteristic->getUUID().equals(_ssidCharacteristic.getUUID())) {
            Serial.println("Writing ssid");
            _config.setSsid(pCharacteristic->getValue());

        } else if (pCharacteristic->getUUID().equals(_passwordCharacteristic.getUUID())) {
            Serial.println("Writing password");
            _config.setPassword(pCharacteristic->getValue());

        } else if (pCharacteristic->getUUID().equals(_timezoneCharacteristic.getUUID())) {
            Serial.println("Writing timezone");
            _config.setTimeZone(pCharacteristic->getValue());
        } else if (pCharacteristic->getUUID().equals(_ledColorCharacteristic.getUUID())) {
            Serial.println("Writing ledcolor");

            uint32_t val;
            memcpy(&val, pCharacteristic->getData(), sizeof(val));
            _config.setLedColor(val);
        }
    }    
}
