#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int n;
char variante[100][10], sablon[100];
char *p;
char cuvinte[100][10];
int nrCuv;
int nrGen;
bool esteGeneric[100];
int combinatii[10];

bool eSablon(char *s) {
    for (int i = 0; i < strlen(s); i++) {
        if(s[i] != '*') {
            return false;
        }
    }
    return true;
}

void citire() {
    ifstream f("date2.in");
    f >> n;

    for (int i = 0; i < n; i++) {
        f >> variante[i];
        cout << variante[i] << endl;
    }

    f.get();
    f.getline(sablon, 100);
    cout << sablon << endl;
}

void spargereSablon() {
    nrCuv = 0;
    p = strtok(sablon, " ");
    while (p != NULL) {
        strcpy(cuvinte[nrCuv], p);
        esteGeneric[nrCuv] = eSablon(cuvinte[nrCuv]);
        nrCuv++;
        p = strtok(NULL, " ");
    }
}

void initializareCombinatii() {
    nrGen = 0;
    for(int i = 0; i < nrCuv; i++) {
        if (esteGeneric[i]) {
            combinatii[nrGen] = 0;
            nrGen++;
        } 
    }
}

void afisareCombinatie(int k) {
    cout << "k " << k << ": ";
    for (int i = 0; i < nrGen; i ++) {
        cout << combinatii[i] << " ";
    }
    cout << endl;
}

void afiseazaComb() {
    char s[200];
    int g = 0;
    strcpy(s, "");
    for (int i = 0; i < nrCuv; i++) {
        if (esteGeneric[i]) {
            int var = combinatii[g];
            strcat(s, variante[var]);
            g++;
        } else {
            strcat(s, cuvinte[i]);
        }
        strcat(s, " ");
    }
    cout << s << endl;
}

bool corect() {
    int g = 0;
    for (int i = 0; i < nrCuv; i++) {
        if (esteGeneric[i]) {
            int var = combinatii[g];
            if (strlen(cuvinte[i]) != strlen(variante[var])) {
                return false;
            } 
            g++;
        }
    }
    return true;
}

void cautaComb(int k) {
    if (k >= nrGen) {
        return;
    }
    for (int i=0; i < n; i++) {
        combinatii[k] = i;
       // afisareCombinatie(k);
        if (corect()) {
            afiseazaComb();
        } 
        cautaComb(k+1);
    }
    combinatii[k] = 0;
}

int main() {
    citire();
    spargereSablon();
   
    initializareCombinatii();
    cautaComb(0);
 
    return 0;
}