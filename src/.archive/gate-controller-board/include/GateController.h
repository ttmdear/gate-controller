#ifndef GATE_CONTROLLER_BOARD_GATECONTROLLER_H
#define GATE_CONTROLLER_BOARD_GATECONTROLLER_H

#include "Pins.h"
#include "RemoteController.h"

class GateController {
private:
    Pins pio;
    RemoteController *rc;

    uint8_t state = STATE_INDEFINITE;

    void processClosedState();

    void processClosingState();

    void processIndefiniteState();

    void processOpeningState();

    void processOpennedState();

    void processStoppedState();

    bool isHigh(const uint8_t &pin);

    bool isMoving();

    bool isStopped();

    void setOnSensorObstacle();

    void setOffSensorObstacle();

    bool isObstacle();

    void setContactors(const bool &open, const bool &close);

    String resolveState(const uint8_t &state);

    void setOnMovingIndicator();

    void setOffMovingIndicator();
public:
    static const uint8_t STATE_INDEFINITE = 0;
    static const uint8_t STATE_OPENNED = 1;
    static const uint8_t STATE_OPENING = 2;
    static const uint8_t STATE_CLOSED = 3;
    static const uint8_t STATE_CLOSING = 4;
    static const uint8_t STATE_STOPPED = 5;

    GateController(Pins pio, RemoteController *rc);

    void process();
};

#endif
