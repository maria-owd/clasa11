#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

/**
 * a) afisati sirul de carcatere (max 200 char)
 * b) afisati lungimea sirului
 * c) afisati primul cuvant din sir
 * d) afisati ultimul cuvant
 * e) fiecare cuv sa inceapa cu litera mare si fiecare spatiu este *
 * f) fiecare cuvant sa fie scris pe o alta linie
 */

char mare(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }

    return c;
}

int main() {
    ifstream f("date.in");
    char s[201];
    int l, poz;
    bool cuvant;

    f.getline(s, 201);

    cout << "a) " << s << endl;

    l = strlen(s);
    cout << "b) " << l << endl;

    cout << "c) ";
    for(int i = 0; s[i] != ' '; i++) {
        cout << s[i];
    }
    cout << endl;

    for (int i = l-1; s[i] != ' '; i--) {
        poz = i;
    }
    cout <<  "d) " << &(s[poz]) << endl;

    cuvant = true;
    for (int i = 0; i < l; i++) {
        if (cuvant) {
            s[i] = mare(s[i]);
            cuvant = false;
        }
        if (s[i] == ' ') {
            cuvant = true;
            s[i] = '*';
        }
    }
    cout << "e) " << s << endl;

    cout << "f) " << endl;
    for (int i = 0; i < l; i++) {
        if (s[i] == '*') {
            cout << endl;
        } else {
            cout << s[i];
        }
    }
    cout << endl;

    return 0;
}