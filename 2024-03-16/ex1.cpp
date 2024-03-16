#include <iostream>
#include <fstream>
using namespace std;

struct elev {
    char nume[50];
    char prenume[20];
    char clasa[10];
    int notaRo;
    int notaMate;
    int notaInfo;
};

int main() {
    int n;
    elev elevi[30];
    int sumaRo, sumaMate, sumaInfo;

    ifstream f("date1.in");

    n = 0;
    while (f) {
        f >> elevi[n].nume;
        f >> elevi[n].prenume;
        f >> elevi[n].clasa;
        f >> elevi[n].notaRo;
        f >> elevi[n].notaMate;
        f >> elevi[n].notaInfo;
        f.get();
        n++;
    }

    sumaRo = sumaMate = sumaInfo = 0;
    for (int i = 0; i < n; i++) {
        cout << elevi[i].nume << " " << elevi[i].prenume << endl;

        sumaRo = sumaRo + elevi[i].notaRo;
        sumaMate = sumaMate + elevi[i].notaMate;
        sumaInfo = sumaInfo + elevi[i].notaInfo;
    }

    cout << "media romana: " << sumaRo/n << endl;
    cout << "media mate: " << sumaMate/n << endl;
    cout << "media info: " << sumaInfo/n << endl;

    return 0;
}