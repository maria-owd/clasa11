#include <iostream>
using namespace std;

/**
 * Subprogramul Impare are un parametru, n, prin care primește un număr natural
 * Subprogramul returnează numărul obținut prin 
 *  duplicarea fiecărei cifre impare a lui n 
 *  sau -1 dacă acesta nu are nicio cifră impară. 
 * Scrieți definiția completă a subprogramului.
    Exemplu: dacă n=3361, subprogramul returnează 3333611.
*/

int Impare(int n) {
    int x = 0, poz, cifra;
    bool areImpare;

    poz = 1;
    areImpare = false;
    while (n != 0) {
        cifra = n % 10;
        if (cifra % 2 != 0) {
            x = cifra * poz + x;
            poz = poz * 10;
            areImpare = true;
        }
        x = cifra * poz + x;
        poz = poz * 10;
        n = n / 10;
    }
    if(areImpare) {
        return x;
    } else {
        return -1;
    }
}

int main() {
    cout << Impare(3361) << endl;
    cout << Impare(2260) << endl;

    return 0;
}