#include <Arduino.h>
#include <Receiver.h>

Receiver::Receiver(int pin) {
    this->pin = pin;
}

void Receiver::init() {
    reset();
}

void Receiver::loop() {
    if (action != 'n') return;

    int s = digitalRead(pin);

    if (s == sample) {
        return;
    }

    unsigned long time = micros();
    unsigned long delta = time - sampleAt;

    sample = s;
    sampleAt = time;

    int bits = 0;

    if (delta > 350 && delta < 450) {
        bits = 1;
    } else if (delta > 1100 && delta < 1300) {
        bits = 2;
    } else {
        reset();
        return;
    }

    if (bits == 1) {
        buffer[++p] = !s;
    } else {
        buffer[++p] = !s;
        buffer[++p] = !s;
    }

    if (ac && a[p] != buffer[p]) {
        ac = false;
    }

    if (bc && b[p] != buffer[p]) {
        bc = false;
    }

    if (cc && c[p] != buffer[p]) {
        cc = false;
    }

    if (dc && d[p] != buffer[p]) {
        dc = false;
    }

    if (!ac && !bc && !cc && !dc) {
        reset();
        return;
    }

    if (p >= 72) {
        if (ac) action = ACTION_A;
        else if (bc) action = ACTION_B;
        else if (cc) action = ACTION_C;
        else if (dc) action = ACTION_D;
    }
}

void Receiver::reset() {
    sample = digitalRead(pin);
    sampleAt = micros();

    p = -1;
    action = ACTION_NONE;

    ac = true;
    bc = true;
    cc = true;
    dc = true;

    for (int i = 0; i < bufferSize; i++) {
        buffer[i] = 0;
    }
}

void Receiver::dump() {
    for (int i = 0; i < bufferSize; i++) {
        if (buffer[i]) {
            Serial.print("1");
        } else {
            Serial.print("0");
        }
    }

    Serial.println();
    reset();
}

bool Receiver::isAction() {
    return action != ACTION_NONE;
}

bool Receiver::isOpen() {
    if (action == ACTION_A) {
        reset();
        return true;
    } else {
        return false;
    }
}

bool Receiver::isClose() {
    if (action == ACTION_B) {
        reset();
        return true;
    } else {
        return false;
    }
}

bool Receiver::isStop() {
    if (action == ACTION_C || action == ACTION_D) {
        reset();
        return true;
    } else {
        return false;
    }
}

char Receiver::readMessage() {
    char tmp = action;
    reset();
    return tmp;
}