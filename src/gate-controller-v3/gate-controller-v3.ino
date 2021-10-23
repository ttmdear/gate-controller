#include <VirtualWire.h>

#define PIN_CLOSE 2
#define PIN_OPEN 3
#define PIN_STOP 4
#define PIN_LIMIT_OPEN 5
#define PIN_LIMIT_CLOSE 6
#define PIN_CONVERTER_SWITCH 7
#define PIN_CONTACTOR_OPEN 8
#define PIN_CONTACTOR_CLOSE 9
#define PIN_RF_RECEIVER 10

class RemoteController {
private:
    uint8_t data[VW_MAX_MESSAGE_LEN];
    uint8_t dataLength = VW_MAX_MESSAGE_LEN;

    char command[VW_MAX_MESSAGE_LEN];
public:
    RemoteController(int pin);
    void process();
    bool isOpenCommand();
    bool isCloseCommand();
    bool isStopCommand();
    void clearCommand();
};

RemoteController* remoteController;

void setup() {
    Serial.begin(9600); // open the serial port at 9600 bps:
    pinMode(PIN_CLOSE, INPUT);
    pinMode(PIN_OPEN, INPUT);
    pinMode(PIN_STOP, INPUT);
    pinMode(PIN_LIMIT_OPEN, INPUT);
    pinMode(PIN_LIMIT_CLOSE, INPUT);
    pinMode(PIN_CONVERTER_SWITCH, OUTPUT);
    pinMode(PIN_CONTACTOR_OPEN, OUTPUT);
    pinMode(PIN_CONTACTOR_CLOSE, OUTPUT);

    Serial.println("setup");

    remoteController = new RemoteController(PIN_RF_RECEIVER);
}


int i = 0;
void loop() {
    test();
}

void test() {
    Serial.println("START TEST");


    Serial.println("PRESS CLOSE");
    while(digitalRead(PIN_CLOSE) != HIGH);

    Serial.println("PRESS OPEN");
    while(digitalRead(PIN_OPEN) != HIGH);

    Serial.println("PRESS STOP");
    while(digitalRead(PIN_STOP) != HIGH);

    Serial.println("PRESS LIMIT OPEN");
    while(digitalRead(PIN_LIMIT_OPEN) != HIGH);

    Serial.println("PRESS LIMIT CLOSE");
    while(digitalRead(PIN_LIMIT_CLOSE) != HIGH);

    Serial.println("PRESS CLOSE TO APPROVE");

    Serial.println("IF MAIN SWITCH IS UP");
    digitalWrite(PIN_CONVERTER_SWITCH, HIGH);
    while(digitalRead(PIN_CLOSE) != HIGH);

    Serial.println("IF OPEN SWITCH IS UP");
    digitalWrite(PIN_CONTACTOR_OPEN, HIGH);
    while(digitalRead(PIN_CLOSE) != HIGH);
    delay(2000);

    Serial.println("IF CLOSE SWITCH IS UP");
    digitalWrite(PIN_CONTACTOR_OPEN, LOW);
    digitalWrite(PIN_CONTACTOR_CLOSE, HIGH);
    while(digitalRead(PIN_CLOSE) != HIGH);
    delay(2000);

    digitalWrite(PIN_CONVERTER_SWITCH, LOW);
    digitalWrite(PIN_CONTACTOR_OPEN, LOW);
    digitalWrite(PIN_CONTACTOR_CLOSE, LOW);
    delay(2000);

    Serial.println("RF TEST");

    Serial.println("PRESS OPEN");
    while(true) {
        remoteController->process();

        if (remoteController->isOpenCommand()) {
            break;
        }
    }

    Serial.println("PRESS CLOSE");
    while(true) {
        remoteController->process();

        if (remoteController->isCloseCommand()) {
            break;
        }
    }

    Serial.println("PRESS STOP");
    while(true) {
        remoteController->process();

        if (remoteController->isStopCommand()) {
            break;
        }
    }

    Serial.println("TEST FINISHED");
}

void testContactors() {
    Serial.println("TEST_CONTRACTORS:START");

    digitalWrite(PIN_CONVERTER_SWITCH, LOW);
    digitalWrite(PIN_CONTACTOR_OPEN, LOW);
    digitalWrite(PIN_CONTACTOR_CLOSE, LOW);

    // digitalWrite(PIN_CONTACTOR_OPEN, LOW);
    // digitalWrite(PIN_CONTACTOR_CLOSE, LOW);
    // delay(5000);

    // digitalWrite(PIN_CONVERTER_SWITCH, LOW);
    // digitalWrite(PIN_CONTACTOR_OPEN, HIGH);
    // digitalWrite(PIN_CONTACTOR_CLOSE, LOW);
    // delay(5000);

    // digitalWrite(PIN_CONVERTER_SWITCH, LOW);
    // digitalWrite(PIN_CONTACTOR_OPEN, LOW);
    // digitalWrite(PIN_CONTACTOR_CLOSE, HIGH);
    // delay(5000);

    // digitalWrite(PIN_CONVERTER_SWITCH, HIGH);
    // digitalWrite(PIN_CONTACTOR_OPEN, LOW);
    // digitalWrite(PIN_CONTACTOR_CLOSE, HIGH);
    // delay(5000);
    
    Serial.println("TEST_CONTRACTORS:STOP");

}

RemoteController::RemoteController(int pin) {
    Serial.print("RemoteController::RemoteController ");
    Serial.println(pin);

    vw_set_ptt_inverted(true);
    vw_set_rx_pin(pin);
    vw_setup(2000);

    vw_rx_start();
}

void RemoteController::process() {
    dataLength = VW_MAX_MESSAGE_LEN;
    bool message = vw_get_message(data, &dataLength);

    if(message) {
        Serial.print("dataLength  ");Serial.println(dataLength);
        memset(command, 0, sizeof(command));

        for(int i = 0; i < dataLength; i++) {
            command[i] = data[i];
        }


        Serial.print("REMOTE MESSAGE ");Serial.println(command);
    }
}

bool RemoteController::isOpenCommand() {
    return strcmp(command, "open") == 0;
}

bool RemoteController::isCloseCommand() {
    return strcmp(command, "close") == 0;
}

bool RemoteController::isStopCommand() {
    return strcmp(command, "stop") == 0;
}

void RemoteController::clearCommand() {
    memset(command, 0, sizeof(command));
}
