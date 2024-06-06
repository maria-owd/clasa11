#include <iostream>
using namespace std;

int n, p, k, st[10], nrSol;

// 1. cifre diferite
// 2. cifre crescatoare
// 3. paritate diferita
bool validPanaAici(int k) {
    for (int i = 1; i < k; i++) {
        if (st[i] == st[k]) {
            return false;
        }
    }     
    for (int i = 1; i <= k-1; i++) {
        if (st[i+1] < st[i]) {
            return false;
        }
        if (st[i] % 2 == st[i+1] % 2) {
            return false;
        }
    }
    return true;
}

void initializare(int k) {
    st[k] = 0;
}

bool alegSuccesor(int k) {
    if (st[k] < n) {
        st[k]++;
        return true;
    } else {
        return false;
    }
}

bool variantaFinala(int k) {
    return k == p;
}

void afisare(int k) {
    for (int i = 1; i <= k; i++)
        cout << st[i] << ' ';
    cout << endl;
    nrSol++;
}

void backtracking() {
    k = 1;
    initializare(k);
    while (k > 0) {
        while (alegSuccesor(k)) {
            if (validPanaAici(k)) {
                if (variantaFinala(k)) {
                    afisare(k);
                } else {
                    k++;
                    initializare(k);
                }
            }
        }
        k--;
    }
}

int main() {
    n = 9;
    p = 3;
    backtracking();
    cout << "S-au generat " << nrSol << " solutii" << endl;

    return 0;
}
