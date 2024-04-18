#include <iostream>
#include <cstring>
using namespace std;


int cmmdcIterativ(int a, int b) {
    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int cmmdcRecursiv(int a, int b) {
    if (b == 0) {
        return a;
    }
    return cmmdcRecursiv(b, a % b);
}

int main() {
    int x, y;
    
    cout << "primul numar: ";
    cin >> x;
    
    cout << "al doilea numar: ";
    cin >> y;
    
    cout << "iterativ: " << cmmdcIterativ(x, y) << endl;
    cout << "recursiv: " << cmmdcRecursiv(x, y) << endl;
    
    return 0;
}