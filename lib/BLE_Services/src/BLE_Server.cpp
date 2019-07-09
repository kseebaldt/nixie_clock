#include "BLE_Server.h"

#include <BLEDevice.h>
#include <BLEServer.h>

namespace BLE {

    Server::Server(Config& config) : _config(config), _configService(config) {}

    void Server::init() {
        BLEDevice::init(_config.name());
        BLEServer *pServer = BLEDevice::createServer();

        _deviceInfoService.createService(pServer);
        _currentTimeService.createService(pServer);
        _configService.createService(pServer);

        BLEAdvertising *pAdvertising = pServer->getAdvertising();

        pAdvertising->addServiceUUID(_deviceInfoService.uuid());
        pAdvertising->addServiceUUID(_currentTimeService.uuid());
        pAdvertising->addServiceUUID(_configService.uuid());
        pAdvertising->setScanResponse(true);
        pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
        pAdvertising->setMinPreferred(0x12);

        pAdvertising->start();
    }
}