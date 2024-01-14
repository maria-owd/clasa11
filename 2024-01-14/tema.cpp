#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

/**
 * Citiți un șir de caractere de lungime cel mult 100 de caractere. 
 * Acesta va fi format din cuvinte separate prin unul sau mai multe spații. 
 * Șirul se va citi din fișierul „date.in”.
 * Cerințe:
 *  a) Afișați pe ecran șirul citit.
 *  b) Afișați, pe câte un rând de ecran, câte un cuvânt din șir.
 *
 * Exemplu:
 *  Dacă se citește șirul: Ana are     12   mere, se va afișa:
    * Ana are     12   mere
    * Ana
    * are
    * 12
    * mere
 */

int main() {

    ifstream f("date1.in");
    char s[101];
    bool cuvant;

    f.getline(s, 101);

    cout << s << endl;

    cuvant = true;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == ' ') {
            if (cuvant) {
                cout << endl;
            }
            cuvant = false;
        } else {
            cuvant = true;
            cout << s[i];
        }
    }
    cout << endl;
}