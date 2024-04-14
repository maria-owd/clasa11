#include <iostream>
#include <cstring>
using namespace std;

int v[8] = {2, 4, 1, 3, 11, 5, 1, 3};
int impar(int n, int m)
{
    // cout << n << m;
    if (n == m)
        return v[n] % 2;
    else
        return impar(n, (n + m) / 2) + impar((n + m) / 2 + 1, m);
}
int main()
{
    cout << impar(0, 7) << endl;
}