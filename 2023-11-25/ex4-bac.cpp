#include <iostream>
using namespace std;

int cif(int a, int b){
    int cifra, aparitie;

    aparitie = 0;
    while (a > 0) {
        cifra = a % 10;
        a = a / 10;

        if (cifra == b) {
            aparitie++;
        }
    }
    return aparitie;
}

int main() {
    int a, b;
    
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    cout << cif(a, b) << endl;

    // b)
    int n;
    int dr, st;
    int poz;
    int x;

    cout << "Un nr cu exact 8 cifre: ";
    cin >> n;
   
    dr = 0;
    st = 0;
    poz = 1;

    for (int cifra = 0; cifra <= 9; cifra++) {
        int aparitii;
        aparitii = cif(n, cifra);

        if (aparitii % 2 == 1) {
            st = 0;
            dr = 0;
            break;
        }

        for (int i = 0; i < aparitii/2; i++) {
            st = st * 10 + cifra;
            dr = dr + cifra * poz;
            poz = poz * 10;
        }
    }
    x = dr + st * poz;
    cout << x << endl;

    return 0;
}
