#include "BLE_DeviceInfoService.h"
#include <stdint.h>

namespace BLE {

    DeviceInfoService::DeviceInfoService() : 
        _uuid((uint16_t)0x180A),
        _manufacturerNameCharacteristic(BLEUUID((uint16_t)0x2A29), BLECharacteristic::PROPERTY_READ),
        _modelNameCharacteristic(BLEUUID((uint16_t)0x2A24), BLECharacteristic::PROPERTY_READ) {

        _manufacturerNameCharacteristic.setValue("Kurtis Seebaldt");
        _modelNameCharacteristic.setValue("Nixie Clock IN-12");
    }

    void DeviceInfoService::createService(BLEServer *server) {
        BLEService *service = server->createService(_uuid);
        service->addCharacteristic(&_manufacturerNameCharacteristic);
        service->addCharacteristic(&_modelNameCharacteristic);
        service->start();
    }
}