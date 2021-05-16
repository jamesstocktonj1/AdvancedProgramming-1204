#include <iostream>
#include <cmath>
#include "ComplexNumbers.cpp"
//#include "SeriesRLC.cpp"

using namespace std;



int main() {
    float r, l, c, vm, va, freq, angv;


    cout << "Resistance (R): ";
    cin >> r;

    cout << "Inductance (H): ";
    cin >> l;

    cout << "Capacitance (F): ";
    cin >> c;
    


    cout << "Voltage Magnitude (V): ";
    cin >> vm;

    cout << "Voltage Phase (degrees): ";
    cin >> va;

    cout << "Circuit Frequency: ";
    cin >> freq;


    angv = 2 * M_PI * freq;

    Comp R(r);
    Comp L(0.0, l * angv);
    Comp C(0.0, 1 / (c * angv));


    Polar V(vm, (va * M_PI) / 180);
    Polar I;


    RLC circuit(R, L, C, V);

    I = circuit.calculateCurrent();

    I.printNumber();


    return 0;
}




/*
Comp calculateImpedance(Comp r, Comp l, Comp c, int freq) {

    int ang = 2 * M_PI * freq;

    l = l * ang;
    c = c * ang;

    return r + (l - c);
}*/







/*
[2:08 PM] Xinyu Feng
#include <iostream>
#include "Complex.h"

int main(){​​​​​
    //create some complex numbers
    Complex unity(1,0), one_of_each(1,1), one_imag(0,-1);
    cout << "1 is :" << endl;
    print_complex(unity);
    cout << "1 + i is :" << endl;
    print_complex(one_of_each);
    cout << "i is :" << endl;
    print_complex(one_imag);

    cout << "1*(i) is :" << endl;
    print_complex(unity*one_imag);
    cout << "1/(i) is :" << endl;
    print_complex(unity/one_imag);

    Complex ones_with_new_arg = one_of_each;
    ones_with_new_arg.setArg(3*PI/4);
    cout << "1 + i but with an arg of 3pi/4 is :" << endl;
    print_complex(ones_with_new_arg);
    ones_with_new_arg.setArg(3*PI/2);
    cout << "1 + i but with an arg of 3pi/2 is :" << endl;
    print_complex(ones_with_new_arg);
}​​​​​

Use similiar code program to check your complex class and complex function in 3.1
*/


