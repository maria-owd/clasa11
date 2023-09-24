#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
int main () {

    int n, a[100][100];
    int pare, cifra, suma;

    ifstream f("date2.in");
    ofstream g("date.out");
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
            cout << setw (4) << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "a) ";
    for (int i = 0; i < n; i++) {
        cout << a[i][n-1] << " ";    
    }
    cout << endl;

    cout << "b) ";
    pare =  0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + j < n-1) {
                if (a[i][j] % 2 == 0) {
                    pare++;
                }
            }
        }
    }
    cout << pare << endl;
    
    cout << "c) ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            suma = 0;
            while (a[i][j] > 0) {
                cifra = a[i][j] % 10;
                suma = suma + cifra;
                a[i][j] = a[i][j] / 10;
            }
            a[i][j] = suma;
        }
    }
   
    cout << "noua matrice este: " << endl;
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int j = 0; j < n; j++) {
            cout << setw (4) << a[i][j] << " ";
            g << setw (4) << a[i][j] << " ";
        }
        cout << endl;
        g << endl;
    }
    cout << endl;

    return 0;
}