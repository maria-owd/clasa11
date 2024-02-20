#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int aparitii(char *s, char c) {
    int contor = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == c) {
            contor++;
        }
    }
    return contor;
}

bool vocala(char c) {
    char v[] = "aeiouAEIOU";
    return strchr(v, c) != NULL;
}

char litMica(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - ('A' - 'a');
    }
    return c;
}

char litMare(char c) {
    if (c >= 'a' && c <= 'a') {
        return c - ('a' - 'A');
    }
    return c;
}

int main () {
    char sep[] = " ,";
    char s[500];
    char a[500][500];
    char* p;
    int n;

    // citire din fisier
    ifstream f("text.in");
    f.getline(s, 500);

    // afisare
    cout << s << endl;

    // impartire pe cuvinte
    n = 0;
    p = strtok(s, sep);
    while (p != NULL) {
        //..fa ceva cu p
        strcpy(a[n], p);
        n++;
        p = strtok(NULL, sep);
    }

    if (n % 2 == 1) {
        // sorteaza cuvintele
        bool ok;
        do {
            ok = true;
            for (int i=0; i<n-1; i++) {
                if (strlen(a[i]) < strlen(a[i+1])) {
                    char t[500];
                    strcpy(t, a[i]);
                    strcpy(a[i], a[i+1]);
                    strcpy(a[i+1], t);
                    ok = false;
                }
            }
        } while (!ok);

        // ultimul cuvant
        strcpy(a[n-1], "#");

        // afiseaza
        for (int i=0; i<n; i++) {
            cout << a[i] << endl;
        }
    } else {
        char t[500];
        strcpy (t,""); // 
        // de la al doilea la penultimul
        for (int i = 1; i < n-2; i++) {
            strcat(t, a[i]);
            strcat(t,"**");
        }
        // primul 
        strcat(t,a[0]);
        strcat(t,"**");
        // ultimul cuvant
        strcat(t,a[n-1]);
        strcat(t,"**");

        cout << t << endl;
    }

    return 0;
}
