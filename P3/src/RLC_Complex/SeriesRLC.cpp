#include <iostream>
#include "ComplexNumbers.cpp"



using namespace std;


class RLC {
    public:

    RLC(Comp res, Comp ind, Comp cap, Polar volt) {
        r = res;
        l = ind;
        c = cap;
        v = volt;
    }

    Polar calculateCurrent() {
        Comp xt, ic, vc;
        Polar i;


        xt = r + (l - c);           //calculate impedence
        vc = v.toComplex();                     //convert V to complex form

        ic = vc / xt;               //I = V / Z
        i = ic;                     //convert I to polar form

        return i;
    }

    private:
    Comp r, l, c;
    Polar v;
};