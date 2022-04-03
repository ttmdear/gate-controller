#ifndef GATE_CONTROLLER_BOARD_RECEIVER_H
#define GATE_CONTROLLER_BOARD_RECEIVER_H

#define MESSAGE_NONE 'n'
#define MESSAGE_A 'a'
#define MESSAGE_B 'b'
#define MESSAGE_C 'c'
#define MESSAGE_D 'd'

class Receiver {
private:
    int pin;
    int sample = 0;
    int bufferSize = 73;
    int buffer[73];
    uint64_t bf = 0;
    int p;
    char step = 0;
    char message = 'n';
    unsigned long sampleAt;

    uint64_t m = 0xD269B4D269249A6;
    uint64_t a = 0x92;
    uint64_t b = 0x93;
    uint64_t c = 0x9A;
    uint64_t d = 0xD2;
public:
    explicit Receiver(int pin);

    void loop();

    void reset();

    void init();

    void dump();

    bool isMessage();

    char readMessage();
};

#endif
