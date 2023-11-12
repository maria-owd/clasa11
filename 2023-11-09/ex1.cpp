#include <iostream>
using namespace std;

bool nrPrim (int a) {
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

void prime(int x, int y) {
    if (y < x) {
        x = x + y;
        y = x - y;
        x = x - y;
    }
    for (int i = x; i <= y; i++) {
        if (nrPrim(i)) {
            cout << i << " "; 
        }
    }
    cout << endl;
}

int main () {
    int x, y, b;

    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;

    prime(x,y);

    return 0;
}