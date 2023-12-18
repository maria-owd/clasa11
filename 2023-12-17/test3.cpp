#include <iostream>
using namespace std;


int duplica(int n) {
    int cifra;
    int x = 0;
    int p = 1;

    while (n > 0 ) {
        cifra = n % 10;
        if (cifra % 2 == 0) {
            // cifra dublata
            x = x + p*cifra;
            p = p * 10;
        } 
        // cifra normala
        x = x + p*cifra;
        p = p * 10;

        n = n / 10;
    }
    return x;
}

void depune(int original, int &nou) {
    nou = duplica(original);
    if (nou == original) {
        nou = -1;
    }
}

int main() {
    int x, n;

    cout << "n:";
    cin >> n;

    depune(n, x);

    cout << x << endl;

    return 0;
}