#include <iostream>
#include <cmath>
#include "ComplexNumbers.cpp"

using namespace std;



int main() {
    Comp n(5, 12);
    Comp m(2, 1);
    Comp x(1, 1);

    cout << "Original Value n: ";
    n.printNumber();

    cout << "Original Value m: ";
    m.printNumber();
    cout << endl;


    x = n + m;
    cout << "n + m: ";
    x.printNumber();

    x = n + 5;
    cout << "n + 5: ";
    x.printNumber();
    cout << endl;


    x = n - m;
    cout << "n - m: ";
    x.printNumber();

    x = n - 5;
    cout << "n - 5: ";
    x.printNumber();
    cout << endl;


    x = n * m;
    cout << "n * m: ";
    x.printNumber();

    x = n * 5;
    cout << "n * 5: ";
    x.printNumber();
    cout << endl;


    x = n / m;
    cout << "n / m: ";
    x.printNumber();

    x = n / 5;
    cout << "n / 5: ";
    x.printNumber();
    cout << endl;




    return 0;
}





Comp calculateImpedance(Comp r, Comp l, Comp c, int freq) {

    int ang = 2 * M_PI * freq;

    l = l * ang;
    c = c * ang;

    return r + (l - c);
}







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


