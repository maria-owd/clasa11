#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


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