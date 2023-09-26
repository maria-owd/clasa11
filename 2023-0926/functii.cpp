#include <iostream>
using namespace std;



int suma(int x1, int x2) {
    int s;
    s = x1 + x2;

    return s;
}

bool par(int x) {
    if (x % 2 == 0) {
        return true;
    } else {
        return false;
    }
}

bool prim(int x) {
    for (int i = 2; i <= x/2; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int a, b, c, d;

    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    cout << "suma = " << suma(a,b) << endl;

    cout << "a este par? " << par(a) << endl;
    cout << "b este par? " << par(b) << endl;

    cout << "a este prim? " << prim(a) << endl;

    cout << "c = ";
    cin >> c;
    cout << "d = ";
    cin >> d;

    cout << "suma = " << suma(c,d) << endl;
    cout << "c este par? " << par(c) << endl;
    cout << "d este par? " << par(d) << endl;

    return 0;
}