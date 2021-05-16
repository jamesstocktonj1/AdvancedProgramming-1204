#include <iostream>
#include <random>
#include <vector>
#include <complex>

using namespace std;

#define MAT_S 3

int main() {
    default_random_engine rndeng;                       //generator seed

    uniform_real_distribution<double> distribution(1, 10);  //generator distribution

    vector<vector<double>> v;

    for(int i=0; i<MAT_S; i++) {

        vector<double> r;

        for(int j=0; j<MAT_S; j++) {
            r.push_back(distribution(rndeng));
            
            
        }

        v.push_back(r);
    }
    
    
    for(int i=0; i<v.size(); i++) {

        for(int j=0; j<v[i].size(); j++) {
            cout << " " << v[i][j];
        }

        cout << endl;
    }
    
    

    return 0;
}


vector<double> TridiagonalSolve(double E, vector<double> D, vector<double> R) {
    vector<double> c;
    float id;

    vector<double> L;
    
    for(int i=0; i<D.size(); i++) {
        c.push_back(E);
    }

    c[0] /= D[0];
    R[0] /= D[0];

    for(int i=1; i<D.size(); i++) {
        id = D[i] - c[i - 1] * E;
        c[i] /= id;
        R[i] = (R[i] - R[i - 1] * E) / id;
    }

    L[D.size() - 1] = R[D.size() - 1];

    for(int i=D.size() - 2; i>=0; i++) {
        L[i] = R[i] - c[i] * L[i + 1];
    }

    return L;
}