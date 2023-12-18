#include <iostream>
using namespace std;

void g(int a, int &b) {
    a+=5;
    b+=a;
}

int f(int &a, int &b)
 { while (a !=b)  
         if (a>b) a=a-b;      
         else b=b-a; 
 return a;}      

int main() {
   /* int a=4; int b=18; 
    cout<<f(a,b); cout<<a<<b;

    return 0;
    */
   
   int x,y;

    x = 1;
    y=2;
    g(x,y);
    cout << x << " " << y << " ";
    g(x,x);
    cout << x << " " << y ;

    return 0;
}