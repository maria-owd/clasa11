#include <iostream>
using namespace std;

// a)
void inversat(int n, int v[100]) {
    int aux;
    for (int i = 0; i <= n/2; i++) {
        aux = v[i];
        v[i] = v[n-1-i];
        v[n-1-i] = aux;
    }
}

void citire(int &n, int v[100]) {
    cout << "n = ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "nr " << i+1 << ": ";
        cin >> v[i];
    }
}

void afisare(int n, int v[100]) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// b)
int fibonacci(int n) {
    int u, p, aux;

    if (n == 0) {
        return 0;
    }

    u = 1;
    p = 0;
    for (int i = 1; i < n; i++) {
        aux = u;
        u = u + p;
        p = aux;
    }
    return u;
} 

int main () {
    int elemente, a[100];
    int f;
    
    // a)
    citire(elemente, a);
    inversat(elemente, a);
    afisare(elemente, a);
    
    // b)
    cout << "al catelea element fibonacii: ";
    cin >> f;
    cout << fibonacci(f) << endl;

    return 0;
}