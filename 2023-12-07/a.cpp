#include <iostream>
using namespace std;

void f(int &a, int b) {
    int aux;
    aux = b;
    b = a;
    a = aux;

    cout << a << " " << b << endl;
}

int main () {
    int a, b;

    a = 5;
    b = 7;

    f(b,a);
    cout << a << " " << b << endl;

    f(a, b + 10);
    cout << a << " " << b << endl;

    return 0;
}