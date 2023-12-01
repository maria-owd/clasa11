#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void elimColoana (int n, int a[100][100], int k) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= k) {
                a[i][j] = a[i][j+1];
            }
        }
    }
}

int cifreImpare(int x) {
    while (x > 0) {
        if ((x % 10) % 2 == 0) {
            return 0;
        }
        x = x / 10;
    }
    return 1;
}

int main () {
    int n, a[100][100], k;
    int x;

    ifstream f("atestat.in");
    f >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            f >> a[i][j];
        }
    }

    cout << "matricea: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(5) << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // c)
    int impare;
    bool eliminat;

    eliminat = false;

    for (int j = 0; j < n; j++) {
        impare = 0;
        for (int i = 0; i < n; i++) {
            if (cifreImpare(a[i][j])) {
                impare++;
            }
        }
        if (impare == j+1) {
            elimColoana(n, a, j);
            eliminat = true;
            break;
        }
    }

    if (eliminat) {
        cout << "matricea: " << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n-1; j++) {
                cout << setw(5) << a[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    } else {
        cout << "matrice nemodificata" << endl;
    }

    return 0;
}