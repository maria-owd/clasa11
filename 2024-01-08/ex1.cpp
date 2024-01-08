#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int n;
    char s[100];
    int maxim;

    cout << "cate cuvinte citim: ";
    cin >> n;

    cin.ignore(); // ignora 0

    maxim = 0;
    for (int i = 0; i < n; i++) {
        cout << "cuvantul " << i+1 << ": ";
        cin.getline(s, 100);
        cout << s << " " << strlen(s) << endl;

        if (strlen(s) > maxim) {
            maxim = strlen(s);
        }
    }
    cout << maxim << endl;
    
    return 0;
}