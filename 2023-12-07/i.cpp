#include <iostream>
using namespace std;

void f(int &x, int y, int &z) {
    x = y + z;
    y = x + z;
    z = x + y;
}

int main() {
    int x = 1;
    int y = 2;
    int z = 3;

    f(x, y, z);
    f(y, z, x);

    cout << x << " " << y << " " << z << endl;   
}