#include <iostream>
using namespace std;

void f1(int &x, int &y) {
    x = 1;
    y = 2;
}

void f2(int &x, int &y) {
    y = 2;
    x = 1;
}

int main() {
    int z;
    f1(z, z);
    cout << z << endl;
    
    f2(z, z);
    cout << z << endl;   
}