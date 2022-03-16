#define PIN_RF 2
#define PIN_INDICATOR 0
#define PIN_OPEN 1
#define PIN_CLOSE 3
#define PIN_STOP 4

#define SIGNAL_OPEN_TIME 500
#define SIGNAL_CLOSE_TIME 1000
#define SIGNAL_STOP_TIME 1500
#define SIGNAL_BREAK_TIME 250 
#define SIGNAL_OPEN 1
#define SIGNAL_CLOSE 2
#define SIGNAL_STOP 3

unsigned long time = millis();
unsigned long transmitLast = millis();

class RF {
private:
    bool sample = false;
    unsigned int sampleLStart = 0;
    unsigned int sampleLEnd = 0;
    unsigned int sampleHStart = 0;
    unsigned int sampleHEnd = 0;

    char signal = 0;
    char signalPhase = 0;
    char signalRead = 0;
public:
    void loop();
    char resolveSignal(unsigned int delta);
    bool isSignal();
    char readSignal();
};

char RF::resolveSignal(unsigned int delta) {
    if (delta >= (SIGNAL_OPEN_TIME - 50) && delta <= (SIGNAL_OPEN_TIME + 50)) {
        return SIGNAL_OPEN;
    } else if (delta >= (SIGNAL_CLOSE_TIME - 50) && delta <= (SIGNAL_CLOSE_TIME + 50)) {
        return SIGNAL_CLOSE;
    } else if (delta >= (SIGNAL_STOP_TIME - 50) && delta <= (SIGNAL_STOP_TIME + 50)) {
        return SIGNAL_STOP;
    } else {
        return 0;
    }
}

bool RF::isSignal() {
    return signalRead != 0;
}

char RF::readSignal() {
    char tmp = signalRead;
    signalRead = 0;
    return tmp;
}

void RF::loop() {
    bool measurement = digitalRead(PIN_RF);

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

        if (delta < 100 || delta > 300) {
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

void setup() {
    blinkSetup();

    pinMode(PIN_RF, INPUT);
    pinMode(PIN_INDICATOR, OUTPUT);
    pinMode(PIN_OPEN, OUTPUT);
    pinMode(PIN_CLOSE, OUTPUT);
    pinMode(PIN_STOP, OUTPUT);

    digitalWrite(PIN_OPEN, LOW);
    digitalWrite(PIN_CLOSE, LOW);
    digitalWrite(PIN_STOP, LOW);
}

void blikLoop() {
    if (millis() - time > 1000) {
        digitalWrite(PIN_INDICATOR, !digitalRead(PIN_INDICATOR));
        time = millis();
    }
}

void blinkSetup() {
    digitalWrite(PIN_INDICATOR, HIGH);
    delay(100);
    digitalWrite(PIN_INDICATOR, LOW);
    delay(100);
    digitalWrite(PIN_INDICATOR, HIGH);
    delay(100);
    digitalWrite(PIN_INDICATOR, LOW);

}

void rfLoop() {

}


RF rf;

void loop() {
    blikLoop();

    rf.loop();

    if (rf.isSignal()) {
        char signal = rf.readSignal();

        if (signal == SIGNAL_OPEN) {
            digitalWrite(PIN_OPEN, HIGH);
        } else if (signal == SIGNAL_CLOSE) {
            digitalWrite(PIN_CLOSE, HIGH);
        } else if (signal == SIGNAL_STOP) {
            digitalWrite(PIN_STOP, HIGH);
        }
    }
}
