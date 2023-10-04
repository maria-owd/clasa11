#include <iostream>
using namespace std;

int n, k;

void par(int n, int &k) {
    k = 0;
    int c;
    while (n) {
        c = n % 10;
        if (c % 2 == 0) {
            k++;
        } 
        n = n/10;
    }
    cout << "sunt in functia par, k=" << k << endl;
}

int main() {
    k = 0;
    n = 123458;

    par(n, k);

    cout << "sunt in main, k=" << k << endl;

}