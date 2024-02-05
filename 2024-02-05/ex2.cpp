#include <iostream>
#include <cstring>

using namespace std;

bool esteVocala(char c) {
    char vocale[] = "aeiouAEIOU";

    return (strchr(vocale, c) != NULL);
}

int nrVocale(char *s) {
    int vocale = 0;
    for(int i = 0; i < strlen(s); i++) {
        if (esteVocala(s[i])) {
            vocale++;
        }
    }
    return vocale;
}

int primaVocala(char *s) {
    for(int i = 0; i < strlen(s); i++) {
        if (esteVocala(s[i])) {
            return i;
        }
    }
    return -1;
}

char transforma(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }
    return c;
}

bool palindrom(char *s) {
    for (int i = 0; i < (strlen(s) - 1) / 2; i++) {
        if (s[i] != s[strlen(s) - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    char x[101] = "bAcAlAUrEAt";
    char copie[101];
    char litera;
    char *poz;
    
    cout << "a) " << x[strlen(x) - 1] << endl;
    cout << "b) " << nrVocale(x) << endl;
    cout << "c) " << x + primaVocala(x) << endl;
    
    strcpy(copie, x);
    copie[0] = transforma(copie[0]);
    cout << "d) " << copie << endl;
    
    cout << "ce litera eliminam: ";
    cin >> litera;

    strcpy(copie, x);
    poz = strchr(copie, litera);

    if (poz != NULL) {
        strcpy(poz, poz + 1);
        cout << "e) " << copie << endl;
    } else {
        cout << "e) nu am gasit litera " << litera << endl;
    }

    cout << "f) ";
    if (palindrom(x)) {
        cout << "DA" << endl;
    } else {
        cout << "NU" << endl;
    }

    return 0;
}
