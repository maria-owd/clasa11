#include <iostream>
#include <fstream>
using namespace std;

/**
 * Se citeste din fiserul linie.in o matrice patratica.
 * O functie care afiseaza:
 *  a) linia cu cele mai multe elemnte prime 
 *  b) pe a doua linie se vor afisa elemntele principale ale matricii
 */

int a[5][5], v[5], n;

bool prim (int a) {
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


void nrPrim (int l) {
    v[l] = 0;
    for (int i = 0; i < n; i++) {
        if (prim(a[l][i])) {
            v[l]++;
        }
    }
}

int main() {
    int maxim, linieMax;

    ifstream f("linie.in");
    f >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            f >> a[i][j];
        }
    }

    maxim = 0;
    linieMax = -1;
    for (int i = 0; i < n; i++) {
        nrPrim(i);
        if (v[i] > maxim) {
            maxim = v[i];
            linieMax = i;
        }
    }

    if (linieMax >= 0) {
        cout << linieMax + 1 << endl;
    } else {
        cout << "nu exista elemente prime" << endl;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i][i] << " ";
    }
    cout << endl;

    return 0;
}