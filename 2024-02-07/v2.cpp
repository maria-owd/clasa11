#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
    char s[20];
    char r[20] = "";
    char t[1];

    cout << "alege un cuvant: ";
    cin.get(s, 20);

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] < 'a' || s[i] > 'z') {
            t[0] = s[i];
            strcat(r, t);
        } 
    }
    if (strlen(r) == 0) {
        cout << "CUVANT VID" << endl;
    } else {
        cout << r << endl;
    }

    return 0;
}