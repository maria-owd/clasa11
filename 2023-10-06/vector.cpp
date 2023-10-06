#include <iostream>
#include <fstream>
using namespace std;

int egale(int n, int v[100]) {

    for (int i = 0; i < n-1; i++) {
        if (v[i] != v[i+1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, v[100];

    ifstream f("date.in");
    f >> n;

    for (int i = 0; i < n; i++) {
        f >> v[i];
    }

    if (egale(n, v)) {
        cout << "DA" << endl;
    } else {
        cout << "NU" << endl;
    }

    return 0;
}