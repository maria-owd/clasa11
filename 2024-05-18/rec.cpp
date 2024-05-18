#include <iostream>
using namespace std;


void ex1(int x) {
    if (x!=0) {
        cout << x % 10;
        ex1(x/10);
    }
}

void ex2(int x) {
    cout << x % 10;
    if (x!=0) {
        ex2(x/10);
    }
}

void ex3(int i, int j) {
    if (i <= j) {
        cout << i;
        ex3(i+1, j-1);
        if (i % 2 !=0 )
            cout << 9-j;
    }
}

void ex4(int n, int m, int &z) {
    int c;
    if (n + m > 0) {
        c = n % 10;
        if (m % 10 > c)
            c = m % 10;
        z = z * 10 + c;
        ex4 (n/10, m/10, z);
    }
}

int ex5(int x, int y) {
    if (x>y) 
        return 0;
    else
        if (x%2 == 0) 
            return (1 + ex5(x+1, y));
        else
            return ex5(x+1, y);
}

int ex6(int x, int y) {
    if (x>y) 
        return 0;
    else
        if (x%2 != 0) 
            return (1 + ex6(x+1, y));
        else
            return ex6(x+1, y);
}

int ex7(int n) {
    if (n==0) 
        return 0;
    else
        return n + ex7(n-1);
}

int ex8(int n) {
    if (n==0) 
        return 0;
    else
        return n + ex7(n-1);
}

int ex9(int n) {
    if (n==0)
        return 0;
    else {
        int c = ex9(n/10);
        if (n%10 > c)
            return n%10;
        else    
            return c;
    }
}

int ex10(int n) {
    if (n==0) 
        return 0;
    else 
        if ((n/10)%2 == 1)
            return n%10 + ex10(n/10);
        else    
            return ex10(n/10);
}

int ex11(int n) {
    if (n==0 || n==1) {
        return 1;
    } else {
        return 2 * ex11(n-1) + ex11(n-2);
    }
}

int ex12(int n) {
    if (n==0) {
        return 0;
    } else {
        return n + ex12(n-1);
    }
}

int main() {
    cout << endl << "--- EX 1 -----" << endl;
    ex1(120); // 021

    cout << endl << "--- EX 2 -----" << endl;
    ex2(120); // 0210

    cout << endl << "--- EX 3 -----" << endl;
    ex3(2, 10); //2345620

    cout << endl << "--- EX 4 -----" << endl;
    int a4 = 0;
    ex4(10542, 1821, a4);
    cout << a4; // 24811

    cout << endl << "--- EX 5 -----" << endl;
    cout << ex5(10, 30); // 11

    cout << endl << "--- EX 6 -----" << endl;
    cout << ex6(4, 12); // 4

    cout << endl << "--- EX 7 -----" << endl;
    cout << "18: " << ex7(18) << endl; // <-- 171
    cout << "31: " << ex7(31) << endl; // <-- 496
    cout << "20: " << ex7(20) << endl; // <-- 210
    cout << "17: " << ex7(17) << endl; // <-- 153!

    cout << endl << "--- EX 8 -----" << endl;
    cout << "10: " << ex8(ex8(10)) << endl; // <-- 1540
    cout << "4: " << ex8(ex8(4)) << endl; // <-- 55!
    cout << "3: " << ex8(ex8(3)) << endl; // <-- 21
    cout << "5: " << ex8(ex8(5)) << endl; // <-- 120
    
    cout << endl << "--- EX 9 -----" << endl;
    cout << ex9(23951); // 9
    
    cout << endl << "--- EX 10 -----" << endl;
    cout << "3258: " << ex10(3258) << endl; // <-- 10
    cout << "1528: " << ex10(1528) << endl; // <-- 7!
    cout << "3972: " << ex10(3972) << endl; // <-- 18
    cout << "3472: " << ex10(3472) << endl; // <-- 6
  
    cout << endl << "--- EX 11 -----" << endl;
    cout << ex11(4); // 17
    
    cout << endl << "--- EX 12 -----" << endl;
    cout << "7: " << ex12(7) << endl; // <-- 28
    cout << "8: " << ex12(8) << endl; // <-- 36
    cout << "4: " << ex12(4) << endl; // <-- 10
    cout << "6: " << ex12(6) << endl; // <-- 21 !!
  
    
    
    return 0;
}