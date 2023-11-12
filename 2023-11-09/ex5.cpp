#include <iostream>
using namespace std;

void invers(int n, int &x) {
    int cifra;

    x = 0;
    while (n > 0) {
        cifra = n % 10;
        n = n / 10;
        x = x * 10 + cifra;
    }
}

int main () {
    int n, x;

    cout << "n = ";
    cin >> n;

    invers (n, x);
    cout << "x = " << x << endl;

    return 0;
}

