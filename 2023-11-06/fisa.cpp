#include <iostream>
#include <fstream>

using namespace std;

void citire(int a[30][30], int &n) {
    ifstream f("date.in");
    f >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            f >> a[i][j];
        }
    }
}

void afisare(int a[30][30], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void s1(int a[30][30], int n, int &max) {

    max = a[0][0];
    for (int i = 0; i < n; i++) {
        if (a[i][i] > max) {
            max = a[i][i];
        }   
    }
}

int s2(int a[30][30], int n) {
    int suma;

    suma = 0;
    for (int i = 0; i < n; i++) {
        suma = suma + a[0][i] + a[n-1][i];
    }
    for (int i = 1; i < n-1; i++) {
        suma = suma + a[i][0] + a[i][n-1];
    }

    return suma;
}

int main () {
    int a[30][30], n, maxim;

    citire(a, n);
   // afisare(a, n);

    s1(a, n, maxim);
    cout << "Elementul maxim = " << maxim << endl;

    cout << "Suma = " << s2(a, n) << endl;

    return 0;
}