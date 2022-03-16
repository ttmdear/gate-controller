#ifndef GATE_CONTROLLER_BOARD_PINS_H
#define GATE_CONTROLLER_BOARD_PINS_H

#include <Arduino.h>

#define PIN_CLOSE 2
#define PIN_OPEN 3
#define PIN_STOP 4
#define PIN_LIMIT_CLOSE 5
#define PIN_LIMIT_OPEN 6
#define PIN_MOVING_INDICATOR 7

#define PIN_CONTACTOR_CONVERTER 8
#define PIN_CONTACTOR_CLOSE 9
#define PIN_CONTACTOR_OPEN A0

#define PIN_SENSOR_OBSTACLE_SWITCH 12
#define PIN_SENSOR_OBSTACLE_SIGNAL A2

#define PIN_RF_RECEIVER 11
#define PIN_RF_RECEIVER_SIGNAL A1

struct Pins {
    uint8_t close;
    uint8_t open;
    uint8_t stop;
    uint8_t limitClose;
    uint8_t limitOpen;
    uint8_t movingIndicator;
    uint8_t contactorConverter;
    uint8_t contactorClose;
    uint8_t contactorOpen;
    uint8_t sensorObstacleSwitch;
    uint8_t sensorObstacleSignal;
};
#endif
