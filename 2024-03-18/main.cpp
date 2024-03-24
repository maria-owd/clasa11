#include <iostream>
#include <fstream>
using namespace std;

/**
 * Cititi:
 *      numele, prenumele, data nasterii a n persoane 
 * Afisati datele pe ecran.
 * Afisati numele, prenumele, anul celor mai tinere persoane
*/

struct dataCalendar {
    int zi, luna, an;
};

struct persoana {
    char nume[30];
    char prenume[30];
    dataCalendar dataNastere;
};

void afisareData(dataCalendar d) {
    cout << d.zi << "." << d.luna << "." << d.an;
}

void afisare(persoana p) {
    cout << p.nume << " " << p.prenume << ": ";
    afisareData(p.dataNastere);
    cout << endl;
}

bool maiTanar(dataCalendar d1, dataCalendar d2) {
    if (d1.an > d2.an) {
        return true;
    } 
    if (d1.an < d2.an) {
        return false;
    }
    if (d1.luna > d2.luna) {
        return true;
    }
    if (d1.luna < d2.luna) {
        return false;
    }
    return d1.zi > d2.zi;
}

int main() {
    int n = 0;
    persoana elevi[50];
    persoana tanara;
    
    ifstream f("date.in");
    while (f) {
        persoana x;

        f >> x.nume;
        f >> x.prenume;
        f >> x.dataNastere.zi;
        f >> x.dataNastere.luna;
        f >> x.dataNastere.an;
        f.get(); 

        elevi[n] = x;
        n++;
    }

    tanara = elevi[0];

    for (int i = 0; i < n; i++) {
        afisare(elevi[i]);

        if (maiTanar(elevi[i].dataNastere, tanara.dataNastere)) {
            tanara = elevi[i];
        }
    }
    cout << "cea mai tanara persoana e: ";
    afisare(tanara);
    cout << endl;

    return 0;
}
