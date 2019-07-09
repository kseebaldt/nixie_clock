#ifndef _BLE_SERVER_H_
#define _BLE_SERVER_H_

#include <BLEServer.h>

#include "Config.h"
#include "BLE_DeviceInfoService.h"
#include "BLE_CurrentTimeService.h"
#include "BLE_ConfigService.h"

namespace BLE {

    class Server {
        public:
            Server(Config& config);

            void init();

            DeviceInfoService& deviceInfoService() { return _deviceInfoService; }
            CurrentTimeService& currentTimeService() { return _currentTimeService; }
            ConfigService& configService() { return _configService; }

        private:
            Config& _config;

            DeviceInfoService _deviceInfoService;
            CurrentTimeService _currentTimeService;
            ConfigService _configService;
    };
};

#endif