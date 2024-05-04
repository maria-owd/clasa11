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
    cout << "0. Iesire din program" << endl;

    int opt;

    cout << endl << endl << "Alegeti numarul optiunii: ";
    cin >> opt;
    
    cin.clear();
    fflush(stdin);
    
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

/**
 * filtreaza furnizorii unici
 * 
 * @param f   lista furnizorilor unico
 * @param nf  numarul furnizorilor unici
 */
void furnizoriUnici(char f[50][50], int &nf) {
    nf = 0;

    for (int i = 0; i < n; i++) {
        bool exista = false;
        // cautam daca furnizorul exista in lista unica
        for (int j = 0; j < nf; j++) {
            if (strcmp(p[i].furnizor, f[j]) == 0) {
                exista = true;
                break;
            }
        }
        if (!exista) {
            strcpy(f[nf], p[i].furnizor);
            nf++;
        }
    }
}

void afisareListaFurnizor(char *numeFurnizor) {
    cout << endl << "Lista produselor cumparate de la " << numeFurnizor << ": " << endl;
    for (int i = 0; i < n; i++) {
        if (strcmp(numeFurnizor, p[i].furnizor) == 0) {
            cout << "  - " << p[i].nume << endl;
        }
    }
}

void listaFurnizori() {
    char f[50][50];     // lista funrnizori unici
    int nf;             // numarul furnizorilor unici
    
    furnizoriUnici(f, nf);
    cout << "Lista furnizorilor: " << endl;
    for (int i = 0; i < nf; i++) {
        cout << i+1 << ") " << f[i] << endl;
    }

    int x;
    cout << "Pentru ce furnizor doriti lista produselor: ";
    cin >> x;

    if (x-1 >= 0 && x-1 < nf) {
        afisareListaFurnizor(f[x-1]);
    } else {
        cout << "Eroare: furnizorul nu este in lista" << endl;
    }
}

void ordonareProduse() {
    produs aux;
    bool ok;
    do {
        ok = true;
        for (int i = 0; i < n-1; i++) {
            if ((strcmp(p[i].nume, p[i+1].nume)) > 0 || (strcmp(p[i].nume, p[i+1].nume) == 0 && p[i].pret < p[i+1].pret)) {
                aux = p[i];
                p[i] = p[i+1];
                p[i+1] = aux;

                ok = false;
            }
        }
    } while (!ok);
}

void stergeProdus(int x) {
    for (int i = x; i < n-1; i++) {
        p[i] = p[i+1];
    }
    n--;
}

void alegeProdusStergere() {
    char nume[50];
    char furnizor[50];
    bool gasit;

    cout << "Numele produsului pe care il stergeti: ";
    cin.getline(nume, 50);

    cout << "Numele furnizorului produsului pe care il stergeti: ";
    cin.getline(furnizor, 50);

    gasit = false;
    for (int i = 0; i < n; i++) {
        if ((strcmp(p[i].nume, nume) == 0) && (strcmp(p[i].furnizor, furnizor) == 0)) {
            stergeProdus(i);
            cout << "Produsul " << i+1 << " a fost sters." << endl;
            i--;
            gasit = true;
        }
    }

    if (!gasit) {
       cout << "Nu am gasit produsul \"" << nume << "\" de la furnizorul \"" << furnizor << "\"" << endl; 
    } 
}

void adaugaProdus() {
    cout << "Numele produsului pe care il adaugati: ";
    cin.getline(p[n].nume, 50);

    cout << "Numele furnizorului produsului pe care il adaugati: ";
    cin.getline(p[n].furnizor, 50);

    cout << "Cantitate: ";
    cin >> p[n].cantitate;

    cout << "Pret: ";
    cin >> p[n].pret;

    n++;

    cout << "Produsul a fost adaugat" << endl;
}


int main () {
    int opt;
    do {
        cout << endl << endl;
        opt = meniu();
        cout << endl << endl;
        switch(opt) {
            case 1: 
                citire();
                break;
            case 2:
                afisare();
                break;
            case 3:
                listaFurnizori();
                break; 
            case 4:
                ordonareProduse();
                afisare();
                break;
            case 5:
                alegeProdusStergere();
                break;
            case 6:
                adaugaProdus();
                break;
            case 0:
                // exit, nu facem nimic
                break;
            default:
                // optiune gresita
                cout << "Optiunea '" << opt << "' este gresita!" << endl;
        }
  
    } while (opt);


}