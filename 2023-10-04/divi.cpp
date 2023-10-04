#include <iostream>
using namespace std;

//operand
int nrDivi(int n) {
    int divi;
    divi = 0;
    for (int k = 2; k <= n/2; k++) {
        if (n % k == 0) {
            divi++;
        }
    }
    return divi;
}

//procedural
void nrDivi(int n, int &divi) {
    divi = nrDivi(n);
}


int main () {
    int n;
    cout << "n = ";
    cin >> n;

    cout << nrDivi(n) << endl;

    int d;
    nrDivi(n, d);
    cout << d << endl;
    return 0;
}


