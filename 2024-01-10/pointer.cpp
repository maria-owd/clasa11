#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char a[100];
    char b[100];

    cout << "cuvantul 1: ";
    cin >> a;
    cout << "cuvantul 2: ";
    cin >> b;

    char aux[100];

    strcpy(aux, a);
    strcpy(a, b);
    strcpy(b, aux);
     
    cout << a << "   " << b << endl;

    return 0;
}