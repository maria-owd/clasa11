#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
int main () {

    int n, x, s1, s2, contor;
    bool zero;
    float suma;

    ifstream f("date1.in");
    f >> n;

    contor = 0;
    suma = 0;
    zero = false;
    s1 = 0;
    s2 = 0;
    for (int i = 0; i < n; i++) {
        f >> x;
        cout << x << " ";

        if (x == 0) {
            zero = true;
        } else {
            if (zero) {
                s2 = s2 + x;
            } else {
                s1 = s1 + x;
            }
        }

        if (x % 2 == 1) {
            suma = suma + x;
            contor++;
        } 
    }
    cout << endl;
    cout << "s1 = " << s1 << " " << "s2 = " << s2 << endl;
    cout << "media = " << suma/contor << endl;
    
    return 0;
}