#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
    char s[20];

    cout << "alege un cuvant: ";
    cin.get(s, 20);

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            strcpy(s+i, s+i+1);
            i--;
        } 
    }
    if (strlen(s) == 0) {
        cout << "CUVANT VID" << endl;
    } else {
        cout << s << endl;
    }

    return 0;
}