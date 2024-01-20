#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

// Introducem fraza in matrice.

int main() {
    ifstream f("date.in");

    char s[256];
    char sep[] = " ,.?!";
    char *p;

    char a[20][256];
    int n;
    
    f.getline(s, 256);

    p = strtok(s, sep);
    n = 0;
    while (p != NULL) {
        strcpy(a[n], p);
        n++;

        p = strtok(NULL, sep);
    }

    // afisare pe cuvinte
    for(int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
    cout << endl;

    // afisare pe litere
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < strlen(a[i]); j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}