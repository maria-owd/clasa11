#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
int main () {
    int n, nr, v[10];
    float suma;

    ifstream f("date2.in");
    f >> n;

    for (int i = 0; i < n; i++) {
        f >> v[i];
        cout << v[i] << " ";
    }
    cout << endl;

    
    for (int i = 0; i < n; i++) {
        suma = 0;
        nr = 0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                suma = suma + v[j];
                nr++;
            }
        }
        
        cout << suma/nr << " ";
    }
    cout << endl;

    return 0;
}

