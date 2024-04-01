#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

/**
* Studentii d la o facultate fac topul celor mai bune melodii din fiecare saptamana.
* Realizati un prgram prin care se introduc n date de forma:
*   - titlul melodiei
*   - artistul
*   - nr puncte primite - date de fiecare 
*   - nr puncte acumulate - totalul
* Afisati primele 3 titluri, descrescator in functie de punctele acumulate.
*/

struct melodie {
    char nume[50];
    char artist[50];
    int puncte;
} m[100];
int n;

int cauta(melodie x) {
    for (int i = 0; i < n; i++) {
        if (strcmp(m[i].nume, x.nume) == 0 && strcmp(m[i].artist, x.artist) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    
    melodie t;

    ifstream f("date.in");

    while (f) {
        f.getline(t.nume, 50);
        f.getline(t.artist, 50);
        f >>t.puncte;
        f.get();

        int poz = cauta(t);
        if (poz >= 0) {
            m[poz].puncte = m[poz].puncte + t.puncte;
        } else {
            m[n]= t;
            n++;
        }
    }
    
    bool schimb;
    do { 
        melodie aux;
        schimb = false;

        for (int i = 0; i < n-1; i++) {
            if (m[i].puncte < m[i+1].puncte) {
                aux = m[i];
                m[i] = m[i+1];
                m[i+1] = aux;
                schimb = true;
            }
        }
    } while (schimb);

    for (int i = 0; i < min(3,n); i++) {
        cout << m[i].nume << " - " << m[i].artist << " are " << m[i].puncte << " puncte" << endl;
    }
    

    return 0;
}