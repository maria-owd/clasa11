#include <iostream>
#include <cstring>
using namespace std;

int u[6] = {3, -5, 6, -4, 7, -4};
int n = 6;
int ex=0;

int alt(int k, int i)
{
    cout << "ex " << (ex++) << endl;
    if (i > n - 1) {
        return 1;
    } else { 
        if ((u[i] >= 0) && k)
            return 0;
        else
            return alt(!k, ++i);
    }
}
int main()
{
    cout << alt(0,1);
}