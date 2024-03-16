#include <iostream>
#include <fstream>
using namespace std;

struct fractie {
    int x, y;
};

float distanta(fractie a, fractie b) {
    int dx, dy;

    dx = a.x - b.x;
    dy = a.y - b.y;

    return sqrt(dx*dx + dy*dy);
}

void afisare(char nume, fractie coord) {
    cout << nume << "(" << coord.x << ", " << coord.y << ")";
}

int main() {
    fractie a, b;

    ifstream f("date2.in");
    f >> a.x;
    f >> a.y;
    f >> b.x;
    f >> b.y;

    cout << "distanta: "; 
    afisare('A', a);
    cout << " - ";
    afisare('B', b);
    cout << " = " << distanta(a, b) << endl;

    return 0;
}