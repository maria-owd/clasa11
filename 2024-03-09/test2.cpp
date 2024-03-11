#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    int n;
    char generic[100][10];
    char s[100][10];
    char t[200] = "";
    char *cuv;
    int gasit;
    int ok;

    ifstream f("date.in");
    f >> n;

    for (int i = 0; i < n; i++) {
        f >> generic[i];
    }
    f.getline(s, 100);

    cuv = strtok(s, " ");
    while (cuv != NULL) {
        if (cuv[0] != '*') {
            strcat(t, cuv);
            strcat(t, " ");
        } else {
            gasit = 0;
            for (int i = 0; i < n && !gasit; i++) {
                if (strlen(cuv[i]) == strlen(generic[i])) {
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