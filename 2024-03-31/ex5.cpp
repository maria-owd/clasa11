#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void f(int n, int &m) {
    if (n!=0) {
        if (n % 10 > m) {
            m= n %10;
        }
        f (n/10, m);
        cout << m << ' ';
    }
}

void p1(int n) {
    int y = 0;
    int x;
    while (n > 0 ) {
        cout << n << ": "; 
        cin >> x;
        while (x % 2 == 0) {
            x = x/2;
        }
        if (x == 1) {
            y = y + 1;
            cout << "\t" << y << endl;
        }
        n = n - 1;
    }
    cout << y << endl;
}

int main() {
    int m = 0;
    //f(54321, m);

    p1(4);
    return 0;
}