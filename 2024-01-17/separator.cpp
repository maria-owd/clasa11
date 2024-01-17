#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int main() {
    char fraza[100];
    char *cuvant;
    char sep[] = " ,.?!";
    
    ifstream f("date.in");
    f.getline(fraza, 100);

    cout << "fraza este: " << fraza << endl;
    
    cuvant = strtok(fraza, sep); 
    while (cuvant != NULL) {
        cout << cuvant << endl;
        cuvant = strtok(NULL, sep);
    }

    return 0;
}