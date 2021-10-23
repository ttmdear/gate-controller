#include "GateController.h"
#include <Pins.h>
#include <Arduino.h>
#include <Debug.h>

GateController::GateController(Pins pio, RemoteController *rc) : pio(pio), rc(rc) {
    pinMode(PIN_CLOSE, INPUT);
    pinMode(PIN_OPEN, INPUT);
    pinMode(PIN_STOP, INPUT);
    pinMode(PIN_LIMIT_CLOSE, INPUT);
    pinMode(PIN_LIMIT_OPEN, INPUT);
    pinMode(PIN_MOVING_INDICATOR, OUTPUT);
    pinMode(PIN_CONTACTOR_CONVERTER, OUTPUT);
    pinMode(PIN_CONTACTOR_CLOSE, OUTPUT);
    pinMode(PIN_CONTACTOR_OPEN, OUTPUT);
    pinMode(PIN_SENSOR_OBSTACLE_SWITCH, OUTPUT);
    pinMode(PIN_SENSOR_OBSTACLE_SIGNAL, INPUT);
}

String GateController::resolveState(const uint8_t &state) {
    switch (state) {
        case STATE_OPENNED:
            return "openned";
        case STATE_OPENING:
            return "opening";
        case STATE_CLOSED:
            return "closed";
        case STATE_CLOSING:
            return "closing";
        case STATE_STOPPED:
            return "stopped";
        default:
            return "indefinite";
    }
}

void GateController::setOnMovingIndicator() {
    digitalWrite(pio.movingIndicator, HIGH);
}

void GateController::setOffMovingIndicator() {
    digitalWrite(pio.movingIndicator, LOW);
}

bool GateController::isObstacle() {
    return !isHigh(pio.sensorObstacleSignal);
}

void GateController::setOnSensorObstacle() {
    digitalWrite(pio.sensorObstacleSwitch, HIGH);
}

void GateController::setOffSensorObstacle() {
    digitalWrite(pio.sensorObstacleSwitch, LOW);
}

bool GateController::isHigh(const uint8_t &pin) {
    return digitalRead(pin) == HIGH;
}

bool GateController::isStopped() {
    return state != STATE_STOPPED;
}

bool GateController::isMoving() {
    return state == STATE_OPENING || state == STATE_CLOSING;
}

void GateController::setContactors(const bool &open, const bool &close) {
    if (open || close) {
        digitalWrite(pio.contactorConverter, HIGH);
    } else {
        digitalWrite(pio.contactorConverter, LOW);
    }

    if (open) {
        digitalWrite(pio.contactorOpen, HIGH);
    } else {
        digitalWrite(pio.contactorOpen, LOW);
    }

    if (close) {
        digitalWrite(pio.contactorClose, HIGH);
    } else {
        digitalWrite(pio.contactorClose, LOW);
    }
}

void GateController::process() {

    // if (digitalRead(pio.close)) {
    //     Serial.print("close ");Serial.println(digitalRead(pio.close));
    // }

    // if (digitalRead(pio.open)) {
    //     Serial.print("open ");Serial.println(digitalRead(pio.open));
    // }

    // if (digitalRead(pio.stop)) {
    //     Serial.print("stop ");Serial.println(digitalRead(pio.stop));
    // }

    // if (digitalRead(pio.limitClose)) {
    //     Serial.print("limitClose ");Serial.println(digitalRead(pio.limitClose));
    // }

    // if (digitalRead(pio.limitOpen)) {
    //     Serial.print("limitOpen ");Serial.println(digitalRead(pio.limitOpen));
    // }

    // if (digitalRead(pio.movingIndicator)) {
    //     Serial.print("movingIndicator ");Serial.println(digitalRead(pio.movingIndicator));
    // }

    // if (digitalRead(pio.sensorObstacleSwitch)) {
    //     Serial.print("sensorObstacleSwitch ");Serial.println(digitalRead(pio.sensorObstacleSwitch));
    // }

    // if (digitalRead(pio.movingIndicator)) {
    //     Serial.print("sensorObstacleSignal ");Serial.println(digitalRead(pio.sensorObstacleSignal));
    // }


    rc->process();

    if (isHigh(pio.limitOpen)) {
        Serial.println("1");
        state = STATE_OPENNED;
    } else if (isHigh(pio.limitClose)) {
        Serial.println("2");
        state = STATE_CLOSED;
    }

    if (state == STATE_OPENNED && !isHigh(pio.limitOpen)) {
        Serial.println("3");
        state = STATE_INDEFINITE;
    } else if (state == STATE_CLOSED && !isHigh(pio.limitClose)) {
        Serial.println("4");
        state = STATE_INDEFINITE;
    }

    if ((isHigh(pio.open) || rc->isOpenCommand()) && state != STATE_OPENNED) {
        Serial.println("5");
        state = STATE_OPENING;
    } else if ((isHigh(pio.close) || rc->isCloseCommand()) && state != STATE_CLOSED) {
        Serial.println("6");
        state = STATE_CLOSING;
    }

    if (isHigh(pio.stop) || rc->isStopCommand()) {
        Serial.println("7");
        state = STATE_STOPPED;
    }

    if (isMoving()) {
        Serial.println("8");
        setOnSensorObstacle();
    } else {
        Serial.println("9");
        setOffSensorObstacle();
    }

    // todo
    // if (isMoving() && isObstacle()) {
    //     Serial.println("10");
    //     state = STATE_STOPPED;
    // }

    switch (state) {
        case STATE_OPENNED:
            Debug::printMessage("STATE_OPENNED");
            processOpennedState();
            break;
        case STATE_OPENING:
            Debug::printMessage("STATE_OPENING");
            processOpeningState();
            break;
        case STATE_CLOSED:
            Debug::printMessage("STATE_CLOSED");
            processClosedState();
            break;
        case STATE_CLOSING:
            Debug::printMessage("STATE_CLOSING");
            processClosingState();
            break;
        case STATE_STOPPED:
            Debug::printMessage("STATE_STOPPED");
            processStoppedState();
            break;
        default:
            Debug::printMessage("STATE_INDEFINITE");
            processIndefiniteState();
            break;
    }

    if (isMoving()) {
        setOnMovingIndicator();
    } else {
        setOffMovingIndicator();
    }

    rc->clearCommand();
}

void GateController::processIndefiniteState() {
    setContactors(false, false);
}

void GateController::processOpennedState() {
    setContactors(false, false);
}

void GateController::processOpeningState() {
    setContactors(true, false);
}

void GateController::processClosedState() {
    setContactors(false, false);
}

void GateController::processClosingState() {
    setContactors(false, true);
}

void GateController::processStoppedState() {
    setContactors(false, false);
}

