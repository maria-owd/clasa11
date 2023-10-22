#include <iostream>
#include <fstream>
using namespace std;

/**
 * Să se creeze fișierul gemene.txt care să conțină primele n perechi de numere prime gemene,
 *  știind că n este un număr natural care se citește de la tastatură.
 * Se numesc prime gemene, două numere naturale prime de forma p, p+2.
 */

bool prim (int a) {
    if (a == 0 || a == 1) {
        return false;
    }

    for (int i = 2; i <= a/2; i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

bool gemene(int p) {
    return prim(p) && prim(p + 2);
}

int main () {
    int n, x;

    cout << "cate perchi gemene: ";
    cin >> n;

    x = 3;
    while (n > 0) {
        if (gemene(x)) {
            cout << x << " " << x + 2 << endl;
            n--;
        }
        x = x + 2;
    }

    return 0;
}