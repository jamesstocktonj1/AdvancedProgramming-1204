#include <iostream>

using namespace std;


bool AND(bool a, bool b);
bool OR(bool a, bool b);
bool XOR(bool a, bool b);

void printState(bool n);
void printBin(bool n);

bool readBit(void);

void halfAdder(bool a, bool b, bool &s, bool &c);
void fullAdder(bool a, bool b, bool Cin, bool &s, bool &c);


int main() {
    bool a, b, c, sum, carry;

    cout << "First Bit: ";
    a = readBit();

    cout << "Second Bit: ";
    b = readBit();

    cout << "Carry Bit: ";
    c = readBit();


    fullAdder(a, b, c, sum, carry);

    cout << "Sum: ";
    printBin(sum);

    cout << "Carry: ";
    printBin(carry);

    return 1;
}


void printState(bool n) {
    cout << ((n) ? "True" : "False") << endl;
}

void printBin(bool n) {
    cout << ((n) ? "1" : "0") << endl;
}

bool readBit() {
    char buf;
    cin >> buf;

    if(buf == '1') {
        return true;
    }
    else {
        return false;
    }
}






bool AND(bool a, bool b) {
    return a && b;
}

bool OR(bool a, bool b) {
    return a || b;
}

bool XOR(bool a, bool b) {
    return (a != b);
}


void halfAdder(bool a, bool b, bool &s, bool &c) {
    s = XOR(a, b);
    c = AND(a, b);
}

void fullAdder(bool a, bool b, bool Cin, bool &s, bool &c) {
    bool c1, c2, s1;

    halfAdder(a, b, s1, c1);
    halfAdder(Cin, s1, s, c2);
    c = OR(c1, c2);
}