#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
int main () {
    int m, n;
    int a[100][100];
    int suma, maxim;

    ifstream f("date3.in");
    f >> m >> n;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            f >> a[i][j];
        }
    }

    cout << "matricea este: " << endl;
    for (int i = 0; i < m; i++) {
        cout << i << ": ";
        for (int j = 0; j < n; j++) {
            cout << setw(3) << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    maxim = a[0][0];
    for (int i = 0; i < m-1; i++) {
        for (int j = 0; j < n-1; j++) {
            suma = a[i][j] + a[i+1][j] + a[i][j+1] + a[i+1][j+1];
            
            if (suma > maxim) {
                maxim = suma;
            }
        }
    }
    cout << "suma maxima: " << maxim << endl;

    return 0;
}