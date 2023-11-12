#include <iostream>
#include <fstream>
using namespace std;

bool existaImpar(int x[100], int n) {
    for (int i = 0; i < n; i++) {
        if (x[i] % 2 == 1) {
            return true;
        }
    }
    return false;
}

void impar(int x[100], int n) {
    if (existaImpar(x, n)) {
       cout << "DA" << endl; 
    } else {
        cout << "NU" << endl;
    }
}

int main () {
    int x[100], n;

    ifstream f("date.in");
    f >> n;

    for (int i = 0; i < n; i++) {
        f >> x[i];
    }

    impar(x, n);

    return 0;
}
