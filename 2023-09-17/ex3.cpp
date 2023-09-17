#include <iostream>
#include <fstream>
using namespace std;

/**
 * În fișierul date.in se găsesc mai multe numere întregi. 
 * Memorați aceste numere într-un vector, 
 *  apoi afișați-le ordonate crescător. 
 * Afișați cel mai mare, respectiv cel mai mic număr din vector, 
 *  precum și pozițiile pe care se găseau aceste numere în vector înainte de ordonarea acestuia.
 */

    int main () {

    int n, v[100], aux;
    int max, min;
    int pMax, pMin;

    ifstream f("date3.in");
    f >> n;

    for (int i = 0; i < n; i++) {
        f >> v[i];
    }

    cout << "vectorul este: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;


    max = v[0];
    min = v[0];
    for (int i = 0; i < n; i++) {
        if (v[i] > max) {
            max = v[i];
            pMax = i;
        }
        if (v[i] < min) {
            min = v[i];
            pMin = i;
        }
    }
    

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (v[i] > v[j]) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }

    cout << "vectorul ordonat este: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    cout << "max = " << max << " pe pozitia " << pMax << endl;
    cout << "min = " << min << " pe pozitia " << pMin << endl;

    return 0;
}