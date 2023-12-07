#include <iostream>
using namespace std;

int a, b;

void f(int &x, int &y) {
    y = y + 2;
    x = x + y;
}

int main() {
    int x = 2;
    f(x, x);
    cout << x << endl;
}