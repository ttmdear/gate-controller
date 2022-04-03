#include <Arduino.h>
#include <Receiver.h>

Receiver::Receiver(int pin) {
    this->pin = pin;
}

void Receiver::init() {
    reset();
}

void Receiver::loop() {
    if (message != 'n') return;

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

    if (p >= 72) {
        message = MESSAGE_B;
    }
}

void Receiver::reset() {
    sample = digitalRead(pin);
    sampleAt = micros();
    message = MESSAGE_NONE;
    p = -1;
    step = 0;
    bf = 0;

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

bool Receiver::isMessage() {
    return message != MESSAGE_NONE;
}

char Receiver::readMessage() {
    char tmp = message;
    reset();
    return tmp;
}