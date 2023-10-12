#include <iostream>
#include <fstream>
using namespace std;

void sum(int n, bool &m) {
    int suma;

    suma = 0;
    while (n > 9) {
        suma = suma + n % 10; 
        n = n/10;
    }
    m = (n == suma);
}

int main() {
    int n, x;
    bool egale;
    int suma;

    ifstream f("date.in");
    f >> n;

    suma = 0;
    for (int i = 0; i < n; i++) {
        f >> x;
        sum(x, egale);

        if (egale) {
            suma = suma + x;
        }
    }
    cout << "suma = " << suma << endl;

    return 0;
}