#include <iostream>
#include <math.h>

using namespace std;



#define N 8


bool AND(bool a, bool b);
bool OR(bool a, bool b);
bool XOR(bool a, bool b);

void printState(bool n);
void printBin(bool n);
void printByte(bool *n);

bool readBit(void);
void readNum(bool *bin);

void halfAdder(bool a, bool b, bool &s, bool &c);
void fullAdder(bool a, bool b, bool Cin, bool &s, bool &c);




int main() {
    bool a[N];
    bool b[N];
    bool c[N + 1] = {false, };

    bool sum[N];
    bool carry;



    cout << "Input number 1: ";
    readNum(a);
    cout << "Number 1: ";
    printByte(a);
    cout << endl;


    cout << "Input number 2: ";
    readNum(b);
    cout << "Number 2: ";
    printByte(b);
    cout << endl;

    cout << "Input Carry: ";
    c[0] = readBit();


    for(int i=0; i<N; i++) {
        fullAdder(a[i], b[i], c[i], sum[i], c[i+1]);
    }

    cout << "\n\nSum: ";
    printByte(sum);
    cout << endl;

    cout << "Carry: ";
    printBin(c[N]);
    cout << endl;

    return 1;
}


void printState(bool n) {
    cout << ((n) ? "True" : "False") << endl;
}

void printBin(bool n) {
    cout << ((n) ? "1" : "0");
}

void printByte(bool *n) {

    for(int i=1; i<=N; i++) {
        printBin(n[N - i]);
    }
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

void readNum(bool *bin) {
    int num;

    cin >> num;

    for(int i=0; i<N; i++) {
        bin[i] = num % 2;
        num = num / 2;
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