#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

/**
    Un text separat prin spatiu.
    a) textul pe ecran
    b) pt fiecare cuvant: lungimea si nr de vocale
    c） ordonare cuvinte crescator inf de nr de vocale
*/

bool esteVocala(char c) {
    char vocala[] = "aeiouAEIOU";

    return (strchr(vocala, c) != NULL);   
}

int nrVocale(char *s) {
    int v = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (esteVocala(s[i])) {
            v++;
        }
    }
    return v;
}

int main () {
    char s[256];
    char a[50][50];
    char sep[] = " .,?!";
    char *p;
    int n = 0;

    ifstream f("date.in");

    f.getline(s, 256);
    cout << "a) " << s << endl << endl;

    cout << "b) " << endl;
    p = strtok(s, sep);
    while (p != NULL) {
        strcpy(a[n], p);
        n++;

        cout << p << " " << strlen(p) << " " << nrVocale(p) << endl;

        p = strtok(NULL, sep);
    }

    cout << endl << "c) "<< endl;

    bool ok;
    do {
        ok = true;

        for (int i = 0; i < n-1; i++) {
            if (nrVocale(a[i+1]) < nrVocale(a[i])) {
                char aux[50];

                strcpy(aux, a[i+1]);
                strcpy(a[i+1], a[i]);
                strcpy(a[i], aux);

                ok = false;
            }
        }
    } while (!ok);
    
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }

    return 0;
}