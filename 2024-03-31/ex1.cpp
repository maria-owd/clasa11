#include <iostream>
#include <cstring>
using namespace std;

void intoarce(char *c) {
    char aux;
    int l = strlen(c);
    for (int i = 0; i < l/2; i++) {
        aux = c[i];
        c[i] = c[l-i-1];
        c[l-i-1] = aux;
    }
}

int main() {
    char s[100] = "#Voi#da#bacu#la#info#";
    char a[50][100];
    int n = 0;
    char *p;
    int max = 0;

    p = strtok(s, "#");
    while (p != NULL) {
        strcpy (a[n], p);

        if (strlen(p) >= max) {
            max = strlen(p);
        }

        p = strtok(NULL, "#");
        n++;
    }
    for (int i = 0; i < n; i++) {
        if (strlen(a[i]) == max) {
            intoarce(a[i]);
        }
        cout << "#" << a[i];
    }
    cout << "#" << endl;

    return 0;
}