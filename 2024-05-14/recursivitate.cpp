#include <iostream>
using namespace std;

/**
* Folosind funcții recursive realizați un program C++ pentru:
*   - citirea de la tastatură a elementelor unui vector cu n (n<=30) numere întregi
*   - afișarea elementelor vectorului pe ecran
*   - afișarea pe ecran a elementelor cu valoare pară
*   - afișarea pe ecran a elementelor de pe poziții pare
*   - determinarea și afișarea pe ecran a sumei elementelor din vector
*/

int v[100];
void citire(int k, int pozMax) { 
    cout << "v[" << k << "] = ";
    cin >> v[k];
    if (k < pozMax) {
        citire(k+1, pozMax);
    }
} 

void afisare(int k, int pozMax) {
    if (k == pozMax) {
        return;
    }
    cout << "v[" << k << "] = " << v[k] << endl;
    afisare(k+1, pozMax);
}

void elemPare(int k, int pozMax) {
    if (k == pozMax) {
        return;
    }

    if (v[k] % 2 == 0) {
        cout << "v[" << k << "] = " << v[k] << endl;
    }
    elemPare(k+1, pozMax);
}

void pozPare(int k, int pozMax) {
    if (k == pozMax) {
        return;
    }

    if (k % 2 == 0) {
        cout << "v[" << k << "] = " << v[k] << endl;
    }
    pozPare(k+1, pozMax);
}

int sumaElem(int k, int pozMax) {
    if (k == pozMax) {
        return 0;
    }
    return v[k] + sumaElem(k+1, pozMax);
}

int main() {
    int n;
    
    cout << "Cate elemente are vectorul: ";
    cin >> n;

    citire(0, n);

    cout << "Elementele vectorului: " << endl; 
    afisare(0, n);

    cout << "Elementele pare sunt: " << endl;
    elemPare(0, n);

    cout << "Elementele de pe pozitii pare sunt: " << endl;
    pozPare(0, n);

    cout << "Suma elementelor este: " << sumaElem(0, n) << endl;
    

    return 0;
}