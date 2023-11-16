#include <iostream>
using namespace std;

void citire(int &n, int v[10]) {
    cout << "n = ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "nr " << i+1 << ": ";
        cin >> v[i];
    }
}

void afisare(int n, int v[10]) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int zero(int x) {
    int cifra, nr;

    if (x == 0) {
        return 1;
    }

    nr = 0;
    while (x > 0) {
        cifra = x % 10;
        x = x / 10;

        if (cifra == 0) {
            nr++;
        }
    }

    return nr;
}

void ordonare(int n, int v[10]) {
    int aux;
    bool ok;
    do {
        ok = true;
        for (int i = 0; i < n-1; i++) {
            if (zero(v[i+1]) < zero(v[i])) {
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;

                ok = false;
            }
        }
    } while (!ok);
}

int main () {
    int n, v[10];

    citire(n, v);
    afisare(n, v);
    ordonare(n, v);
    afisare(n, v);

    return 0;
}