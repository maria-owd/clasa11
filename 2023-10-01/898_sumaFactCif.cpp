#include <iostream>
using namespace std;

/**
 * https://www.pbinfo.ro/probleme/898/sumfactcif
 * 
 */


int sumfactcif(int n) {
    int f;
    int suma, cifra;

    if (n == 0) {
        return 1;
    }

    suma = 0;
    while (n > 0) {
        cifra = n%10;
        n = n/10;
       
        f = 1;
        for (int i = 1; i <= cifra; i++) {
            f = f * i;
        }

        suma = suma + f;
    }

    return suma;
}


int main() {
    cout << sumfactcif(241) << endl;
    cout << sumfactcif(10) << endl;
    cout << sumfactcif(0) << endl;
}