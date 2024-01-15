#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

/**
 * Din fișier citiți: n cuvinte.
 * Afișați pe ecran 
 *      numărul de caractere a celui mai lung cuvânt,
 *      împreună cu ultimul cuvânt citit care are această lungime.
 * Afișați care este cel mai mic cuvânt în sens l.g, 
 *      iar dacă sunt mai multe astfel de cuvinte, 
 *      afișați ultimul dintre ele, împreună cu nr de caractere
 */

int main() {
    char a[100];
    int n;
    int lungime, maxim, minim;
    char b[100], c[100];

    ifstream f("date.in");
    f >> n;

    maxim = 0;
    
    for (int i = 0; i < n; i++) {
        f.getline(a, 101);

        if (i == 1) {
            strcpy(c,a);
        }

        lungime = strlen (a);
        if (lungime >= maxim) {
            maxim = lungime;
            strcpy(b, a);
        }

        if (strcmp(a, c) < 0) {
            strcpy(c, a);
        }
    }
    cout << maxim << "  " << b << endl;
    cout << c << "  " << strlen(c) << endl;
    
    return 0;
}