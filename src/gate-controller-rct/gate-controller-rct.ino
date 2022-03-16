#include <VirtualWire.h>

#define PIN_TX 8
#define PIN_RX 9
#define PIN_STATE 13
#define PIN_BUTTON_OPEN 4
#define PIN_BUTTON_CLOSE 3
#define PIN_BUTTON_STOP 2

#define OPEN_MSG 'o'
#define CLOSE_MSG 'c'
#define STOP_MSG 's'

void blikSetup() {
    digitalWrite(PIN_STATE, HIGH);
    delay(2000);
    digitalWrite(PIN_STATE, LOW);
    delay(1000);
    digitalWrite(PIN_STATE, HIGH);
    delay(500);
    digitalWrite(PIN_STATE, LOW);
}

void setup() {
    delay(1000);
    Serial.begin(9600);    // Debugging only
    Serial.println("setup");

    vw_set_tx_pin(PIN_TX);
    vw_set_rx_pin(PIN_RX);
    vw_set_ptt_inverted(true);
    vw_setup(2000);

    pinMode(PIN_BUTTON_OPEN, INPUT);
    pinMode(PIN_BUTTON_CLOSE, INPUT);
    pinMode(PIN_BUTTON_STOP, INPUT);

    blikSetup();
}

void transmit(char msg) {
    Serial.print("transmit ");
    Serial.println(msg);

    char buf[1] = {msg};

    digitalWrite(PIN_STATE, HIGH);
    vw_send((uint8_t *)buf, 1);
    vw_wait_tx();
    digitalWrite(PIN_STATE, LOW);

    Serial.println("end");
}

void loop(){
    if (digitalRead(PIN_BUTTON_OPEN) == HIGH) {
        transmit(OPEN_MSG);
    } else if (digitalRead(PIN_BUTTON_CLOSE) == HIGH) {
        transmit(CLOSE_MSG);
    } else if (digitalRead(PIN_BUTTON_STOP) == HIGH) {
        transmit(STOP_MSG);
    }
}
