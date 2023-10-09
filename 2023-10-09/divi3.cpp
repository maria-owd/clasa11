#include <iostream>
using namespace std;

/**
* O functie care returneaza numarul format doar din cifrele divizibile cu 3 ale unui nr n.
    Daca nu sunt astfel de cifre, se returneaza -1.
*/

//operand
int trei(int n) {
    int cifra;
    int x, poz;

    x = 0;
    poz = 1;
    while (n > 0) {
        cifra = n % 10;
        n = n/10;

        if (cifra % 3 == 0) {
            x = x + cifra * poz;
            poz = poz * 10;
        }
    }
    if (poz == 1) {
        return -1;
    } else {
        return x;
    }
}

//procedural
void trei(int n, int &x) {
    int cifra, poz;
  
    x = 0;
    poz = 1;
    while (n > 0) {
        cifra = n % 10;
        n = n/10;

        if (cifra % 3 == 0) {
            x = x + cifra * poz;
            poz = poz * 10;
        }
    }
    if (poz == 1) {
        x = -1;
    }
}

int main() {
    int n;

    cout << "n = ";
    cin >> n;
    cout << "a) " << trei(n) << endl;
   
    int nr;
    trei(n, nr);
    cout << "b) " << nr << endl;

    return 0;
}