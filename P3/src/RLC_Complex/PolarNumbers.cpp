#include <iostream>
//#include "ComplexNumbers.cpp"

using namespace std;







class Polar {

    public:
    Polar() {
        radius = 0.0;
        angle = 0.0;
    }

    Polar(float r, float o) {
        radius = r;
        angle = o;
    }

    Polar operator= (const Comp &n) {
        radius = sqrt((n.re * n.re) + (n.im * n.im));
        angle = atan(n.im / n.re);
    }


    void printNumber(void) {
        cout << radius << ", " << angle << "r" << endl;
    }

    float radius;
    float angle;
};