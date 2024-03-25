#include <iostream>
#include <fstream>
using namespace std;

/**
 * Informatii despre 2 masini: marca, culoare, an fabricatie, pret.
 *  a) cititi din fisier
 *  b) afisati pe ecran
 *  c) daca prima masina a fost fabricata in ultimii 10 ani
 *  d) daca prima masina are p > 5000 euro
 *  e) marca cea mai noua
 *  f) marca cea mai ieftina
 *  g) daca masinile au aceeasi marca
 *  h) daca masinile au aceeasi culoare
 *  i) daca masinile au acelasi pret
 *  j) mariti pretul masinii 1 cu 20%
 *  k) scadeti pretul masinii 2 cu 100 euro
*/

struct Masina {
    char marca[50], culoare[20];
    int anF;
    float pret;
};

ifstream f("date.in");
void citire(Masina &m) {
    f.getline(m.marca, 50);
    f.getline(m.culoare, 20);
    f >> m.anF;
    f >> m.pret;
    f.get();
}

void afisare(Masina m) {
    cout << "masina " << m.marca << endl;
    cout << "de culoare " << m.culoare << endl;
    cout << "fabricata in " << m.anF << endl;
    cout << "are pretul " << m.pret << endl << endl;
}

void maiNouaDe(Masina m, int ani) {
    cout << m.marca;
    if (2024 - ani > m.anF) {
        cout << " nu";
    }
    cout << " e mai noua de " << ani << " ani" << endl; 
}

void maiScumpaDe(Masina m, int pret) {
    cout << m.marca;
    if (m.pret < pret) {
        cout << " nu";
    }
    cout << " e mai scumpa de " << pret << " euro" << endl;
}

void marcaCeaNoua(Masina m1, Masina m2) {
    if (m1.anF > m2.anF) {
        cout << m1.marca << " e mai noua ca " << m2.marca << endl;
    } else {
        cout << m2.marca << " e mai noua ca " << m1.marca << endl;
    }
} 

void comparaMarca(Masina m1, Masina m2) {
    cout << "masinile";
    if (strcmp(m1.marca, m2.marca) != 0) {
        cout << " nu";
    }
    cout << " au aceeasi marca" << endl;
}

void scumpeste(Masina &m, int procent) {
    m.pret = m.pret + (procent * m.pret)/100; 
    cout << "am scumpit \"" << m.marca << "\" cu " << procent << "%. Noul pret: " << m.pret << endl;
}

int main () {
    Masina m1, m2;

    // b)
    citire(m1);
    citire(m2);
    afisare(m1);
    afisare(m2);

    // c)
    maiNouaDe(m1, 10); 
    // d)
    maiScumpaDe(m2, 9000);
    // e) 
    marcaCeaNoua(m1, m2);
    // f)
    comparaMarca(m1, m2);
    // j)
    scumpeste(m1, 20);

    return 0;
}

