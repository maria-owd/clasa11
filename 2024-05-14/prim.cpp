#include <iostream>
using namespace std;

bool estePrim(int x) {
    if (x == 0) {
        return true;
    }
    if (x == 1) {
        return false;
    }
    if (x == 2) {
        return true;
    }

    // -----
    for (int i =3; i< x/2; i++) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}


bool primSingurReturn(int x) {
    bool p = true;

    if (x == 0 ) {
        p = false;
    } else {
        if (x == 1) {
            p = false;
        } else {
            if (x == 2) {
                p = true;
            } else {
                for (int i =3; i< x/2; i++) {
                    if (x % i == 0) {
                        p = false;
                    }
                }
            }
        }
    }

    return p;
}

void prim(int x) {
    if (x == 0 ) {
        cout << " nu e prim" << endl;
    } else {
        if (x == 1) {
            cout << " nu e prim" << endl;
        } else {
            if (x == 2) {
                cout << "prim " << endl;
            } else {
                bool p = true;
                for (int i =3; i< x/2; i++) {
                    if (x % i == 0) {
                        p = false;
                    }
                }
                if (p) {
                    cout << "prim" << endl;
                } else {
                    cout << "nu e prim" << endl;
                }
            }
        }
    }
}

int main() {
    prim(20);
}