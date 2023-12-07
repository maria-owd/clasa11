#include <iostream>
using namespace std;

int a1(int a, int &b) {
    a = 2 * a;
    b = b - a;
    return a + b;
}

int a2(int &a, int &b) {
    int m = a - b;
    a = b;
    b = b + a;
    return m;
}

int main() {
    int x = 3;
    int y = 5;
    x = a1(x, y);
    y = a2(y, x);

    cout << x << " " << y << endl;   
}