#ifndef _BLE_CURRENT_TIME_SERVICE_H_
#define _BLE_CURRENT_TIME_SERVICE_H_

#include <BLEServer.h>

namespace BLE {
    class CurrentTimeCallbacks : public BLECharacteristicCallbacks {
    public:
        virtual ~CurrentTimeCallbacks();
        virtual void onRead(BLECharacteristic* pCharacteristic);
        virtual void onWrite(BLECharacteristic* pCharacteristic);
    };

    class CurrentTimeService {
        public:
            CurrentTimeService();

            BLEUUID uuid() const { return _uuid; }
            void createService(BLEServer *server);
            void update(tm timeinfo);

        private:
            const BLEUUID _uuid;
            BLECharacteristic _currentTimeCharacteristic;
            BLECharacteristic _localTimeInfoCharacteristic;
            CurrentTimeCallbacks _callbacks;
    };
};

#endif