#include <iostream>
#include <string>
#include <vector>

int onboard_led = D7; //this reference only works in arduino-type environments
int button = D3;

using namespace std;

class Morse {
public:
    std::vector<int> A = { 0, 1 };
    std::vector<int> B = { 1, 0, 0, 0 };
    std::vector<int> C = { 1, 0, 1, 0 };
    std::vector<int> D = { 1, 0, 1 };
    std::vector<int> E = { 0};
    std::vector<int> F = { 0, 0, 1, 0 };
    std::vector<int> G = { 1, 1, 0 };
    std::vector<int> H = { 0, 0, 0, 0 };
    std::vector<int> I = { 0, 0 };
    std::vector<int> J = { 0, 1, 1, 1 };
    std::vector<int> K = { 1, 0, 1 };
    std::vector<int> L = { 0, 1, 0, 0 };
    std::vector<int> M = { 1, 1 };
    std::vector<int> N = { 1, 0 };
    std::vector<int> O = { 1, 1, 1 };
    std::vector<int> P = { 0, 1, 1, 0 };
    std::vector<int> Q = { 1, 1, 0, 1 };
    std::vector<int> R = { 0, 1, 0 };
    std::vector<int> S = { 0, 0, 0 };
    std::vector<int> T = { 1 };
    std::vector<int> U = { 0, 0, 1 };
    std::vector<int> V = { 0, 0, 0, 1 };
    std::vector<int> W = { 0, 1, 1 };
    std::vector<int> X = { 1, 0, 0, 1 };
    std::vector<int> Y = { 1, 0, 1, 1 };
    std::vector<int> Z = { 1, 1, 0, 0 };
    int dash = 3000;
    int dot = 1000;
    int space = 1000;
    int led;
    std::string name;
    Morse(std::string name, int led)
    {
        this->name = name;
        this->led = led;
    }
    void blink_string()
    {
        for (int i = 0; i < this->name.size(); ++i)
        {
            if (toupper(this->name[i]) == 'A') { read_sequence(A); }
            else if (toupper(this->name[i]) == 'B') { read_sequence(B); }
            else if (toupper(this->name[i]) == 'C') { read_sequence(C); }
            else if (toupper(this->name[i]) == 'D') { read_sequence(D); }
            else if (toupper(this->name[i]) == 'E') { read_sequence(E); }
            else if (toupper(this->name[i]) == 'F') { read_sequence(F); }
            else if (toupper(this->name[i]) == 'G') { read_sequence(G); }
            else if (toupper(this->name[i]) == 'H') { read_sequence(H); }
            else if (toupper(this->name[i]) == 'I') { read_sequence(I); }
            else if (toupper(this->name[i]) == 'J') { read_sequence(J); }
            else if (toupper(this->name[i]) == 'K') { read_sequence(K); }
            else if (toupper(this->name[i]) == 'L') { read_sequence(L); }
            else if (toupper(this->name[i]) == 'M') { read_sequence(M); }
            else if (toupper(this->name[i]) == 'N') { read_sequence(N); }
            else if (toupper(this->name[i]) == 'O') { read_sequence(O); }
            else if (toupper(this->name[i]) == 'P') { read_sequence(P); }
            else if (toupper(this->name[i]) == 'Q') { read_sequence(Q); }
            else if (toupper(this->name[i]) == 'R') { read_sequence(R); }
            else if (toupper(this->name[i]) == 'S') { read_sequence(S); }
            else if (toupper(this->name[i]) == 'T') { read_sequence(T); }
            else if (toupper(this->name[i]) == 'U') { read_sequence(U); }
            else if (toupper(this->name[i]) == 'V') { read_sequence(V); }
            else if (toupper(this->name[i]) == 'W') { read_sequence(W); }
            else if (toupper(this->name[i]) == 'X') { read_sequence(X); }
            else if (toupper(this->name[i]) == 'Y') { read_sequence(Y); }
            else if (toupper(this->name[i]) == 'Z') { read_sequence(Z); };
            
        }
    }
    void read_sequence(std::vector<int> sequence )
    {
        for (int i = 0; i < sequence.size(); ++i)
        {
            if (sequence[i] == 1) { blink(this->dash); }
            else { blink(this->dot); }
        }
    }
    void blink(int time_delay)
    {
        digitalWrite(this->led, HIGH);
        delay(time_delay);
        digitalWrite(this->led, LOW);
        delay(this->space);
    }
};

void setup() {
    pinMode(onboard_led, OUTPUT);
    pinMode(button, INPUT_PULLUP);
}

void loop() {
    int buttonState = digitalRead( button );
    std::string my_name = "Jarrod";
    Morse m(my_name, onboard_led);
    while(buttonState != LOW){
        m.blink_string();
    }
}

