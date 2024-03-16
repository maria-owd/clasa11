#include <iostream>
#include <fstream>
using namespace std;

struct fractie {
    int p, q;
};

fractie suma(fractie a, fractie b) {
    fractie s;

    s.p = a.p * b.q + b.p * a.q;
    s.q = a.q * b.q;

    return s;
}

void afisare(char nume, fractie f) {
    cout << nume << "=" << f.p << "/" << f.q << endl;
}

int main() {
    fractie f, g, h;

    ifstream fin("date3.in");
    fin >> f.p;
    fin >> f.q;
    fin >> g.p;
    fin >> g.q;

    afisare('F', f);
    afisare('G', g);

    h = suma(f, g);
    afisare('H', h);

    return 0;
}