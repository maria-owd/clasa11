#include <iostream>
using namespace std;

/**
 * https://www.pbinfo.ro/probleme/3104/b-egal
 * 
 */

int Egal(int n) {
    int cifra, impar;

    impar = -1;
    while (n > 0) {
        cifra = n%10;
        if (cifra % 2 != 0) {
            if (impar == -1) {
                impar = cifra;
            }
            if (impar != cifra) {
                return 0;
            }
        }
        n = n/10;
    }

    return 1;
}

int main () {
    cout << Egal(7727470) << endl;
    cout << Egal(7240) << endl;
    cout << Egal(7921470) << endl;
}