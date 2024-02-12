#include <iostream>
#include <cstring>

using namespace std;

/**
 * Citim un cuv format din cel mult 20 litere.
 *  Inversează prima jumate a șirului cu cea de-a doua jumate.
 *  Dacă șirul conține un nr impar de caractere, char din mijloc e nemodificat
 * 
 * Ex:
 *      informatica --> atica.m.infor
 *      informatic --> matic.infor
 */

int main() {
    char s[20];
    int jumate;
    int rest;
    char t[20];

    cout << "cuvant: ";
    cin >> s;
    
    jumate = strlen(s) / 2;
    rest = strlen(s) % 2;
    
    strcpy(t, s + jumate + rest);
    strncat(t, s + jumate, rest);
    strncat(t, s, jumate);

    cout << t << endl;
    
    return 0;
}