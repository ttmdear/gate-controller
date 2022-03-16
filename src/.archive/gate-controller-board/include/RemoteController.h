#ifndef GATE_CONTROLLER_BOARD_REMOTECONTROLLER_H
#define GATE_CONTROLLER_BOARD_REMOTECONTROLLER_H

#include <Arduino.h>
#include <VirtualWire.h>

class RemoteController {
private:
    uint8_t data[VW_MAX_MESSAGE_LEN];
    uint8_t dataLength = VW_MAX_MESSAGE_LEN;

    uint8_t pin;
    uint8_t signalPin;

    char command[VW_MAX_MESSAGE_LEN];
public:
    RemoteController(const uint8_t &pin, const uint8_t &signalPin);

    void process();

    bool isOpenCommand();

    bool isCloseCommand();

    bool isStopCommand();

    void clearCommand();
};

#endif
