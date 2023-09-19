#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
int main () {
    int n;
    int a[100][100];
    int suma, nrCifra, min, max;

    ifstream f("date1.in");
    f >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            f >> a[i][j];
        }
    }

    cout << "matricea este: " << endl;
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int j = 0; j < n; j++) {
            cout << setw(6) << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                nrCifra = 0;

                while (a[i][j] > 0) {
                    nrCifra++;
                    a[i][j] = a[i][j]/10;
                }
                a[i][j] = nrCifra;
            }
        }
    }
    cout << endl;

    cout << "noua matrice este: " << endl;
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int j = 0; j < n; j++) {
            cout << setw(6) << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    min = a[0][0];
    max = a[n-1][n-1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + j < n-1) {              // deasupra ds
                if (a[i][j] < min) {
                    min = a[i][j];
                }
            } 
            if (i + j > n - 1) {
                if (a[i][j] > max) {        // sub ds
                    max = a[i][j];
                }
            }
        }
    }
    suma = min + max;
    cout << "minim + maxim = " << min<< " + " << max << " = " << suma << endl;

    nrCifra = 0;  // nr de cifre
    while (suma > 0) {
        if ((suma % 10) % 2 == 0) {
            nrCifra++;
        }
       suma = suma/10; 
    }

    if (nrCifra % 2 == 0) {
        cout << "suma are număr par de cifre pare" << endl;
    } else {
        cout << "suma are număr impar de cifre pare" << endl;
    }

    return 0;
}