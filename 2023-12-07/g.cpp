#include <iostream>
using namespace std;

void suma(int a, int b, int &s) {
    s = a + b;
}

void test(int &x, int &y) {
    suma(x, y, x);
    suma(x, -y, y);
    suma(x, -y, x);
}

int main() {
    int a = 253;
    int b = 23;
    test(a, b);
    
    cout << a << " " << b << endl;   
}