#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

void p4 () {
    char s[]="aeronautic", t[20];
    for(int i = 0; i < strlen(s); i++) {
        if(strchr("aeiou",s[i])) { 
            strcpy(t,s+i+1);
            strcpy(s+i,t);
            i--;
        }
    }
   cout << s << endl;
}

void p3() {
    char s[]="avion";
    char x[] = "talon";
    char t[50];

    strcpy(t,strchr(s,'v'));
    strcpy(s,t);
    strcpy(s+2,x);
    s[5]=0;

    cout << s << endl;
}

void p5(char *x, char *y) {
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    cout << "a) " << (strcmp(y + strlen(y) - strlen(x), x) == 0) << endl;
    cout << "b) " << (strstr(x,y) != 0) << endl;
    cout << "c) " << (strstr(y,x) != 0) << endl;
    cout << "d) " << (strstr(y,x) == y) << endl;
}

int main() {
   // p3();
    p5("us", "catelus");
    return 0;
}