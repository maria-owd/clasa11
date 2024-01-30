#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

/**
 * Un sir cu maxim 500 caractere
 *  a) sirul pe ecran
 *  b) cuvintele unul sub altul
 *  c) cuvintele care au nr par de char unul sub altul
 */

int main() {
    ifstream f("date.in");

    char s[500];
    char sep[] = " ,.?!";
    char *p;
    char a[50][50];
    int n = 0;

    f.getline(s, 500);
    cout << "a) " << s << endl << endl;

    cout << "b) " << endl;
    p = strtok(s, sep);
    while(p != NULL) {
        cout << p << endl;

        if(strlen(p) % 2 == 0) {
            strcpy(a[n], p);
            n++;
        }

        p = strtok(NULL, sep);
    }
    cout << endl << "c) " << endl;

    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
    
    return 0;
}