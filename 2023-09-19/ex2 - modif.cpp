#include <iostream>
using namespace std;

int main () {
    int n, z, p, c;

    cout << "n = ";
    cin >> n;

    z = 0;
    p = 1;

    do {
        c = n % 10;
        n = n / 10;

        if (c % 3 == 0) {
            z = z + p * (9-c);
            p = p * 10;
        }
    } while (n > 0);
    cout << "z = " << z << endl;
    
    return 0;
}