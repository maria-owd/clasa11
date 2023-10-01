#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

    int n;
    int a[100][100];
    int b[100][100];
    int c[100][100];

    int x[100][100];



void afiseaza(const char* nume, int m[100][100]) {

    cout << nume << ": " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(3) << m[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

}

int main () {


    ifstream f("A.in");
    f >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            f >> a[i][j];
        }
    }

    afiseaza("A", a);

    ifstream g("B.in");
    g >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g >> b[i][j];
        }
    }

    afiseaza("B", b);

/*
    ifstream h("C.in");
    h >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            h >> c[i][j];
        }
    }
    afiseaza("C", c);

    //--- calcul
    int k = 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            x[i][j] = (c[i][j] - a[i][j])/k;
        }
    }
    afiseaza("k=2  (C-A)/2", x);
*/

    //--- A*B
    int k = 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            x[i][j] = 0;
            for (int k=0; k <n; k++) {
                x[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    afiseaza("A*B", x);
    return 0;
}