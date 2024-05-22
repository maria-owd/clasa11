#include <iostream>
#include <fstream>
using namespace std;

ifstream f("date.in");
int v[10];
void citire(int k, int p) {
    if (k < p) {
        f >> v[k];
        citire(k+1, p);
    }
} 

void afisare(int k, int p) {
    if (k < p) {
        cout << "v[" << k << "] = " << v[k] << endl; 
        afisare(k+1, p);
    }
}

int nrElemente(int k, int p) {
    int numar = 0;
    if (k < p) {
        if(v[k] >= 10 && ((v[k] / 10) % 10) % 2 == 0) {
            numar = 1;
        }
        numar = numar + nrElemente(k+1, p);
    }
    return numar;
}

int divizori(int x, int d) {
    int nr;

    if (x == 0) {
        return 0;
    }
    if (x == 1) {
        return 1;
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

int sumaDivi(int k, int p) {
    int numar = 0;
    if (k < p) {
        if(divizori(v[k], 1) % 2 == 0) {
            numar = v[k];
        }
        numar = numar + sumaDivi(k+1, p);
    }
    return numar;
}

int main() {
    int n;
    f >> n;
    cout << "n = " << n << endl;

    citire(0,n);
    cout << "Elementele vectorului: " << endl;
    afisare(0, n);

    cout << "Numarul elementelor cu minim 2 cifre, cu cifra zecilor para: " << nrElemente(0, n) << endl;
    cout << "Suma elementelor cu nr par de divizori: " << sumaDivi(0, n) << endl;
    return 0;
}