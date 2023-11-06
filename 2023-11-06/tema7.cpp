#include <iostream>
#include <fstream>

using namespace std;

void s1(int a[30][30], int &m, int &n) {
    ifstream f("date.in");
    f >> m >> n;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            f >> a[i][j];
        }
    }
}

void afisare(int a[30][30], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int s2(int a[30][30], int n, int k) {
    int suma;

    suma = 0;
    for (int i = 0; i < n; i++) {
        suma = suma + a[k][i];
    }

    return suma;
}

int main () {
    int a[30][30], m, n;
    int maxim, s, linie;

    s1(a, m, n);
    //afisare (a, m, n);

    maxim = a[0][0];
    linie = 0;
    for (int i = 0 ; i < m; i++) {
        s = s2(a, n, i);

        if (s > maxim) {
            maxim = s;
            linie = i;
        }
    }

    cout << linie + 1 << " " << maxim << endl;

    return 0;
}