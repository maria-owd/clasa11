#include <iostream>
#include <iostream>
#include <fstream>

using namespace std;

/**
 * Cititi din date.in nr de elemente si elementele nr. naturale ale unui vector
 * 
 * Afisati v
 * 
 * apoi afisat pe randuri diferite toate perechile de indici (i,j) 
 * pentru care suma elementelor de pe pozitiile indicate de ele este nr. prim.
 * 
 * @return int 
 */
int main () {

    int n, v[100];
    int suma;
    bool prim;

    ifstream f("date1.in");
    f >> n;

    for (int i = 0; i < n; i++) {
        f >> v[i];
    }

    cout << "vectorul este: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            suma = v[i] + v[j];
            prim = true;
            for (int k = 2; k <= suma/2; k++) {
                if (suma%k == 0) {
                    prim = false;
                }
            }
            if (prim) {
                cout << i << " " << j << endl;
            }
        }
    }

    return 0;
}
