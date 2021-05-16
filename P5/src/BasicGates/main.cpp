#include <iostream>
#include <vector>
#include "LogicGates.cpp"

using namespace std;

#define N 8



void printBit(bool n);
bool readBit();

void printBin(vector<bool> ar);

vector<bool> readNum();
bool readSymbol();



int main() {
    vector<bool> a(N);
    vector<bool> b(N);
    vector<bool> c(N+1);
    vector<bool> s(N);

    bool isSub;         //sub or add => 1 if sub

    FullAdder fa;       //main addition full adder
    XOR sXOR;           //AND gate which flips bits of b if subtract

    cout << "Number A: ";
    a = readNum();

    cout << "Binary A: ";
    printBin(a);
    cout << "\n\n";


    cout << "Number B: ";
    b = readNum();

    cout << "Binary B: ";
    printBin(b);
    cout << "\n\n";


    cout << "Addition or Subtraction: ";
    isSub = readSymbol();

    cout << ((isSub) ? "Subtracting" : "Adding") << endl;



    c[0] = isSub;        //pre-load first carry in with nSub
    sXOR.a = isSub;      //load and with isSub to flip bits if isSub is 1

    for(int i=0; i<N; i++) {
        sXOR.b = b[i];

        fa.a = a[i];
        fa.b = sXOR.calculate();        //flips bit if isSub is false
        fa.cin = c[i];
        fa.calculate();

        c[i+1] = fa.cout;
        s[i] = fa.s;

    }

    cout << "\nAddition Result: ";
    printBin(s);

    cout << "\nCarry Bit: ";
    printBit(c[N]);

    return 0;
}






void printBit(bool n) {
    cout << ((n) ? "1" : "0");
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

vector<bool> readNum() {
    int num;
    vector<bool> temp;

    cin >> num;

    for(int i=0; i<N; i++) {
        temp.push_back(num % 2);
        num = num / 2;
    }

    return temp;
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

void printBin(vector<bool> ar) {

    for(int i=0; i<ar.size(); i++) {
        printBit(ar[(ar.size()-1) - i]);
    }
}