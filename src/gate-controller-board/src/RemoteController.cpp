#include <Debug.h>
#include "RemoteController.h"

RemoteController::RemoteController(const uint8_t &pin, const uint8_t &signalPin) : pin(pin), signalPin(signalPin) {
    pinMode(pin, INPUT);
    pinMode(pin, OUTPUT);

    vw_set_ptt_inverted(true);
    vw_set_rx_pin(pin);
    vw_setup(2000);

    vw_rx_start();
}

void RemoteController::process() {
    dataLength = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(data, &dataLength)) {
        memset(command, 0, sizeof(command));

        for (int i = 0; i < dataLength; i++) {
            command[i] = data[i];
        }

        Debug::printVar("command", command);
    }
}

bool RemoteController::isOpenCommand() {
    return strcmp(command, "open") == 0;
}

bool RemoteController::isCloseCommand() {
    return strcmp(command, "close") == 0;
}

bool RemoteController::isStopCommand() {
    return strcmp(command, "stop") == 0;
}

void RemoteController::clearCommand() {
    memset(command, 0, sizeof(command));
}
