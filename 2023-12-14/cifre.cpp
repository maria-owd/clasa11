#include <iostream>
using namespace std;

void verific(int n, bool &egale) {
    int cifra;

    cifra = n % 10;
    while (n > 0) {
        if (cifra != n % 10) {
            egale = false;
            return;
        }
        n = n / 10;
    }
    egale = true;
}

int main () {
    int n;
    bool cifreEgale;

    cout << "n = ";
    cin >> n;

    verific(n, cifreEgale);
    
    if (cifreEgale) {
        cout << "da" << endl;
    } else {
        cout << "nu" << endl;
    }

    return 0;
}