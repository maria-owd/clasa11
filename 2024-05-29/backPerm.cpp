#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int n;

int v[10];

// in functie de problema
bool validPanaAici(int k) {
    for (int i = 0; i < k; i++) {
        if (v[i] == v[k]) {
            return false;
        }
    }
    return true;
}

void afisare(int k) {
    for(int i = 0; i <= k; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void backtracking(int k) {
    if (k < n) {
        for (int i = 1; i <= n; i++) { // valori posibile
            v[k] = i;
            if (validPanaAici(k)) {
                if (k == n-1) { //final
                    afisare(k);
                }
                backtracking(k + 1);
            } 
        }
    }
} 

int main() {
    n = 4;

    backtracking(0);
}