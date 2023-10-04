#include <iostream>
using namespace std;

//operand
int perf(int n) {

    int divi, suma;
    divi = 0;
    suma = 0;

    for (int i = 1; i <= n/2; i++) {
        if (n % i == 0) {
            divi++;
            suma = suma + divi;
        }
    }

    if (suma == n) {
        return 1;
    } 

    return 0;
}

//procedural
void perf(int n, bool &rezultat) {
    int r;
    r = perf(n);

    if (r == 1) {
        rezultat = true;
    } else {
        rezultat = false;
    }

}

int main() {
    int n;

    cout << "n = ";
    cin >> n;

    cout << perf(n) << endl;

    bool rez;
    perf(n, rez);
    cout << rez << endl;

    return 0;
}