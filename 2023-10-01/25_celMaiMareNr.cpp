#include <iostream>
using namespace std;

int cmmnr(int n) {
    int cifra, nrCifre;
    int v[7];
    bool ok;

    nrCifre = 0;
    while (n > 0) {
        cifra = n%10;
        v[nrCifre] = cifra;
        n = n/10;
        nrCifre++;
    }

    do {
        ok = true;
        for (int i = 0; i < nrCifre - 1; i++) {
            if (v[i] < v[i+1]) {
                int aux;
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                ok = false;
            }
        }
    } while (!ok);

    n = 0;
    for (int i = 0; i < nrCifre; i++) {
        n = n*10 + v[i];
    }

    return n;
}

int main() {
    cout << cmmnr(1234) << endl;
    cout << cmmnr(35410) << endl;
    return 0;
}