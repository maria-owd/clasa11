#include <iostream>
using namespace std;

void F(int &a, int b)
{
    b = b + a;
    a = a + b;
    cout << a << " " << b << " ";
}

int main()
{
    int x = 5, y = 7;
    F(x, y);
    cout << x << " " << y << " ";
    return 0;
}