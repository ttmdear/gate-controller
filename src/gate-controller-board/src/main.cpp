#include <Arduino.h>

#define ledPin 13

int timer1_counter;
unsigned long t = millis();

#define PIN_RF 11

class Receiver {
private:
    int sample = 0;
    int bufferSize = 73;
    int buffer[73];
    int p;
    bool message = false;
    unsigned long sampleAt;
public:
    void loop();

    void reset();

    void init();

    void dump();

    bool isMessage();
};

void Receiver::loop() {
    if (message) return;

    int s = digitalRead(PIN_RF);

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
        message = true;
    }
}

void Receiver::reset() {
    sample = digitalRead(PIN_RF);
    sampleAt = micros();
    message = false;

    p = -1;

    for (int i = 0; i < bufferSize; i++) {
        buffer[i] = 0;
    }
}

void Receiver::init() {
    reset();
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
    return message;
}


Receiver receiver;

void setup() {
    Serial.begin(9600);    // Debugging only
    Serial.println("setup");

    pinMode(PIN_RF, INPUT);

    receiver.init();

    // initialize timer1
    noInterrupts(); // disable all interrupts

    TCCR1A = 0;
    TCCR1B = 0;

    // 62500, jedna jednostka to 16us
    timer1_counter = 62499; // preload timer 65536-16MHz/256/2Hz

    TCNT1 = timer1_counter; // preload timer
    TCCR1B |= (1 << CS12); // 256 prescaler
    TIMSK1 |= (1 << TOIE1); // enable timer overflow interrupt
    interrupts(); // enable all interrupts
}

void loop() {
    receiver.loop();

    if (receiver.isMessage()) {
        receiver.dump();
    }
}

ISR(TIMER1_OVF_vect) {
    TCNT1 = timer1_counter; // preload timer
    receiver.loop();
}

// // // Pins
// // #define PIN_CLOSE 2
// // #define PIN_OPEN 3
// // #define PIN_STOP 4
// // #define PIN_LIMIT_CLOSE 5
// // #define PIN_LIMIT_OPEN 6
// // #define PIN_SWITCH_OPEN 7
// // #define PIN_SWITCH_CLOSE 8
// //
// // #define PIN_RF_INPUT 9
// // #define PIN_OBSTACLE_INPUT 10
// // #define PIN_MOVING_INDICATOR 11
// //
// // // State
// // #define STATE_OPENING 0
// // #define STATE_LIMIT_OPEN 1
// // #define STATE_CLOSING 2
// // #define STATE_LIMIT_CLOSE 3
// // #define STATE_STOP 4
// //
// // #define NONE_MSG 'n'
// // #define OPEN_MSG 'o'
// // #define CLOSE_MSG 'c'
// // #define STOP_MSG 's'
// //
// // const int led_pin = 13;
// // // const int transmit_pin = 12;
// // const int receive_pin = 9;
// // // const int transmit_en_pin = 3;
// //
// // void setup() {
// //     delay(1000);
// //     Serial.begin(9600);    // Debugging only
// //     Serial.println("setup");
// //
// //     // Initialise the IO and ISR
// //     // vw_set_tx_pin(transmit_pin);
// //     vw_set_rx_pin(receive_pin);
// //     // vw_set_ptt_pin(transmit_en_pin);
// //     vw_set_ptt_inverted(true); // Required for DR3100
// //     vw_setup(2000);     // Bits per sec
// //     vw_rx_start();       // Start the receiver PLL running
// //
// //     pinMode(PIN_CLOSE, INPUT);
// //     digitalWrite(PIN_CLOSE, HIGH);
// //
// //     pinMode(PIN_OPEN, INPUT);
// //     digitalWrite(PIN_OPEN, HIGH);
// //
// //     pinMode(PIN_STOP, INPUT);
// //     digitalWrite(PIN_STOP, HIGH);
// //
// //     pinMode(PIN_LIMIT_CLOSE, INPUT);
// //     digitalWrite(PIN_LIMIT_CLOSE, HIGH);
// //
// //     pinMode(PIN_LIMIT_OPEN, INPUT);
// //     digitalWrite(PIN_LIMIT_OPEN, HIGH);
// //
// //     pinMode(PIN_SWITCH_OPEN, OUTPUT);
// //     digitalWrite(PIN_SWITCH_OPEN, LOW);
// //
// //     pinMode(PIN_SWITCH_CLOSE, OUTPUT);
// //     digitalWrite(PIN_SWITCH_CLOSE, LOW);
// //
// //     pinMode(PIN_RF_INPUT, INPUT);
// //     pinMode(PIN_OBSTACLE_INPUT, INPUT);
// //     pinMode(PIN_MOVING_INDICATOR, OUTPUT);
// // }
// //
// // int state = STATE_STOP;
// // int statePrevious = state;
// //
// // void test();
// //
// // uint8_t receive() {
// //     uint8_t buf[VW_MAX_MESSAGE_LEN];
// //     uint8_t buflen = VW_MAX_MESSAGE_LEN;
// //
// //     buf[0] = NONE_MSG;
// //
// //     if (vw_get_message(buf, &buflen)) {
// //         int i;
// //
// //         // digitalWrite(led_pin, HIGH); // Flash a light to show received good message
// //
// //         // Message with a good checksum received, print it.
// //         Serial.print("Got: ");
// //
// //         for (i = 0; i < buflen; i++) {
// //             // Serial.print(buf[i], HEX);
// //             Serial.print(buf[i], HEX);
// //             Serial.print(' ');
// //         }
// //
// //         Serial.println();
// //         // digitalWrite(led_pin, LOW);
// //     }
// //
// //     return buf[0];
// // }
// //
// // bool isLow(char pin) {
// //     return digitalRead(pin) == LOW;
// // }
// //
// // void setUpDown(char pinUp, char pinDown) {
// //     digitalWrite(pinDown, LOW);
// //     digitalWrite(pinUp, HIGH);
// // }
// //
// // void setDown(char pinA, char pinB) {
// //     digitalWrite(pinA, LOW);
// //     digitalWrite(pinB, LOW);
// // }
// //
// // void setState(int value) {
// //     if (value != state) {
// //         state = value;
// //
// //         Serial.print("state change ");
// //         Serial.println(state);
// //     }
// // }
// //
// // void blik19() {
// //     for(int i = 0; i <= 10; i++) {
// //         digitalWrite(13, HIGH);
// //         delay(100);
// //         digitalWrite(13, LOW);
// //     }
// // }
// //
// // void loop() {
// //     uint8_t r = receive();
// //
// //     if (r != NONE_MSG) {
// //         if (r == OPEN_MSG) {
// //             setState(STATE_OPENING);
// //             Serial.println("rf open");
// //             blik19();
// //         } else if (r == CLOSE_MSG) {
// //             setState(STATE_CLOSING);
// //             Serial.println("rf close");
// //             blik19();
// //         } else if (r == STOP_MSG) {
// //             setState(STATE_STOP);
// //             Serial.println("rf stop");
// //             blik19();
// //         }
// //     }
// //
// //     // if (isLow(PIN_CLOSE) && !isLow(PIN_LIMIT_CLOSE)) {
// //     //     setState(STATE_CLOSING);
// //     //     Serial.println("a");
// //     // } else if (isLow(PIN_OPEN) && !isLow(PIN_LIMIT_OPEN)) {
// //     //     setState(STATE_OPENING);
// //     //     Serial.println("b");
// //     // }
// //
// //     // if (isLow(PIN_STOP)) {
// //     //     setState(STATE_STOP);
// //     //     Serial.println("c");
// //     // }
// //
// //     // if (state == STATE_OPENING && isLow(PIN_LIMIT_OPEN)) {
// //     //     state = STATE_STOP;
// //     //     Serial.println("d");
// //     // } else if (state == STATE_CLOSING && isLow(PIN_LIMIT_CLOSE)) {
// //     //     state = STATE_STOP;
// //     //     Serial.println("e");
// //     // }
// //
// //     // if (state != statePrevious) {
// //     //     if (state == STATE_STOP) {
// //     //         setDown(PIN_SWITCH_OPEN, PIN_SWITCH_CLOSE);
// //     //         Serial.println("f");
// //     //     } else if (state == STATE_CLOSING) {
// //     //         setUpDown(PIN_SWITCH_CLOSE, PIN_SWITCH_OPEN);
// //     //         Serial.println("g");
// //     //     } else if (state == STATE_OPENING) {
// //     //         setUpDown(PIN_SWITCH_OPEN, PIN_SWITCH_CLOSE);
// //     //         Serial.println("h");
// //     //     }
// //
// //     //     statePrevious = state;
// //     // }
// // }