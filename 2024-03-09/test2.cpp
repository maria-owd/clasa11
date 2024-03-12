#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    int n;
    char generic[100][10];
    char s[100];
    char t[200] = "x: ";
    char *cuv;
    int gasit;
    int ok;

    ifstream f("date2.in");
    f >> n;

    for (int i = 0; i < n; i++) {
        f >> generic[i];
        cout << generic[i] << endl;
    }
    f.get();
    f.getline(s, 100);
    cout << s << endl;
    cuv = strtok(s, " ");
    while (cuv != NULL) {
        if (cuv[0] != '*') {
            strcat(t, cuv);
            strcat(t, " ");
        } else {
            gasit = 0;
            for (int i = 0; i < n && !gasit; i++) {
                if (strlen(cuv) == strlen(generic[i])) {
                    strcat(t, generic[i]);
                    strcat(t, " ");
                    gasit = 1;
                }
            }
            if (!gasit) {
                ok = 0;
            }
        }
        cuv = strtok (NULL, " ");
    }
    if (ok) {
        cout << t << endl;
    } else {
        cout << "imposibil";
    }

    return 0;
}