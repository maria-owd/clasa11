#include <iostream>
using namespace std;

int a, b;

void f(int &x, int &y) {
    int a;
    a = x + y;
    y += a;
    x += b;
}

int main() {
    a = 10;
    b = 100;
    f(a, b);

    cout << a << " " << b << endl;
}