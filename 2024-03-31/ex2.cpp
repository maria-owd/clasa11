#include <iostream>
#include <cstring>
using namespace std;

int numarare(int n, int m, int a[20], int b[20]) {
    int contor = 0;
    bool toate;
    for (int i = 0; i < n; i++) {
        toate = true;
        for (int j = 0; j < m; j++) {
            if (a[i] >= b[j]) {
                toate = false;
            }
        }
        if (toate) {
            contor++;
        }
    }
    return contor;
}

int main() {
    int a[20] = {1,4,5,3,82,6,2};
    int b[20] = {56,6,34,23,8,9,12,18};
    cout << numarare(7, 8, a, b) << endl;

    return 0;
}