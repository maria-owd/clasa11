#include <iostream>
using namespace std;

/**
* functia s1 afiseaza numarul de cifre ale parametrului n
*/

int s1(int n) {
    int nr;

    nr = 0;
    while (n > 0) {
        n = n / 10;
        nr++;
    }
    return nr;
}

/**
* functia s2 afiseaza numarul de cifre ale parametrului n
*/

void s2(int &n, int k) {
    int copie, cifra, x;
    int poz;

    copie = n;
    x = 0;
    poz = 1;
    while (n > 0) {
        cifra = n % 10;
        n = n / 10;

        if (cifra == k) {
            x = x + cifra * poz;
            poz = poz * 10;
        } 
        x = x + cifra * poz;
        poz = poz * 10;
    }
    n = x; 
}

int main() {
    int n, a, b;

   //cout << "n = ";
   // cin >> n;
    n = 121532;
    a = 3;
    b = 2;

    int cifreInitiale;
    int cifreFinale;

    cifreInitiale = s1(n);
    s2(n, a);
    s2(n, b);
    cifreFinale = s1(n);

    cout << cifreFinale - cifreInitiale << endl;
    
    return 0;
}