#ifndef _BLE_CONFIG_SERVICE_H_
#define _BLE_CONFIG_SERVICE_H_

#include <BLEServer.h>
#include "Config.h"

namespace BLE {

    class ConfigService : public BLECharacteristicCallbacks {
        public:
            ConfigService(Config &config);

            BLEUUID uuid() const { return _uuid; }
            void createService(BLEServer *server);
            virtual void onRead(BLECharacteristic* pCharacteristic);
            virtual void onWrite(BLECharacteristic* pCharacteristic);

        private:
            Config& _config;

            const BLEUUID _uuid;
            BLECharacteristic _nameCharacteristic;
            BLECharacteristic _ssidCharacteristic;
            BLECharacteristic _passwordCharacteristic;
            BLECharacteristic _timezoneCharacteristic;
            BLECharacteristic _ledColorCharacteristic;
    };
};

#endif