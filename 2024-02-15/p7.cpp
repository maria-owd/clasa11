#include <iostream>
#include <cstring>
using namespace std;

/**
    Se consideră un text cu cel mult 100 de caractere 
        transformarea acestuia prin duplicarea tuturor vocalelor din text
    Exemplu: problema aceea frumoasa
         proobleemaa aaceeeeaa fruumooaasaa.
*/

bool vocala(char c) {
    char v[] = "aeiouAEIOU";

    return strchr(v, c) != NULL;
}

int main() {
    char s[200] = "problema aceea frumoasa";

    cout << s << endl;

    for (int i = 0; i < strlen(s); i++) {
        if (vocala(s[i])) {
            strcpy(s + i, s + i +1);
           // s[i + 1] = s[i];
            i--; 
            cout << s << endl;
        }
    }
   

    return 0;
}