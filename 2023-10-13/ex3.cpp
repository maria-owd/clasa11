#include <iostream>
using namespace std;

bool prim(int a) {
    if (a == 0 || a == 1) {
        return false;
    }
    for (int i = 2; i <= a/2; i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

int produs (int n) {
    int produs;

    produs = 1;
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0 && prim(i)) {
            produs = produs * i; 
        }
    }

    return produs;
}

int main () {
    int a, b, c;

    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;

    if (produs(a) == produs(b) && produs(a) == produs(c)) {
        cout << "DA" << endl;
    } else {
        cout << "NU" << endl;
    }

    return 0;
}