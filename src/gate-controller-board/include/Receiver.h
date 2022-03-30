#ifndef GATE_CONTROLLER_BOARD_RECEIVER_H
#define GATE_CONTROLLER_BOARD_RECEIVER_H

class Receiver {
private:
    int pin;
    int sample = 0;
    int bufferSize = 73;
    int buffer[73];
    int p;
    bool message = false;
    unsigned long sampleAt;
public:
    explicit Receiver(int pin);

    void loop();

    void reset();

    void init();

    void dump();

    bool isMessage();
};

#endif
