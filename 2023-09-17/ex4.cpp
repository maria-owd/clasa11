 #include <iostream>
 #include <fstream>

using namespace std;

/**
 * un vector cu nr nat, afisati elementele vectorului
 * media aritmetica a elementelor care
 *      incep si se gata cu aceeasi cifra 
 * primul nr par si pozitia acestuia
 * ultimul nr impar si pozitia acestuia
 * apoi sa se interschimbe in vector aceste nr.
 * afisati vectorul dupa transpunere 
 */
int main() {

    int n, v[100];
    int nr;
    float suma;
    int aux, ultima, prima;

    ifstream f("date4.in");
    f >> n;

    for (int i = 0; i < n; i++) {
        f >> v[i];
    }

    cout << "vectorul este: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    // a.
    suma = 0;
    nr = 0;
    for (int i = 0; i < n; i++) {
        prima = v[i];
        while (prima > 9) {
            prima = prima/10;
        }
        ultima = v[i]%10;
        
        if (prima == ultima) {
            suma = suma + v[i];
            nr++;
        }
    }
    cout << "media: " << suma/nr << endl;

    // b.
    prima = -1;
    ultima = -1;
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 0) {
            cout << v[i] << " pe pozitia " << i << endl;
            prima = i;
            i = n; 
        }
    }

    // c.
    for (int i = n-1; i >= 0; i--) {
        if (v[i] % 2 == 1) {
            cout << v[i] << " pe pozitia " << i << endl;
            ultima = i;
            i = -1;
        }
    }

    // d.
    if (prima > -1 && ultima > -1) {
        aux = v[prima];
        v[prima] = v[ultima];
        v[ultima] = aux;
    
        cout << "vectorul nou este: ";
        for (int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    } else {
        cout << "nu se poate face permutarea" << endl;
    }
    
    return 0;
}