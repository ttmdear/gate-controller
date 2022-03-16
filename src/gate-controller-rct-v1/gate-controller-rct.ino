#define PIN_BUTTON_OPEN 3
#define PIN_BUTTON_CLOSE 2
#define PIN_BUTTON_STOP 1
#define PIN_RF 0
#define PIN_INDICATOR 4

#define SIGNAL_OPEN_TIME 250
#define SIGNAL_CLOSE_TIME 500
#define SIGNAL_STOP_TIME 750

#define SIGNAL_BREAK_TIME 250

unsigned long time = millis();
unsigned long transmitLast = millis();

void setup() {
    pinMode(PIN_BUTTON_OPEN, INPUT);
    pinMode(PIN_BUTTON_CLOSE, INPUT);
    pinMode(PIN_BUTTON_STOP, INPUT);

    digitalWrite(PIN_BUTTON_OPEN, HIGH);
    digitalWrite(PIN_BUTTON_CLOSE, HIGH);
    digitalWrite(PIN_BUTTON_STOP, HIGH);

    pinMode(PIN_INDICATOR, OUTPUT);

    pinMode(PIN_RF, OUTPUT);
    digitalWrite(PIN_RF, HIGH);

    blinkSetup();
}

void signal(int time) {
    for(int i=0; i<7; i++) {
        digitalWrite(PIN_RF, LOW);
        delayMicroseconds(time);

        digitalWrite(PIN_RF, HIGH);
        delayMicroseconds(SIGNAL_BREAK_TIME);
    }
}

void transmit(const char* message) {
    int i = 0;
    while(true) {
        if (message[i] == '\0') break;

        for(char p = 7; p >= 0; p--) {
            if (message[i] & (1 << p)) {
                signal(true);
            } else {
                signal(false);
            }
        }

        i++;
    }
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

void loop() {
    blikLoop();

    if (millis() - transmitLast < 10) {
        return;
    }

    if (!digitalRead(PIN_BUTTON_OPEN)) {
        signal(SIGNAL_OPEN_TIME);
        transmitLast = millis();
    } else if (!digitalRead(PIN_BUTTON_CLOSE)) {
        signal(SIGNAL_CLOSE_TIME);
        transmitLast = millis();
    } else if (!digitalRead(PIN_BUTTON_STOP)) {
        signal(SIGNAL_STOP_TIME);
        transmitLast = millis();
    }
}
