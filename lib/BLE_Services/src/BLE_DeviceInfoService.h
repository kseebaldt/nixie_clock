#ifndef _BLE_DEVICE_INFO_SERVICE_H_
#define _BLE_DEVICE_INFO_SERVICE_H_

#include <BLEServer.h>

namespace BLE {

    class DeviceInfoService {
        public:
            DeviceInfoService();

            BLEUUID uuid() const { return _uuid; }
            void createService(BLEServer *server);

        private:
            const BLEUUID _uuid;
            BLECharacteristic _manufacturerNameCharacteristic;
            BLECharacteristic _modelNameCharacteristic;
    };
};

#endif