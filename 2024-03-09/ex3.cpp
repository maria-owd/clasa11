#include <iostream>
#include <fstream>
using namespace std;
/**
 * Un șir se numește de tip api dacă 
 *  numărul de apariții ale fiecărui termen este mai mic sau egal cu acel termen și are o paritate egală cu a acestuia.
 *  Fișierul bac.in conține un șir de cel mult 10^6 numere naturale.
 * Se cere să se afișeze pe ecran mesajul DA, dacă șirul este de tip api, 
 *  sau mesajul NU în caz contrar. 
 * Proiectați un algoritm eficient din punctul de vedere al timpului de executare.
    Exemplu: dacă fișierul conține numerele 6 27 2 6 27 6 6 14 14 2 27 
    se afișează pe ecran DA (termenul par 6 apare de 4 ori, 4 fiind tot număr par și 4≤6,
    termenii pari 2 și 14 apar de câte 2 ori, 2 fiind tot număr par și 2≤2, respectiv 2≤14,
    iar termenul impar 27 apare de 3 ori, 3 fiind tot număr impar și 3≤27).
*/

int main() {
    int x;
    int aparitii[1000] = {0}; 
    bool api;

    ifstream f("bac.in");

    while (f >> x){
        cout << x << " ";
        aparitii[x] = aparitii[x] + 1;
    }

    api = true;
    for (int i = 0; i < 1000; i++) {
        if (aparitii[i] > 0) {
            if (aparitii[i] > i) {
                api = false;
                break;
            }
            if (aparitii[i] % 2 != i % 2) {
                api = false;
                break;
            }
        }
    }
    cout << endl;

    if (api) {
        cout << "DA" << endl;
    } else {
        cout << "NU" << endl;
    }

    return 0;
}