#include <iostream>
using namespace std;

int a = 17;

void f(int &b) {
    int c = a + b;
    b++;
    a--;
    cout << a << endl;
}

int main() {
    int a = 10;

    f(a);

    cout << a << endl;   
}