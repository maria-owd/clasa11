#include <iostream>
#include <fstream>

using namespace std;

// prima cifra a unui numar
int cifra(int n) {
    while (n > 9) {
        n = n/10;
    }
    return n;
}

bool verifica(int x) {
    int copie, cifra, ogl;

    copie = x;
    ogl = 0;
    while (x > 0) {
        cifra = x % 10;
        x = x / 10;
        ogl = ogl * 10 + cifra;
    }

    return ogl == copie;
}


int main() {
    int n, a, x;

    ifstream f("numar.in");
    f >> n;

    x = 0;
    for (int i = 0; i < n; i++) {
        f >> a;
        x = x * 10 + cifra(a);
    }

    cout << x << endl;

    if (verifica(x)) {
        cout << "numarul " << x << " este palindrom" << endl;
    } else {
        cout << "numarul " << x << " nu este palindrom" << endl;
    }

    return 0;
}