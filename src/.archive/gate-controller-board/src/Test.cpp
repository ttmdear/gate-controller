#include "Test.h"

#include <Pins.h>
#include <Arduino.h>
#include <Debug.h>

void Test::testInput() {
    Debug::printMessage("TEST INPUT");
    Debug::printMessage("-----------------------");

    pinMode(PIN_CLOSE, INPUT);
    pinMode(PIN_OPEN, INPUT);
    pinMode(PIN_STOP, INPUT);
    pinMode(PIN_LIMIT_CLOSE, INPUT);
    pinMode(PIN_LIMIT_OPEN, INPUT);
    pinMode(PIN_SENSOR_OBSTACLE_SIGNAL, INPUT);
    pinMode(PIN_RF_RECEIVER_SIGNAL, INPUT);

    int counter = 10;

    while(true) {
        if (digitalRead(PIN_CLOSE)) {
            Debug::printVar("PIN_CLOSE", 1);
        }

        if (digitalRead(PIN_OPEN)) {
            Debug::printVar("PIN_OPEN", 1);
        }

        if (digitalRead(PIN_STOP)) {
            Debug::printVar("PIN_STOP", 1);
        }

        if (digitalRead(PIN_LIMIT_CLOSE)) {
            Debug::printVar("PIN_LIMIT_CLOSE", 1);
        }

        if (digitalRead(PIN_LIMIT_OPEN)) {
            Debug::printVar("PIN_LIMIT_OPEN", 1);
        }

        delay(3000);

        Debug::printVar("PIN_SENSOR_OBSTACLE_SIGNAL", analogRead(PIN_SENSOR_OBSTACLE_SIGNAL));

        if (--counter == 0) {
            break;
        }
    }

    // Debug::printMessage("PIN_RF_RECEIVER TO UP");
    // digitalWrite(PIN_RF_RECEIVER, HIGH);
    // delay(5000);
    // digitalWrite(PIN_RF_RECEIVER, LOW);
}

void Test::testOutput() {
    Debug::printMessage("TEST OUTPUT");
    Debug::printMessage("-----------------------");

    pinMode(PIN_SENSOR_OBSTACLE_SWITCH, OUTPUT);
    pinMode(PIN_MOVING_INDICATOR, OUTPUT);
    pinMode(PIN_CONTACTOR_CONVERTER, OUTPUT);
    pinMode(PIN_CONTACTOR_CLOSE, OUTPUT);
    pinMode(PIN_CONTACTOR_OPEN, OUTPUT);
    pinMode(PIN_RF_RECEIVER, OUTPUT);

    Debug::printMessage("PIN_MOVING_INDICATOR TO UP");
    digitalWrite(PIN_MOVING_INDICATOR, HIGH);
    delay(5000);
    digitalWrite(PIN_MOVING_INDICATOR, LOW);

    Debug::printMessage("PIN_CONTACTOR_CONVERTER TO UP");
    digitalWrite(PIN_CONTACTOR_CONVERTER, HIGH);
    delay(5000);
    digitalWrite(PIN_CONTACTOR_CONVERTER, LOW);

    Debug::printMessage("PIN_CONTACTOR_CLOSE TO UP");
    digitalWrite(PIN_CONTACTOR_CLOSE, HIGH);
    delay(5000);
    digitalWrite(PIN_CONTACTOR_CLOSE, LOW);

    Debug::printMessage("PIN_CONTACTOR_OPEN TO UP");
    digitalWrite(PIN_CONTACTOR_OPEN, HIGH);
    delay(5000);
    Debug::printMessage("PIN_CONTACTOR_OPEN TO DOWN");
    digitalWrite(PIN_CONTACTOR_OPEN, LOW);

    Debug::printMessage("PIN_SENSOR_OBSTACLE_SWITCH TO UP");
    digitalWrite(PIN_SENSOR_OBSTACLE_SWITCH, HIGH);
    delay(5000);
    digitalWrite(PIN_SENSOR_OBSTACLE_SWITCH, LOW);

    Debug::printMessage("PIN_RF_RECEIVER_SIGNAL TO UP");
    digitalWrite(PIN_RF_RECEIVER_SIGNAL, HIGH);
    delay(5000);
    digitalWrite(PIN_RF_RECEIVER_SIGNAL, LOW);
}

void Test::run() {
    testInput();
    testOutput();
}
