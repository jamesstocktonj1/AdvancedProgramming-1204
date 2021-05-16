#include <iostream>

using namespace std;


bool AND(bool a, bool b);
bool OR(bool a, bool b);
bool XOR(bool a, bool b);

bool NAND(bool a, bool b);
bool NOR(bool a, bool b);
bool NOT(bool a);

void printState(bool n);
void printBin(bool n);

void halfAdder(bool a, bool b, bool &s, bool &c);


int main() {
    bool a = false;
    bool b = false;

    bool c;

    c = AND(a, b);
    cout << "AND: ";
    printState(c);

    c = OR(a, b);
    cout << "OR: ";
    printState(c);

    c = XOR(a, b);
    cout << "XOR: ";
    printState(c);


    c = NAND(a, b);
    cout << "NAND: ";
    printState(c);

    c = NOR(a, b);
    cout << "NOR: ";
    printState(c);
}


void printState(bool n) {
    cout << ((n) ? "True" : "False") << endl;
}

void printBin(bool n) {
    cout << ((n) ? "1" : "0") << endl;
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

bool NAND(bool a, bool b) {
    return NOT(AND(a, b));
}

bool NOR(bool a, bool b) {
    return NOT(OR(a, b));
}

bool NOT(bool a) {
    return !a;
}


void halfAdder(bool a, bool b, bool &s, bool &c) {
    s = XOR(a, b);
    c = AND(a, b);
}