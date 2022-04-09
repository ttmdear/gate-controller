#ifndef GATE_CONTROLLER_BOARD_RECEIVER_H
#define GATE_CONTROLLER_BOARD_RECEIVER_H

#define ACTION_NONE 'n'
#define ACTION_A 'a'
#define ACTION_B 'b'
#define ACTION_C 'c'
#define ACTION_D 'd'

class Receiver {
private:
    int pin;
    int sample = 0;
    unsigned long sampleAt;
    int bufferSize = 73;
    int buffer[73];

    int p;
    char action;

    char a[73] = {1,1,0,1,0,0,1,0,0,1,1,0,1,0,0,1,1,0,1,1,0,1,0,0,1,1,0,1,0,0,1,0,0,1,1,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,1,0,1,0,0,1,1,0,1,0,0,1,1,0,1,0,0,1,0,0,1};
    char b[73] = {1,1,0,1,0,0,1,0,0,1,1,0,1,0,0,1,1,0,1,1,0,1,0,0,1,1,0,1,0,0,1,0,0,1,1,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,1,0,1,0,0,1,1,0,1,1,0,1,0,0,1,0,0,1,0,0,1};
    char c[73] = {1,1,0,1,0,0,1,0,0,1,1,0,1,0,0,1,1,0,1,1,0,1,0,0,1,1,0,1,0,0,1,0,0,1,1,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,1,0,1,0,0,1,1,0,1,0,0,1,0,0,1,0,0,1,1,0,1};
    char d[73] = {1,1,0,1,0,0,1,0,0,1,1,0,1,0,0,1,1,0,1,1,0,1,0,0,1,1,0,1,0,0,1,0,0,1,1,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,1,0,1,0,0,1,1,0,1,0,0,1,0,0,1,1,0,1,0,0,1};

    bool ac;
    bool bc;
    bool cc;
    bool dc;
public:
    explicit Receiver(int pin);

    void loop();

    void reset();

    void init();

    void dump();

    bool isAction();

    bool isOpen();

    bool isClose();

    bool isStop();

    char readMessage();
};

#endif
