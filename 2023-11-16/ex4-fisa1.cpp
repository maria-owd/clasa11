#include <iostream>
using namespace std;

// a) divi proprii

void divi(int n) {

    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}

// b)

char tip(char c) {
    if (c >= '0' && c <= '9') {
        return 'C';
    }

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        return 'L';
    }

    return 'S';
}

int main () {
    int n;
    cout << "n = ";
    cin >> n;

    divi(n);

    char c;
    cout << "c = ";
    cin >> c;

    cout << c << " este " << tip(c) << endl;

    return 0;
}