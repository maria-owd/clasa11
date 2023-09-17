#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

/**
 * Cititi din date.in o matrice patratica - ce contine nr. nat
 * Afisati: 
 *         matricea.
 *         elementele de pe diagonala secundara
 * Inlocuiti toate elemntele pare cu nr. lor de divizori --> afisati
 */
int main () {
    int n;
    int a[100][100];
    int divi;

    ifstream f("date2.in");
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
            cout << setw(3) << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "diagonala secundara: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i+j == n-1) {
                cout << a[i][j] << " ";
            }
        }
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 == 0) {
                divi = 0;
                for (int k = 1; k <= a[i][j]; k++) {
                    if (a[i][j] % k == 0) {
                        divi++;
                    }
                }
                a[i][j] = divi;
            }

        }
    }

    cout << endl << "noua matrice este: " << endl;
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int j = 0; j < n; j++) {
            cout << setw(3) << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}