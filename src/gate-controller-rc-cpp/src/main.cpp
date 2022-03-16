#include <iostream>
#include <vector>
#include <chrono>

#define HIGHT true
#define LOW false

using namespace std;

// Global
chrono::high_resolution_clock clk;

uint16_t microseconds() {
    return chrono::duration_cast<chrono::microseconds>(clk.now().time_since_epoch()).count();
}

class Wire {
private:
    vector<char> data;
    uint16_t time;
    char state = 0;
public:
    Wire();

    char getState() const;
    void loop();
    void printOut();
    void setState(char state);
};

Wire::Wire() {
    time = microseconds();
}

void Wire::loop() {
    uint16_t now = ::microseconds();

    if (now - time > 10) {
        data.push_back(state);
        time = now;
    }
}

char Wire::getState() const {
    return state;
}

void Wire::setState(char state) {
    this->state = state;
}

int digitalRead(char pin) {

}

void Wire::printOut() {
    int size = data.size();
    char state;
    char statePrevious = 0;

    for(int i=0; i<size; i++) {
        state = data.at(i);

        if (statePrevious != state) {
            cout<<"|";
        }

        if (state) {
            cout<<"^^^";
        } else {
            cout<<"___";
        }
    }
}

void signal(char pin, bool value) {
    if (value) {
        cout<<"---";
    } else {
        cout<<"___";
    }
}

void transmit(const char* message) {
    int i = 0;
    while(true) {
        if (message[i] == '\0') break;

        for(char p = 7; p >= 0; p--) {
            if (message[i] & (1 << p)) {
                signal(1, HIGHT);
            } else {
                signal(1, LOW);
            }
        }

        i++;
    }
}


uint16_t runAt = microseconds();
uint16_t loopTime = microseconds();

int main() {
    while(true) {

    }
}

