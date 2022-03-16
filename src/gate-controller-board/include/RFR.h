#ifndef GATE_CONTROLLER_BOARD_RFR_H
#define GATE_CONTROLLER_BOARD_RFR_H

// #define SIGNAL_OPEN_TIME 500
// #define SIGNAL_CLOSE_TIME 1000
// #define SIGNAL_STOP_TIME 1500

// Transmiter
// #define SIGNAL_OPEN_TIME 1500
// #define SIGNAL_CLOSE_TIME 2500
// #define SIGNAL_STOP_TIME 3500
#define SIGNAL_OPEN_TIME 4000
#define SIGNAL_CLOSE_TIME 8000
#define SIGNAL_STOP_TIME 12000
#define SIGNAL_BREAK_TIME 250
#define SIGNAL_OPEN 1
#define SIGNAL_CLOSE 2
#define SIGNAL_STOP 3

class RFR {
private:
    char pin;
    bool sample = false;
    unsigned int sampleLStart = 0;
    unsigned int sampleLEnd = 0;
    unsigned int sampleHStart = 0;
    unsigned int sampleHEnd = 0;

    char signal = 0;
    char signalPhase = 0;
    char signalRead = 0;
public:
    RFR(char pin);

    void loop();
    char resolveSignal(unsigned int delta);
    bool isSignal();
    char readSignal();
    bool isSignalOpen();
    bool isSignalClose();
    bool isSignalStop();
    void cleanSignal();
};

#endif
