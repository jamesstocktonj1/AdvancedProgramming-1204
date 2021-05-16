#include <iostream>
#include <math.h>

using namespace std;



#define N 4


bool AND(bool a, bool b);
bool OR(bool a, bool b);
bool XOR(bool a, bool b);

void printState(bool n);
void printBin(bool n);
void printByte(bool *n);


bool readBit(void);
void readNum(bool *bin);
bool readSymbol(void);

void halfAdder(bool a, bool b, bool &s, bool &c);
void fullAdder(bool a, bool b, bool Cin, bool &s, bool &c);
void fourBitAdder(bool *a, bool *b, bool *s, bool *c);


void convertTwosComplement(bool *bin);




int main() {
    bool a[N];
    bool b[N];
    bool acc[N];

    bool sum[8] = {false, };
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


    //initially load the accumulation
    sum[0] = AND(b[0], a[0]);
    for(int i=0; i<N-1; i++) {
        acc[i] = AND(a[i+1], b[0]);
    }
    acc[N-1] = false;


    for(int i=1; i<N; i++) {

        
        for(int j=0; j<N; j++) {
            fullAdder(acc[j], AND(a[j], b[i]), false, acc[j], carry);
        }
        
        sum[i] = acc[0];
        acc[0] = acc[1];
        acc[1] = acc[2];
        acc[2] = acc[3];
        acc[3] = carry;
    }

    sum[4] = acc[0];
    sum[5] = acc[1];
    sum[6] = acc[2];
    acc[7] = acc[3];

    cout << "Multiplication: ";
    for(int i=1; i<=8; i++) {
        printBin(sum[N - i]);
    }
    cout << endl;

    cout << "Carry: ";
    printBin(carry);

    
    

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

//modified for 2s complement
void readNum(bool *bin) {
    int num;

    cin >> num;

    for(int i=0; i<N; i++) {
        bin[i] = num % 2;
        num = num / 2;
    }
}

bool readSymbol() {
    char sym;

    cin >> sym;

    if(sym == '-') {
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

/*
void fourBitAdder(bool *a, bool *b, bool *s, bool c) {
    bool ct[5] = {false, };

    for(int i=0; i<4; i++) {
        fullAdder(a[i], b[i], ct[i], s[i], ct[i+1]);
    }
}*/