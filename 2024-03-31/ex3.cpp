#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int ultima(int x) {
    return x % 10;
}

int prima(int x) {
    while (x > 9) {
        x = x / 10;
    }
    return x;
}

bool fazan(int x1, int x2) {
    return ultima(x1) == prima(x2);
}

int main() {
    int a, b, contor = 1, maxim = 0;

    ifstream f("bac.txt");

    f >> a;
    while (f >> b) {
        if (fazan(a, b)) {
            contor++;
        } else {
            if (contor > maxim) {
                maxim = contor;
            }
            contor = 1;
        }
        a = b;
    }
    cout << maxim << endl;

    return 0;
}
 