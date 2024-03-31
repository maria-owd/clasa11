#include <iostream>
using namespace std;

int main() {
    char s[100] = "Voi da bacalaureatul la Inforatica";
    int aparitii[256] = {0};
    int maxim = 0;
    char ch;

    for (int i = 0; i < strlen(s); i++) {
        aparitii[s[i]]++;
    }
    for (int c=1; c <= 255; c++) {
        if (aparitii[c] > maxim) {
            maxim = aparitii[c];
        }
    }
    for (int c=1; c <= 255; c++) {
        if (aparitii[c] == maxim) {
            ch = c;
           cout << ch << " " << maxim << endl;
        }
    }
    return 0;
}