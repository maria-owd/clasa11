#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int n;  // numarul produselor
struct produs {
    char nume[50];
    int cantitate, pret;
    char furnizor[50];
} p[100];  // produsele din cofetarie 

/**
 * Afisare logo cofetarie 
 */
void logo() {
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;   
    cout << "______ _                        __             _   " << endl;     
    cout << "| ___ (_)                      / _|           | |       " << endl;
    cout << "| |_/ /_  ___  ___ ___    ___ | |_    ___ __ _| | _____ " << endl;
    cout << "|  __/| |/ _ \\/ __/ _ \\  / _ \\|  _|  / __/ _` | |/ / _ \\" << endl;
    cout << "| |   | |  __/ (_|  __/ | (_) | |   | (_| (_| |   <  __/" << endl;
    cout << "\\_|   |_|\\___|\\___\\___|  \\___/|_|    \\___\\__,_|_|\\_\\___|" << endl;
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;                                        
}

/**
 * Afisare meniu principal
 * 
 * @return int -> optiunea selectata
 */
int meniu() {   
    logo(); 
    cout << endl << "*** Meniu cofetarie ***" << endl << endl;
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
    
    // sterge lista de caractere de la tastatura
    cin.clear();  
    fflush(stdin);
    
    return opt;
}

/**
 * Citire date din fisier
 */
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

/**
 * Afisare linie orizontala, folosind caracter special ASCII
 * 
 * @param nr: lungimea liniei, in caractere 
 */
void linie(int nr) {
    for (int i = 0; i < nr; i++) {
        cout << "─";
    }
}

/**
 * Afisare lista de produse, folosind caractere ASCII pentru tabel
 */
void afisare() {
    // linia de sus a tabelului
    cout << "┌"; linie(42); cout << "┬"; linie(4); cout << "┬"; linie(4); cout << "┬"; linie(22); cout << "┐" << endl;

    // titlul tabelului
    cout << "│ " << left << setw(40) << "Denumirea sortimentului" << " │ ";
    cout << right << setw(2) << "Ct" << " │ ";
    cout << right << setw(2) << "Pr" << " │ ";
    cout << left << setw(20) << "Furnizor" << " │" << endl;

    // linia de jos a titlului
    cout << "├"; linie(42); cout << "┼"; linie(4); cout << "┼"; linie(4); cout << "┼"; linie(22); cout << "┤" << endl;

    // lista de produse
    for (int i = 0; i < n; i++) {
        cout << "│ " << left << setw(40) << p[i].nume << " │ ";
        cout << right << setw(2) << p[i].cantitate << " │ ";
        cout << right << setw(2) << p[i].pret << " │ ";
        cout << left << setw(20) << p[i].furnizor << " │" << endl;
    }
    
    // linia de jos
    cout << "└"; linie(42); cout << "┴"; linie(4); cout << "┴"; linie(4); cout << "┴"; linie(22); cout << "┘" << endl;
}

/**
 * Filtreaza furnizorii unici
 * 
 * @param f   Lista furnizorilor unici
 * @param nf  Numarul furnizorilor unici
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

/**
 * Afisare lista produse cumparate de la un furnizor transmis prin parametru
 * 
 * @param numeFurnizor -> numele furnizorului pentru care se afiseaza lista
 */
void afisareListaFurnizor(char *numeFurnizor) {
    cout << endl << "Lista produselor cumparate de la " << numeFurnizor << ": " << endl;
    for (int i = 0; i < n; i++) {
        if (strcmp(numeFurnizor, p[i].furnizor) == 0) {
            cout << "  - " << p[i].nume << endl;
        }
    }
}

/**
 * Afisare lista furnizorilor, apoi afiseaza lista produselor cumparate  
 * de la furnizorul ales
 */
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

/**
 * Ordonarea produselor alfabetic dupa nume produsului, 
 * iar la acelasi nume, descrescator după pret.
 */
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

/**
 * Sterge un produs din lista
 * 
 * @param x -> indicele produsului sters
 */
void stergeProdus(int x) {
    for (int i = x; i < n-1; i++) {
        p[i] = p[i+1];
    }
    n--;
}

/**
 * Sterge un produs cu numele si furnizorul alesi de la tastatura
 */
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

/**
 * Adauga un produs la finalul listei cu datele introduse de la tastatura
 */
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

/**
 * Calculeaza numarul produselor de la fiecare furnizor
 * Afisarea furnizorului cu cele mai multe comenzi
 */
void furnizorPopular() {
    char f[50][50];     // lista funrnizori unici
    int nf;             // numarul furnizorilor unici
    int cantitati[50];  // numarul total al comenzilor la un furnizor
    int iMaxim = 0;

    // identificarea furnizorilor unici
    furnizoriUnici(f, nf);

    // calculare cantitate/furnizor
    for (int i = 0; i < nf; i++) {
        cantitati[i] = 0;

        for (int j = 0; j < n; j++) {
            if (strcmp(f[i], p[j].furnizor) == 0) {
                cantitati[i] = cantitati[i] + p[j].cantitate;
            }
        }
    }

    // identificarea cantitatii maxime
    for (int i = 0; i < nf; i++) {
        if (cantitati[i] > cantitati[iMaxim]) {
            iMaxim = i;
        }
    }

    cout << "Furnizorul cu cele mai multe comenzi: " << f[iMaxim] << " cu " << cantitati[iMaxim] << " produse " << endl;
}

/**
 * Afisare stoc cofetarie
 */
void stocCofetarie() {
    int suma = 0;

    for (int i = 0; i < n; i++) {
        suma = suma + p[i].cantitate;
    }

    cout << "Stocul total: " << suma << endl;
}

/**
 * Afisare membrii echipei
 */
void membriiEchipei() {
    cout << "Membrii echipei: " << endl;
    cout << "♥ " << "Maiorescu Maria" << endl;
    cout << "♥ " << "Radu Alice" << endl;
    cout << "♥ " << "Trofim Romira" << endl;
}

/**
 * Se afiseaza meniul principal
 * Executarea functiei selectate, pana la iesire 
 */
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
            case 7:
                furnizorPopular();
                break;
            case 8:
                stocCofetarie();
                break;
            case 9:
                membriiEchipei();
                break;
            case 0:
                // exit, nu facem nimic
                break;
            default:
                // optiune gresita
                cout << "Optiunea '" << opt << "' este gresita!" << endl;
        }

        // se asteapta apasare Enter pentru a vizualiza rezultatele 
        if (opt) {
            cout << endl << "Apasati Enter pentru a continua ..." ;
            cin.get();
        }
    } while (opt);

    return 0;
}