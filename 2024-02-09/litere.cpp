#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

/**
 * Fisierul are o linie cu un text de maim 70 char.
 *  a) transforma prima si ultima litera in majuscula
 *  b) functie -> cuvintele care incep cu consoana si se termina cu vocala
 *  c) primul cuvant; se sterge pe rand o consoana -> cuvintele obtinute
*/

char convertire(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }
    return c;
}

bool vocala(char c) {
    char vocale[] = "aeiouAEIOU";

    return strchr(vocale, c) != NULL;
}

int main() {
    char s[70];
    char *p;
    char sep[] = " ";
    char a[50][20];
    int n = 0;
    char t[70];

    ifstream f("text.in");
    f.getline(s, 256);

    cout << "textul: " << s << endl;

    p = strtok(s, sep);
    while(p != NULL) {
        strcpy(a[n], p);
        n++;
        p = strtok(NULL, sep);
    }

    cout << "a) ";
    for (int i = 0; i < n; i++) {
        char t[70];
        strcpy(t, a[i]);

        t[0] = convertire(t[0]);
        t[strlen(t)-1] = convertire(t[strlen(t)-1]);

        cout << t << " ";
    }
    cout << endl;

    cout << "b) ";
    for (int i = 0; i < n; i++) {
        if (!vocala(a[i][0]) && vocala(a[i][strlen(a[i])-1])) {
            cout << a[i] << " ";
        }
    }
    cout << endl;

    cout << "c) ";

    strcpy(t, a[0]);
    bool consoana;
    do {
        consoana = false;
        for (int i = 0; i < strlen(t) - 1; i++) {
            if(!vocala(t[i])) {
                strcpy(t+i, t+i+1);
                consoana = true;
                break;
            }
        }
        if (consoana) {
            cout << t << " ";
        }
    } while(consoana);
    cout << endl;

    return 0;
}