#include <iostream>
#include <random>

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


