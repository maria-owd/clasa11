#include <iostream>
using namespace std;

struct DataCal {
    int zi, luna, an;
};

struct Persoana {
    char nume[50];
    DataCal nastere;
    DataCal absolvire;
};

DataCal citireData(const char *tip) {
    DataCal d;

    cout << "ziua " << tip ;
    cin >> d.zi;
    cout << "luna " << tip;
    cin >> d.luna;
    cout << "anul " << tip ;
    cin >> d.an;

    return d;
}

Persoana citire() {
    Persoana p;

    cout << "numele: ";
    cin >> p.nume;

    p.nastere = citireData("nasterii: ");
    cout << endl;
    p.absolvire = citireData("absolvirii: ");

    return p;
}

void afisareData(DataCal d, const char *tip) {
    cout << tip << " " << d.zi << "." << d.luna << "." << d.an;
}

void afisare(Persoana p) {
    cout << p.nume << " ";
    afisareData(p.nastere, "s-a nascut la");
    cout << ", ";
    afisareData(p.absolvire, "a absolvit la");
    cout << endl;
}

int main() {
    Persoana x;

    x = citire();
    afisare(x);

    return 0;
}