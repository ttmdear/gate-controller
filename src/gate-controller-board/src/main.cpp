#include <Arduino.h>
#include <Debug.h>
#include <Pins.h>
#include <RemoteController.h>
#include <GateController.h>

RemoteController* remoteController;
GateController* gateController;

Pins pio = {
    PIN_CLOSE,
    PIN_OPEN,
    PIN_STOP,
    PIN_LIMIT_CLOSE,
    PIN_LIMIT_OPEN,
    PIN_MOVING_INDICATOR,
    PIN_CONTACTOR_CONVERTER,
    PIN_CONTACTOR_CLOSE,
    PIN_CONTACTOR_OPEN,
    PIN_SENSOR_OBSTACLE_SWITCH,
    PIN_SENSOR_OBSTACLE_SIGNAL
};

void setup() {
    Debug::init();

    remoteController = new RemoteController(PIN_RF_RECEIVER, PIN_RF_RECEIVER_SIGNAL);
    gateController = new GateController(pio, remoteController);
}

void loop() {
    gateController->process();
    delay(2000);
}
