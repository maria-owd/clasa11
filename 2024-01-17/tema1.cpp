#include <iostream>
#include <cstring>

using namespace std;

/**
 * Scrieţi un program C++ care citeşte de la tastatură o frază de maximum 255 de caractere
 * (litere mari ale alfabetului englez şi spaţii), ale cărei cuvinte sunt despărţite prin câte un spaţiu şi
 * afişează pe primul rând al ecranului numărul total al cuvintelor din frază, iar pe rândul următor de
 * ecran, în ordine alfabetică, scrise o singură dată, consoanele care au apărut în frază (consoane sunt
 * toate literele alfabetului englez, mai puţin A, E, I, O, U). Literele afişate sunt separate prin câte un
 * spaţiu.
 * 
 * Exemplu: dacă se citeşte fraza LA BACALAUREAT SUBIECTELE AU FOST USOARE
 * se va afişa:
 *              6
 *              B C F L R S T
 * 
 */
bool consoana(char c) {
    return (c != 'A') && (c != 'E') && (c != 'I') && (c != 'O') && (c != 'U')
    && (c != 'a') && (c != 'e') && (c != 'i') && (c != 'o') && (c != 'u');
}

int main() {
    char sep[] = " ";
    char fraza[255];
    char litere[255];
    char *c;
    int cuvinte;
    
    cout << "Fraza: ";
    cin.getline(fraza, 255);

    for (int i=0; i<255; i++) {
        litere[i] = 0;
    }

    cuvinte = 0;
    c = strtok(fraza, sep);
    while (c != NULL) {    
        cuvinte ++;

        while (*c != 0) {
            litere[*c]++;
            c++;
        }

        c = strtok(NULL, sep);
    }

    cout << cuvinte << endl;

    for (char i = 'A'; i <= 'Z'; i++) {
        if (litere[i] > 0 && consoana(i)) {
            cout << i << ' ';
        }
    }
    cout << endl;

    return 0;
}