#include <iostream>
#include <fstream>
using namespace std;

struct carte{
    char titlu[50];
    char autor[50];
    char editura[50];
    int pret, exemplare;
};

void afisare(int n, carte c[]) {
    for (int i = 0; i < n; i++) {
        cout << "cartea " << c[i].titlu << endl;
        cout << "autorul " << c[i].autor << endl;
        cout << "editura " << c[i].editura << endl;
        cout << "pretul " << c[i].pret << endl;
        cout << "exemplare " << c[i].exemplare << endl << endl;
    }
}

void lista(int n, carte c[]) {
    for (int i = 0; i < n; i++) {
        cout << i+1 << ": ";
        cout << "\"" << c[i].titlu << "\" de ";
        cout << c[i].autor << " - ";
        cout << c[i].exemplare << " exemplare" << endl;
    }
}

int main() {
    int n;
    carte c[100];
    int suma;

    ifstream f("date.in");
    f >> n;
    f.get();

    for (int i = 0; i < n; i++) {
        f.getline(c[i].titlu, 50);
        f.getline(c[i].autor, 50);
        f.getline(c[i].editura, 50);
        f >> c[i].pret;
        f >> c[i].exemplare;
        f.get();
    }
    
    afisare(n, c);
    
    if (n % 2 == 0) {
        cout << "editurile de la mijloc: " << c[n/2 - 1].editura << ", " << c[n/2].editura << endl;
    } else {
        cout << "editura de la mijloc: " << c[(n-1)/2].editura << endl;
    }

    suma = 0;
    for (int i = 0; i < n; i++) {
        suma = suma + c[i].pret;
    }
    cout << "pretul mediu: " << (float)suma / n << endl;

    bool ok;
    do {
        carte aux;
        ok = true;
        for (int i = 0; i < n-1; i++) {
            if (c[i].exemplare > c[i+1].exemplare) {
                aux = c[i];
                c[i] = c[i+1];
                c[i+1] = aux;
                ok = false;
            }
        }
    } while (!ok);

    lista(n, c);
    
    return 0;
}