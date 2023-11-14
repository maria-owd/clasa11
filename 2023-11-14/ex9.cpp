#include <iostream>
using namespace std;

int sub(int x) {
    int cifra, a, poz;

    poz = 1;
    a = 0;
    while (x > 9) {
        cifra = x % 10;
        x = x / 10;

        a = a + cifra * poz;
        poz = poz * 10;
    }
    a = a * 10 + x;

    return a;
}

void dreapta(int x, int &a) {
    int cifra, prima, poz;

    poz = 1;
    a = 0;

    prima = x % 10;
    x = x / 10;
    while (x > 0) {
        cifra = x % 10;
        x = x / 10;

        a = a + cifra * poz;
        poz = poz * 10;
    }
    a = prima * poz + a;
}

int main () {
    int x, copie;
    int a;

    cout << "x = ";
    cin >> x;

    copie = x;
    
    cout << endl << "stanga" << endl;

    x = sub(x);
    while (x != copie) {   
        cout << x << endl;
        x = sub(x);
    }
    
    cout << endl << "dreapta" << endl;

    x = copie;
    dreapta(x, a);
    while (a != x) {   
        cout << a << endl;

        dreapta(a, a);
    }

    return 0;
}