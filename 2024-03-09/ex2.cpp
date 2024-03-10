#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

/**
 * Un șablon este un text în care cuvintele sunt separate prin câte un spațiu și sunt formate fie numai din litere mici și mari ale alfabetului englez, fie numai din caractere *, în ultimul caz numindu-se cuvinte generice. Lungimea unui cuvânt este egală cu numărul de caractere care îl compun.
Un computer generează o frază pe baza unui astfel de șablon, prin înlocuirea fiecărui cuvânt generic cu unul dintre cuvintele de aceeași lungime, preluat dintr-o listă dată.
Scrieți un program C/C++ care citește de la tastatură un număr natural, n (n∈[1,100]), și o listă de n cuvinte, urmată de un șablon de tipul precizat. Fiecare cuvânt din listă este format din maximum 10 litere mici și mari ale alfabetului englez și la citire este introdus singur pe linie. Șablonul conține maximum 100 de caractere. Programul obține în memorie și apoi afișează pe ecran una dintre frazele care pot fi generate pe baza șablonului și a listei citite sau mesajul imposibil dacă nu se poate genera o astfel de frază.
 * 
 */

int n;
char variante[100][10], sablon[100];
char *p;
char cuvinte[100][10];
int nrCuv;
bool esteGeneric[100];


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

int main() {
    citire();
    spargereSablon();
    char s[100] = {0};

    bool gasit;
    bool posibil;

    posibil = true;
    for (int i = 0; i < nrCuv; i++) {
        if (esteGeneric[i]) {
            gasit = false;
            for (int j = 0; j < n; j++) {
                if (strlen(cuvinte[i]) == strlen(variante[j])) {
                    strcat(s,variante[j]);
                    gasit = true;
                    break;
                }
            }
            if (!gasit) {
                posibil = false;
            }
        } else {
            strcat(s, cuvinte[i]);
        }
        strcat(s, " ");
    }
    if (posibil) {
        cout << s << endl;
    } else {
        cout << "imposibil" << endl;
    }
    
    return 0;
}