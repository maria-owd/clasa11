#include <iostream>
#include <cstring>

using namespace std;

/**
 * Un şir cu maximum 255 de caractere conţine cuvinte separate prin unul 
 * sau mai multe spaţii.
 * Cuvintele sunt formate numai din litere mici ale alfabetului englez.
 * Scrieţi un program C++ care citeşte un astfel de şir şi îl afişează modificat, 
 * prima şi ultima literă a fiecărui cuvânt fiind afişată ca literă mare.
 * 
 * Exemplu: pentru şirul: 
 *      maine este proba la informatica
 * se va afişa:
 *      MainE EstE ProbA LA InformaticA
 */
char mare(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }

    return c;
}

int main() {
    char s[255];
    bool primaLitera;
    bool inCuvant;
        
    cout << "Sir: ";
    cin.getline(s, 255);

    primaLitera = true;
    inCuvant = (s[0] != ' ');
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == ' ') {
            if (inCuvant && (i > 0)) {
                s[i-1] = mare(s[i-1]);
            } 
            inCuvant = false;
        } else {
            if (!inCuvant) {
                inCuvant = true;
                primaLitera = true;
            }
        }        
        
        if (primaLitera) {
            s[i] = mare(s[i]);
            primaLitera = false;
        }
    }
    s[strlen(s)-1] = mare(s[strlen(s)-1]);
    cout << s << endl;

    return 0;
}