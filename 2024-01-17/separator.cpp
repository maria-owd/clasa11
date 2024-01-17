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
    
    cuvant = strtok(fraza, sep);    // primul apel => primul cuvant
    while (cuvant != NULL) {        // cuvant = NULL => s-a terminat fraza
        cout << cuvant << endl;     // procesarea cuvantului curent
        cuvant = strtok(NULL, sep); // urmatoarele cuvinte (NULL = de la ultima apelare)
    }

    return 0;
}