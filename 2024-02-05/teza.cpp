#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

bool mare(char c) {
    return (c >= 'A' && c <= 'Z');
}

bool litereMari(char s[]) {
    for (int i = 0; i < strlen(s); i++) {
        if (!mare(s[i])) {
            return false;
        }
    }
   return true;
}

int main() {
    char s[256], *p, sep[] = " ,.?!";
    int n, cuvinte, propozitii = 0;

    ifstream f("date.in");
    f >> n;
    f.get();

    for (int i = 0; i < n; i++) {
        f.getline(s, 256);
        cout << s << endl;

        p = strtok(s, sep);
        cuvinte = 0;
        while (p != NULL) {
            if(litereMari(p) == 1) {
                cuvinte++;
            }
            p = strtok(NULL, sep);
        }
        if(cuvinte == 1) {
            propozitii++;
        }
    }
    cout  << endl << "linii cu 1 cuv doar cu litere mari: " << propozitii << endl;
    
    return 0;
}