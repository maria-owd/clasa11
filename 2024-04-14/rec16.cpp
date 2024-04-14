#include <iostream>
#include <cstring>
using namespace std;

void cifre(int n)
{
    cin >> n;
    if (n != 6)
        cifre(n);
    if (n != 2)
        cout << n;
}
int main()
{
    cifre(9);
}