#include <Arduino.h>
#include <Receiver.h>

#define PIN_OPEN 2
#define PIN_CLOSE 12
#define PIN_STOP 4
#define PIN_OPEN_LIMIT 5
#define PIN_CLOSE_LIMIT 6
#define PIN_OPEN_SWITCH 7
#define PIN_CLOSE_SWITCH 8
#define PIN_OBSTACLE 9
#define PIN_MOVING 10
#define PIN_RF 11

#define STATE_STOP 1
#define STATE_OPEN 2
#define STATE_CLOSE 3

int timer1_counter;
unsigned long t = millis();
uint8_t stat;
uint8_t prev;

Receiver receiver(PIN_RF);

void initPin(uint8_t pin, uint8_t mode, uint8_t state) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, state);
    pinMode(pin, mode);
}

bool isl(uint8_t pin) {
    return digitalRead(pin) == LOW;
}

bool ish(uint8_t pin) {
    return digitalRead(pin) == HIGH;
}

void setSwitch(uint8_t open, uint8_t close) {
    if (open && close) {
        open = LOW;
        close = LOW;
    }

    digitalWrite(PIN_OPEN_SWITCH, open);
    digitalWrite(PIN_CLOSE_SWITCH, close);

}

void setup() {
    Serial.begin(9600); // Debugging only
    Serial.println("setup");

    pinMode(PIN_OPEN, INPUT_PULLUP);
    pinMode(PIN_CLOSE, INPUT_PULLUP);
    pinMode(PIN_STOP, INPUT_PULLUP);
    pinMode(PIN_OPEN_LIMIT, INPUT_PULLUP);
    pinMode(PIN_CLOSE_LIMIT, INPUT_PULLUP);

    initPin(PIN_OPEN_SWITCH, OUTPUT, LOW);
    initPin(PIN_CLOSE_SWITCH, OUTPUT, LOW);

    initPin(PIN_OBSTACLE, INPUT, HIGH);
    initPin(PIN_MOVING, OUTPUT, LOW);
    initPin(PIN_RF, INPUT, LOW);

    stat = STATE_STOP;
    prev = stat;

    receiver.init();

    // initialize timer1
    noInterrupts(); // disable all interrupts

    TCCR1A = 0;
    TCCR1B = 0;

    // 65536, jedna jednostka to 16us
    // 65536, jedna jednostka to 4us to 0.262144
    timer1_counter = 65532; // preload timer 65536-16MHz/256/2Hz

    TCNT1 = timer1_counter; // preload timer
    // TCCR1B |= (1 << CS12); // 256 prescaler
    TCCR1B |= (1 << CS11); // 64 prescaler
    TCCR1B |= (1 << CS10); // 64 prescaler
    TIMSK1 |= (1 << TOIE1); // enable timer overflow interrupt
    interrupts(); // enable all interrupts
}

unsigned long m1 = micros();
unsigned long db = 0;
unsigned long d = 0;

void printPin(const char label[], int pin) {
    Serial.print(label);
    Serial.println(digitalRead(pin));
}

void printPinState() {
    printPin("PIN_OPEN        : ", PIN_OPEN);
    printPin("PIN_CLOSE       : ", PIN_CLOSE);
    printPin("PIN_STOP        : ", PIN_STOP);
    printPin("PIN_OPEN_LIMIT  : ", PIN_OPEN_LIMIT);
    printPin("PIN_CLOSE_LIMIT : ", PIN_CLOSE_LIMIT);
    Serial.println("-------------------------");
}

void loop() {
     if (ish(PIN_OPEN_LIMIT) && (isl(PIN_OPEN) || receiver.isOpen())) {
         stat = STATE_OPEN;
     } else if (ish(PIN_CLOSE_LIMIT) && (isl(PIN_CLOSE) || receiver.isClose())) {
         stat = STATE_CLOSE;
     }

     if (isl(PIN_STOP) || receiver.isStop()) {
         stat = STATE_STOP;
     } else if (prev == STATE_OPEN && isl(PIN_OPEN_LIMIT)) {
         stat = STATE_STOP;
     } else if (prev == STATE_CLOSE && isl(PIN_CLOSE_LIMIT)) {
         stat = STATE_STOP;
     }

     if (prev != stat) {
         if (stat == STATE_STOP) {
             setSwitch(LOW, LOW);
             Serial.println("stop");
             prev = stat;
         } else if (stat == STATE_OPEN) {
             setSwitch(HIGH, LOW);
             Serial.println("open");
         } else if (stat == STATE_CLOSE) {
             setSwitch(LOW, HIGH);
             Serial.println("close");
         }

         prev = stat;
     }

     if (receiver.isAction()) {
         receiver.reset();
     }
}

ISR(TIMER1_OVF_vect) {
    TCNT1 = timer1_counter; // preload timer
    receiver.loop();
}