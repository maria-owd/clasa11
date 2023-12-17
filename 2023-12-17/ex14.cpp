#include <iostream>
#include <fstream>
using namespace std;

int semn(float x) {
    if (x < 0) {
        return -1;
    }
    if(x == 0) {
        return 0;
    }
    return 1; 
}

void sortare(float a[100], int n) {
    float aux;
    bool ok;

    do {
        ok = true; // optimist (cred ca va fi sortat ok)

        for (int i = 0; i < n-1; i++) {       
            if (semn(a[i]) > semn(a[i+1])) {   // conditia "gresita" de sortare
                aux = a[i];
                a[i] = a[i+1];
                a[i+1] = aux;

                ok = false; // nu a fost sortat ok
            }
        }
    } while (!ok);
}

void afisare(float a[100], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main () {
    float a[100];
    int n;

    ifstream f("date.in");
    f >> n;

    for (int i = 0; i < n; i++) {
        f >> a[i];
    }

    afisare(a, n);
    sortare(a, n);
    afisare(a, n);

    return 0;
}