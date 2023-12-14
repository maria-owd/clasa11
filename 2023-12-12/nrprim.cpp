#include <iostream>
using namespace std;


/**
 * Nrprim care are ca parametru nr nat X și 
 * returnează cel mai mic nr prim strict mai mare decât X
 * 
 *      Ex pt X = 25 —> 29
 *         pt 17 —> 19
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

int nrPrim(int x) {
    x = x + 1;
    while (!prim(x)) {
        x = x + 1;
    }
    return x;
}

int main() {
    cout << nrPrim(25) << endl;
    cout << nrPrim(17) << endl;
}