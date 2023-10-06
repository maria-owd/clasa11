#include <iostream>
#include <fstream>

using namespace std;

/**
 * Citeste nr din date.in
 * Cu o functie verifica daca toate cifrele unui numar sunt egale.
*/

int egale(int n) {
    int primaCifra;
    int cifra;

    primaCifra = n%10;
    while (n > 0) {
        cifra = n%10;
        n = n/10;

        if (primaCifra != cifra) {
            return 0;
        }
    }
    return 1;
}

int pu(int n) {
    int primaCifra;
    int cifra;

    primaCifra = n%10;
    while (n > 0) {
        cifra = n%10;
        n = n/10;
    }
    if (primaCifra == cifra) {
        return 1;
    }
    
    return 0;
}

int main () {
    cout << egale(1234) << endl;
    cout << egale(777) << endl;
    cout << pu(125) << endl;
    cout << pu(121) << endl;
    cout << pu(125671) << endl;

    return 0;
}