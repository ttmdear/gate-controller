class Receiver {
private:
    bool sample;
    
public:
    void loop();
}

Receiver receiver;

void setup() {

}

void loop() {
    receiver.loop();
}
