#include <iostream>
#include <fstream>

using namespace std;

#define BUF_SIZE 100

char buf[BUF_SIZE];

int main() {
    ifstream file;
    file.open("test.txt");

    char c;

    file >> c;
    cout << c << endl;

    for(int i=0; file >> c; i++) {
        buf[i] = c;
    }

    cout << buf << endl;

    file.close();
}






