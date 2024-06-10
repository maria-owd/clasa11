#include <iostream>
using namespace std;

/**
 * Se citesc doua nr nat n si k.
 * Modurile in care se pot aranja nr de la 1 -> n
 *      a.i. diferenta dintre doua numere alaturate sa fie <= k
*/

int n, p, k, st[10], nrSol;

bool validPanaAici(int k) {
    for (int i = 1; i < k; i++) {
        if (st[i] == st[k]) {
            return false;
        }
    }     
    for (int i = 1; i <= k-1; i++) {
        if (abs(st[i] - st[i+1]) > p) {
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
    n = 4;
    p = 2;
    
    backtracking();
    cout << "S-au generat " << nrSol << " solutii" << endl;

    return 0;
}
