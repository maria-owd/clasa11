#include <iostream>
using namespace std;

int n, k, st[10], nrSol;

// in functie de problema
bool validPanaAici(int k) {
    for (int i = 1; i < k; i++)
        if (st[i] == st[k])
            return false;
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
    return k == n;
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

int main()
{
    n = 3;
    backtracking();
    cout << "S-au generat " << nrSol << " solutii.\n";
    return 0;
}
