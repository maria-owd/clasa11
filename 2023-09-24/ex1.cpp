#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
int main () {

    int n, v[100];
    int rang, minim, divi;
    bool prim;

    ifstream f("date1.in");
    ofstream g("date.out");
    f >> n;

    for (int i = 0; i < n; i++) {
        f >> v[i];
    }

    cout << "a) ";
    for (int i = 0; i < n; i++) {
        rang = (v[i]/10) % 10;
        cout << rang << " ";
    }
    cout << endl;

    cout << "b) ";
    minim = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] < minim) {
            minim = v[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (v[i] == minim) {
            cout << i+1 << endl;
            i = n;
        }
    }

    cout << "c) ";
    prim = false; 
    for (int i = 0; i < n; i++) {
        if (v[i] >= 100 && v[i] <= 999) {
            divi = 0;
            for (int k = 2; k <= v[i]/2; k++) {
                if (v[i] % k == 0) {
                    divi++;
                }
            }
        
            if (divi == 0) {
                cout << v[i] << " ";
                g << v[i] << " ";
                prim = true;
            } 
        }
    }
    if (!prim) {
        cout << "NU EXISTA NUMERE PRIME DE TREI CIFRE" << endl;
        g << "NU EXISTA NUMERE PRIME DE TREI CIFRE" << endl;
    }
    cout << endl;

    return 0;
}