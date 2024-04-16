#include <iostream>
#include <cstring>
using namespace std;

int sumaNaturale(int n) {
    if (n == 0) {
        return 0;
    }
    return sumaNaturale(n-1) + n;
}

int sumaImpare(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    if (n % 2 == 0) {
        return sumaImpare(n-1);
    } else {
        return sumaImpare(n-2) + n;
    }
}

int main () {
    int n;

    cout << "n = ";
    cin >> n;

    cout << "suma tuturor numerelor naturale: " << sumaNaturale(n) << endl;
    cout << "suma tuturor numerelor naturale impare: " << sumaImpare(n) << endl;
    return 0;
}