
#include <Debug.h>
#include "../../../../../../../../opt/arduino-1.8.9/hardware/arduino/avr/cores/arduino/HardwareSerial.h"
#include <Arduino.h>

struct Data {
    char *label;
    unsigned long value;
};

#define DATA_LIST_LENGTH 2

Data **dataList = new Data *[DATA_LIST_LENGTH];

void Debug::init() {
    Serial.begin(9600);

    for (uint8_t i = 0; i < DATA_LIST_LENGTH; i++) {
        dataList[i] = nullptr;
    }
}

void Debug::printVar(const char *label, const char *value) {
    Serial.print(label);
    Serial.print(" ");
    Serial.println(value);
}

void Debug::printMessage(const char *message) {
    Serial.println(message);
}

void Debug::delay(unsigned long t) {
    ::delay(t);
}

void Debug::printVar(const char *label, const char value) {
    Serial.print(label);
    Serial.print(" ");
    Serial.println(value);
}

void Debug::printVar(const char *label, bool value) {
    Serial.print(label);
    Serial.print(" ");
    Serial.println(value);
}

void Debug::printVar(const char *label, int value) {
    Serial.print(label);
    Serial.print(" ");
    Serial.println(value);
}

void Debug::printVar(const char *label, float value) {
    Serial.print(label);
    Serial.print(" ");
    Serial.println(value);
}

int getFreeRam() {
    extern int __heap_start, *__brkval;

    int v;

    return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}

int getDataSection() {
    extern int __data_end;

    return (int) &__data_end;
}

int getVariableSize() {
    extern int __bss_start, __bss_end;

    return (int) (&__bss_end - &__bss_start);
}

void printRepeat(const char *c, uint8_t n) {
    for (uint8_t i = 0; i < n; i++) {
        Serial.print(c);
    }

    Serial.println();
}

void Debug::printFreeMemory(const char *label) {
    Serial.print("M:");
    Serial.print(label);
    Serial.print(" ");
    Serial.println(getFreeRam());
}

void Debug::printMemoryState(const char *label) {
    Serial.print("Memory state ");
    Serial.println(label);
    printRepeat("-", 32);
    printVar("Free memory     ", getFreeRam());
    printVar("Data section    ", getDataSection());
    printVar("Variable section", getVariableSize());
    printRepeat("-", 32);
}

void Debug::stop(int status) {
    Serial.print("Stop program with status ");
    Serial.println(status);

    while (true);
}

void Debug::print(const char *message) {
    Serial.print(message);
}

void Debug::println(const char *message) {
    Serial.println(message);
}

void Debug::println() {
    Serial.println();
}

void Debug::printVar(const char *label, unsigned int value) {
    Serial.print(label);
    Serial.print(" ");
    Serial.println(value);
}

void Debug::printVar(const char *label, uint32_t value) {
    Serial.print(label);
    Serial.print(" ");
    Serial.println(value);
}

void Debug::startTimer(const char *label) {
    for (uint8_t i = 0; i < DATA_LIST_LENGTH; i++) {
        if (dataList[i] == nullptr) {
            dataList[i] = new Data();

            dataList[i]->label = new char[strlen(label) + 1];

            strcpy(dataList[i]->label, label);
            dataList[i]->value = millis();

            return;
        }
    }
}

void Debug::stopTimer(const char *label) {
    for (uint8_t i = 0; i < DATA_LIST_LENGTH; i++) {
        if (dataList[i] == nullptr || strcmp(dataList[i]->label, label) != 0) {
            continue;
        }

        Serial.print("Timer ");
        Serial.print(label);
        Serial.print(" ");
        Serial.println(millis() - dataList[i]->value);

        delete [] dataList[i]->label;
        delete dataList[i];

        dataList[i] = nullptr;
    }
}
