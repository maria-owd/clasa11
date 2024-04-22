#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int n;
struct produs {
    char nume[50];
    int cantitate, pret;
    char furnizor[50];
} p[100];

int meniu() {
    cin.clear();
    fflush(stdin);
    
    cout << endl << "Meniu cofetarie" << endl;
    cout << "1. Citire produse" << endl;
    cout << "2. Lista produselor din depozitul firmei" << endl;
    cout << "3. Lista produselor cumparate de la furnizorul cu numele citit de la tastatura" << endl;
    cout << "4. Ordonarea produselor alfabetic dupa nume produsului, iar la aceiasi nume descrescator dupa pret." << endl;
    cout << "5. Stergerea unui produs, cu numele denumirea furnizorului citite de la tastatura" << endl;
    cout << "6. Adaugarea unui nou produs la sfarsitul listei" << endl;
    cout << "7. Afisarea numelui furnizorului de la care a cumparat cele mai multe produse" << endl;
    cout << "8. Afisati valoarea totala a stocului produselor din depozitul cofetariei." << endl;
    cout << "9. Membrii echipei" << endl;
    cout << "10. Iesire din program" << endl;

    int opt;

    cout << "Alegeti numarul optiunii: ";
    cin >> opt;

    return opt;
}

void citire() {
    ifstream f("cofetarie.in");
    f >> n;
    f.get();

    for (int i = 0; i < n; i++) {
        f.getline(p[i].nume, 50);
        f >> p[i].cantitate;
        f >> p[i].pret;
        f.get();
        f.getline(p[i].furnizor, 50);
    }
    cout << "Au fost citite " << n << " produse.";
}

void linie(int nr) {
    for (int i = 0; i < nr; i++) {
        cout << "─";
    }
}

void afisare() {
    // linia de sus a tabelului
    cout << "┌"; linie(42); cout << "┬"; linie(4); cout << "┬"; linie(4); cout << "┬"; linie(32); cout << "┐" << endl;

    // titlul tabelului
    cout << "│ " << left << setw(40) << "Denumirea sortimentului" << " │ ";
    cout << right << setw(2) << "Ct" << " │ ";
    cout << right << setw(2) << "Pr" << " │ ";
    cout << left << setw(30) << "Furnizor" << " │" << endl;

    // linia de jos a titlului
    cout << "├"; linie(42); cout << "┼"; linie(4); cout << "┼"; linie(4); cout << "┼"; linie(32); cout << "┤" << endl;

    // lista de produse
    for (int i = 0; i < n; i++) {
        cout << "│ " << left << setw(40) << p[i].nume << " │ ";
        cout << right << setw(2) << p[i].cantitate << " │ ";
        cout << right << setw(2) << p[i].pret << " │ ";
        cout << left << setw(30) << p[i].furnizor << " │" << endl;
    }
    
    // linia de jos
    cout << "└"; linie(42); cout << "┴"; linie(4); cout << "┴"; linie(4); cout << "┴"; linie(32); cout << "┘" << endl;
}

int main () {
    int opt;
    do {
        opt = meniu();
        switch(opt) {
            case 1: 
                citire();
                break;
            case 2:
                afisare();
                break;
            case 10:
                // exit, nu facem nimic
                break;
            default:
                // optiune gresita
                cout << "Optiunea '" << opt << "' este gresita!" << endl;
        }
  
    } while (opt != 10);


}