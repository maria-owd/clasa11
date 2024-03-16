#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

/**
 * Cititi datele despre elevi: nume, preunume, nota1, nota2, nota3.
 * Afisati tabelul cu notele si media.
 * Elevii cu media maxima.
 * Ordonati in functie de medie si mesajul nepromovat ( medie < 6)
 */

struct elev {
    char nume[50];
    char prenume[20];
    int note[3];
    float medie;
};

ifstream f("date.in");

elev citire() {
    elev e;
    int suma;

    f >> e.nume;
    f >> e.prenume;

    suma = 0;
    for (int i = 0; i < 3; i++) {
        f >> e.note[i];

        suma = suma + e.note[i];
    }
    f.get();

    e.medie = suma/3.0;

    return e;
}

void afisare(elev e) {
    cout  << left << setw(10) << e.nume << " | "  << setw(10) << e.prenume << " | ";

    for (int i = 0; i < 3; i++) {
        cout << right << setw(2) << e.note[i] << " | ";
    }
    cout << right << setw(5)<< fixed << setprecision(2) << e.medie;

    if (e.medie < 6) {
        cout << " - nepromovat";
    }
    cout << endl;
}

void swap(elev &e1, elev &e2) {
    elev aux;

    aux = e1;
    e1 = e2;
    e2 = aux;
}

int main() {
    int n;
    elev elevi[30];
    float medieMax = 0;

    n = 0;
    while (f) {
        elevi[n] = citire();

        if (elevi[n].medie > medieMax) {
            medieMax = elevi[n].medie;
        }

        n++;
    }

    cout << "medie max: " << medieMax << ", elevii: " << endl;
    for (int i = 0; i < n; i++) {
        if (elevi[i].medie == medieMax) {
           cout << elevi[i].nume << " " << elevi[i].prenume << endl;
        } 
    }

    bool ok;

    do {
        ok = true;

        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                if(elevi[i].medie < elevi[j].medie) {
                    swap(elevi[i], elevi[j]);
                    ok = false;
                }
            }
        }
    } while (!ok);

    cout << endl << "sortare: " << endl;
    for (int i = 0; i < n; i++) {
        afisare(elevi[i]); 
    }

    return 0;
}