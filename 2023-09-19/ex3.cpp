#include <iostream>
using namespace std;

int main () {
    int a, b, i, n, c, k;

    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    k = 0;

    for (int i = a; i <= b; i++) {
        n = i;
        c = 0;
        while (n > 0) {
            if (n % 2 == 1) {
                c = c + 1;
            }
            n = n/10;
        }
        if (c > 0) {
            k++;
        }
    }
    cout << "k = " << k << endl;

    return 0;
}