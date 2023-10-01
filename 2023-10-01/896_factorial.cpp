#include <iostream>
using namespace std;


int fact(int n) {
    int produs;
    
    if (n == 0) {
        return 1;
    }
    if (n < 0 || n > 12) {
        return 0;
    }

    produs = 1;
    for (int i = 1; i <=n; i++) {
        produs = produs * i;
    }

    return produs;
}

int main () {
    cout << fact(4) << endl;
    cout << fact(3) << endl;
    cout << fact(0) << endl;
    cout << fact(12) << endl;
    cout << fact(-1) << endl;

    return 0;
}

