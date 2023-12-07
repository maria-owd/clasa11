#include <iostream>
using namespace std;

void q(int &a, int b) {
    a = (a + b)/2;
    b = (a + b)/2;
}

int main() {
    int a = 3;
    int b = 30;

    q(a, b);
    q(b, a);

    cout << a << " " << b << endl;   
}