#include <iostream>
#include <fstream>
using namespace std;

ifstream f("date.in");


void citire(int v[10], int k, int p) {
    if (k < p) {
        f >> v[k];
        citire(v, k+1, p);
    }
} 

void afisare(int v[10], int k, int p) {
    if (k < p) {
        //-----
        cout << "v[" << k << "] = " << v[k] << endl; 
        //-----
        afisare(v, k+1, p);
    }
}

int nrElemente(int v[10], int k, int p) {
    int numar = 0;
    if (k < p) {
        // ------
        if(v[k] >= 10 && ((v[k] / 10) % 10) % 2 == 0) {
            numar = 1;
        }
        // ----
        numar = numar + nrElemente(v, k+1, p);
    }
    return numar;
}

// divizori(v[k], 1)
int divizori(int x, int d) {
    int nr;

    if (x == 0) {
        return 0;
    }
    if (d > x) {
        return 0;
    }
    if (x % d == 0) {
        nr = 1; 
    } else {
        nr = 0;
    }
    return nr + divizori(x, d+1);
}

int sumaDivi(int v[10], int k, int p) {
    int numar = 0;
    if (k < p) {
        //----
        if(divizori(v[k], 1) % 2 == 0) {
            numar = v[k];
        }
        //----
        numar = numar + sumaDivi(v, k+1, p);
    }
    return numar;
}

int main() {
    int n;
    int vec[10];

    f >> n;
    cout << "n = " << n << endl;

    citire(vec, 0,n);
    cout << "Elementele vectorului: " << endl;
    afisare(vec,0, n);

    cout << "Numarul elementelor cu minim 2 cifre, cu cifra zecilor para: " << nrElemente(vec, 0, n) << endl;
    cout << "Suma elementelor cu nr par de divizori: " << sumaDivi(vec, 0, n) << endl;
    return 0;
}