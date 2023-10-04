#include <iostream>
using namespace std;

int nrCif(int &n, int a /* locale, in functie, INITIALIZATE!!*/) {
    int nr, cifra; // locale -> in funcitie
    cout << "sunt in nrCif, n=" << n << ", a=" << a << endl;
    
    nr = 0;
    while (n > 0) {
        cifra = n%10;
        nr++;
        n = n/10;
        a--;
    }

    cout << "ies din nrCif, n=" << n << ", a=" << a << endl;
    return nr;
}

int main() {
    int n; // main;
    int x; // main

    n = 765;
    x = 100;
    
    //cout << nrCif(12345, 8) << endl;

    cout << "1: sunt in main, n=" << n << ", x=" << x << endl;

    cout << nrCif(n, 6) << endl;

    cout << "2: sunt in main, n=" << n << ", x=" << x << endl;

    return 0;
}