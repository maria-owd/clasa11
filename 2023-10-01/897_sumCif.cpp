#include <iostream>
using namespace std;

int sumcif(int n) {
    int suma;

    suma = 0;
    while (n > 0) {
        suma = suma + n%10;
        n = n/10;
    }

    return suma;
}

int main() {

    cout << sumcif(241) << endl;

    return 0;
}