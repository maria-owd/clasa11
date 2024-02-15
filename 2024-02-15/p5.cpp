#include <iostream>
#include <cstring>
using namespace std;

/**
*  Un cuvânt format din cel mult 20 de caractere
*      afișează pe ecran șirul obținut prin eliminarea literei cu cea mai mare frecvență în cuvânt.
*  Dacă sunt mai multelitere cu frecvență maximă 
*     se va elimina litera care se găsește mai înainte în alfabet. 
*   Exemplu: 
*       informatica --> informtic 
*   (literele a și i se găsesc de 2 ori în cuvânt, 
       dar litera a se află înaintea literei i în alfabet).
*/

int aparitii(char *s, char c) {
    int contor = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == c) {
            contor++;
        }
    }
    return contor;
}

int main () {
    char s[20] = "informatica";
    int maxim = 0;
    int apare;
    char m;

    cout << s << endl;
    
    for (char c = 'a'; c <= 'z'; c++) {
        apare = aparitii(s, c);
        if (apare > maxim) {
            maxim = apare;
            m = c;
        }
    }
    for (int i = 0; i < strlen(s); i++) {
        if(s[i] == m) {
            strcpy(s + i, s + i + 1);
            i--;
        }
    }
    cout << s << endl;
    
    return 0;
}