#include <RFR.h>
#include <Arduino.h>

char RFR::resolveSignal(unsigned int delta) {
    unsigned int margin = 1000;
    if (delta >= SIGNAL_OPEN_TIME && delta <= SIGNAL_OPEN_TIME + margin) {
        return SIGNAL_OPEN;
    } else if (delta >= SIGNAL_CLOSE_TIME && delta <= SIGNAL_CLOSE_TIME + margin) {
        return SIGNAL_CLOSE;
    } else if (delta >= SIGNAL_STOP_TIME && delta <= SIGNAL_STOP_TIME + margin) {
        return SIGNAL_STOP;
    } else {
        return 0;
    }
    // int margin = 100;
    // if (delta >= (SIGNAL_OPEN_TIME - margin) && delta <= (SIGNAL_OPEN_TIME + margin)) {
    //     return SIGNAL_OPEN;
    // } else if (delta >= (SIGNAL_CLOSE_TIME - margin) && delta <= (SIGNAL_CLOSE_TIME + margin)) {
    //     return SIGNAL_CLOSE;
    // } else if (delta >= (SIGNAL_STOP_TIME - margin) && delta <= (SIGNAL_STOP_TIME + margin)) {
    //     return SIGNAL_STOP;
    // } else {
    //     return 0;
    // }
}

bool RFR::isSignal() {
    return signalRead != 0;
}

char RFR::readSignal() {
    char tmp = signalRead;
    signalRead = 0;
    return tmp;
}

bool RFR::isSignalOpen() {
    return signalRead == SIGNAL_OPEN;
}

bool RFR::isSignalClose() {
    return signalRead == SIGNAL_CLOSE;
}

bool RFR::isSignalStop() {
    return signalRead == SIGNAL_STOP;
}

void RFR::cleanSignal() {
    signalRead = 0;
}

void RFR::loop() {
    bool measurement = digitalRead(pin);

    if (measurement == sample) {
        // The sample didn't change
        return;
    }

    sample = measurement;
    unsigned int time = micros();

    // Change to lower
    if (!sample) {
        sampleHEnd = time;
        sampleLStart = time;

        if (sampleHStart == 0) return;

        unsigned int delta = sampleHEnd - sampleHStart;

        if (delta < 3500 || delta > 4500) {
            signal = 0;
            signalPhase = 0;
        }
    } else {
        sampleLEnd = time;
        sampleHStart = time;

        if (sampleLStart == 0) return;

        char signalLoop = resolveSignal(sampleLEnd - sampleLStart);

        if (signalLoop == 0) {
            signal = 0;
            signalPhase = 0;
        } else if (signal == 0) {
            signal = signalLoop;
            signalPhase = 1;
        } else if (signal == signalLoop) {
            signalPhase++;
        } else if (signal != signalLoop) {
            signal = 0;
            signalPhase = 0;
        }
    }

    if (signalPhase >= 3) {
        signalRead = signal;
        signal = 0;
        signalPhase = 0;
    }
}

RFR::RFR(char pin) {
    this->pin = pin;
}
