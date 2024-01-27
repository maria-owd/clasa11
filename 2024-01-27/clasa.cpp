#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

/**
 * Un text cu maxim 500 caractere.
    a) afisati textul
    b) cuvintele unul sub altul
    c) numarati cate cuvinte sunt identice cu primul cuvant 
    d) cuvintele unul sub altul, cu prima si ultima litera mare
    e）afisati lexicografic doar cuvintele care contin litere
 */

char litera(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }
    return c;
}

bool esteLitera(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool doarLitere(char *s) {
    for (int i = 0; i < strlen(s); i++) {
        if (!esteLitera(s[i])) {
            return false;
        }
    }
    return true;
}

int main () {
    char s[500], a[50][50];
    char *p;
    int n, egale;

    ifstream f("date.in");

    f.getline(s,500); 
    cout << "a) " << s << endl;

    n = 0;
    p = strtok(s, " ");
    while (p != NULL) {
        strcpy(a[n], p);
        n++;
        p = strtok(NULL, " ");
    }

    cout << endl << "b) " << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }

    egale = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && strcmp(a[0], a[i]) == 0) {
            egale++;
        }
    }
    cout << endl << "c) " << egale << endl;

    cout << endl << "d) " << endl;
    for (int i = 0; i < n; i++) {
        char t[50];
        int l;

        strcpy(t, a[i]);
        l = strlen(t);

        t[0] = litera(t[0]);
        t[l-1] = litera(t[l-1]);
        cout << t << endl;
    }

    cout << endl << "e) " << endl;
    for (int i = 0; i < n; i++) {
        if (doarLitere(a[i])) {
            cout << a[i] << endl;
        }
    }

    return 0;
}