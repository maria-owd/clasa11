#include <iostream>
#include <cstring>
using namespace std;

int nrCif(int n) {
    if(n <= 9) {
        return 1;
    } else {
        return nrCif(n/10) + 1;
    }
}

int nrCifImp(int n) {
    if (n == 0) {
        return 0;
    } else {
        return nrCifImp(n/10) + n % 2;
    }
}

int main () {
    int x[] = {987, 132589, 0, 1, 432432, 35, 68, 974};

    for (int i = 0; i < sizeof(x)/sizeof(*x); i++) {
        cout << "numarul " << x[i] << " are " << nrCif(x[i]) << " cifre si " << nrCifImp(x[i]) << " cifre impare" << endl;
    }
    return 0;
}