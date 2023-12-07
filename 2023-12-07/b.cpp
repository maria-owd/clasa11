#include <iostream>
using namespace std;

void f(int &a, int b, int &c) {
    a = a + 2;
    b = b - 10;
    c = a + b;
    cout << a << " " << b << " " << c << endl;
}

int main() {
    int x = 5;
    int y = 2;
    int z = 10;
    
    f(x, x, x);
    cout << x << " " << y << " " << z << endl;
    
    f(z, z, z);
    cout << x << " " << y << " " << z << endl;
    
    f(y, y, y);
    cout << x << " " << y << " " << z << endl;
}