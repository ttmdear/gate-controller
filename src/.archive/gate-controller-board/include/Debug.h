#ifndef GAME_BOARD_DEBUG_H
#define GAME_BOARD_DEBUG_H

#include <stdint-gcc.h>

class Debug {

public:
    static void init();

    static void printVar(const char *label, const char *value);

    static void printVar(const char *label, const char value);

    static void printVar(const char *label, bool value);

    static void printVar(const char *label, int value);

    static void printVar(const char *label, unsigned int value);

    static void printVar(const char *label, uint32_t value);

    static void printVar(const char *label, float value);

    static void printMessage(const char *message);

    static void print(const char *message);

    static void println(const char *message);

    static void println();

    static void stop(int status);

    static void delay(unsigned long t);

    static void printMemoryState(const char *label);

    static void printFreeMemory(const char *label);

    static void startTimer(const char *label);

    static void stopTimer(const char *label);
};

#endif //GAME_BOARD_DEBUG_H
