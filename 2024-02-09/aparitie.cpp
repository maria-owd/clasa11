#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

/**
 * Un text de maxim 250 caractere separate de spatiu si virgula.
 * Numarul de litere care apare de exact k ori; daca nu --> 0
*/

char litera(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - ('A' - 'a');
    }
    return c;
}

int aparitii(char c, char *s) {
    int apare = 0;
    for(int i = 0; i < strlen(s); i++) {
        if (c == litera(s[i])) {
            apare++;
        }
    }
    return apare;
}

int main() {
    char s[256];
    int k, contor = 0;

    ifstream f("date.in");
    f >> k;
    f.get();
    f.getline(s, 256);

    cout << "textul este: " << s << endl;
    cout << "k = " << k << endl;

    for (char c = 'a'; c < 'z'; c++) {
        if(aparitii(c, s) == k) {
            contor++;
        }
    }
    cout << contor << endl;

    return 0;
}

