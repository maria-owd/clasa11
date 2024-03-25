#include <iostream>
#include <fstream>
using namespace std;

struct Data{
    int zi, an;
    char luna[11];
};

struct Meteo{
    float temp;
    Data d;
} x, y;

ifstream f("text.in");
void citire(Meteo &m) {
    f >> m.d.zi;
    f >> m.d.luna;
    f >> m.d.an;
    f >> m.temp;
    f.get();
}

void afisare(Meteo m) {
    cout << m.d.zi << " " << m.d.luna << " " << m.d.an << " temp " << m.temp << "˚" << endl;
}

void tempMax(Meteo m1, Meteo m2) {
    cout << "temperatura maxima: ";
    if (m1.temp > m2.temp) {
        afisare(m1);
    } else {
        afisare(m2);
    }
}

void tempMedie(Meteo m1, Meteo m2) {
    cout << "temperatura medie: " << (m1.temp + m2.temp)/2.0 << endl;;
}

int main() {
    citire(x);
    citire(y);
    afisare(x);
    afisare(y);
    tempMax(x, y);
    tempMedie(x, y);

    return 0;
}