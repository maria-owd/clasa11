#include <iostream>
using namespace std;

void f(int a, int &b) {
    a++;
    b = a;
    b++;
}

void g(int &a, int b) {
    b++;
    a = b;
    a++;
}

int main() {
    int x = 4;
    int y = -2;
    f(x, y);
    g(x, y);
    cout << x << " " << y << endl;   
}