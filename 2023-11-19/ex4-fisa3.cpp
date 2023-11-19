#include <iostream>
using namespace std;

// a)
int cifraMini(int n) {
    int cifra, minim;

    minim = 10;
    while (n > 0) {
        cifra = n % 10;
        if (cifra < minim) {
            minim = cifra;
        }
        n = n / 10;
    }
    return minim;
}

// b)
void P(int a, int b) {
    int aux;
    if (b < a) {
        aux = b;
        b = a;
        a = aux;
    }
    for (int i = a; i <= b; i++) {
        cout << i << " ";
    }
    cout << endl;
}

int main () {
    int n;
    int a, b;

    cout << "n = ";
    cin >> n;
    cout << cifraMini(n) << endl;

    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    P(a, b); 

    return 0;
}