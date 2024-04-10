#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;


/**
 * 1. Să se definească o structură cu numele mașina, 
 * care va conține marca mașinii(un șir de maxim 20 de  caractere), 
 * capacitatea cilindrică(un număr întreg) și data înmatriculării
 * (formată din zi, lună an) astfel încât  pentru o variabilă m definită 
 * de tip mașină să se poată accesa câmpurile astfel: 
 *      m.marca     m.capacitate        m.data.zi       m.data.an
 */
struct masina {
    char marca[20];
    int capacitate;
    struct {
        int zi,luna, an;
    } data;
} m;

/** 2. Să se definească o structură cu numele medicament, 
 * pentru care trebuie memorate următoarele  informații: 
 * denumirea(un șir de maxim 20 de caractere), 
 * prețul(un număr real) și data expirării(formată  din zi, lună an) 
 * astfel încât pentru o variabilă m definită de tip medicament 
 * să se poată accesa câmpurile  astfel: 
 *      m.denumire      m.pret      m.datae.zi      m.datae.an
*/
struct medicament {
    char denumire[20];
    float pret;
    struct {
        int zi,luna, an;
    } datae;
} m;

/**
 * 3. Să se definească o structură cu numele segment, care va conține 
 * două puncte notate A și B care formează  capetele segmentului. 
 * Pentru fiecare punct în parte se vor memora coordonatele carteziene (x, y).  
 * (numere reale). Variabila m va fi definită de tip segment astfel 
 * încât să se poată accesa câmpurile structurii  astfel: 
 *  m.A.x        m.A.y       m.B.x       m.B.y
 */
struct segment {
    struct {
        int x, y;
    } A, B;
} m;

/**
 * 4. Să se definească o structură cerc, care memorează raza(număr întreg) 
 * și coordonatele centrului cercului O(x, y) (numere reale). 
 * Definiți două variabile C1 și C2 care memorează caracteristice a 
 * două cercuri astfel  încât să se poată accesa câmpurile structurii astfel: 
 *      C1.O.x      C1.O.y      C1.raza         C2.O.y
 */
struct cerc {
    int raza;
    struct {
        int x, y;
    } O;
} C1, C2;


/** 5. Definiți o structură cu numele complex, care va memora partea reală 
 * și partea imaginară a unui număr  complex(ambele numere întregi). 
 * Definiți apoi o variabilă cu numele a care va memora informațiile celor
 * 10 numere complexe dintr-o aplicație astfel încât să se poată accesa 
 * câmpurile structurii astfel: 
 *      A[0].pr         A[0].pim
*/
struct complex {
    int pr, pim;
} A[10];

/**
 * 6. Sa se definească o structură cu numele meteo, care să memoreze temperatura 
 * maximă și minimă in  fiecare zi dintr-o lună din an. 
 * Variabila Mai păstrează temperaturile înregistrate în luna mai din 2020. 
 * Cum  trebuie declarate datele astfel încât accesul să fie: 
 *      Mai.t[1].min        Mai.t[1].max    Mai.t[2].min    Mai.t[2].min
 * 
 */
struct meteo {
    struct {
        int min, max;
    } t[12];
} Mai;

/**
 * 7. Să se definească o structură cu numele abonat, care memorează 
 * numele și prenumele fiecărui client(sir de maxim 30 de caractere) 
 * suma de plată de pe luna curentă(număr real) și două date calendaristice: 
 * data  limită până la care poate fi achitată factura curentă și 
 * data achitării facturii anterioare. 
 * Pentru fiecare dată  calendaristică se va memora luna și anul. 
 * Firma are maxim 100 de clienți. 
 * Datele de facturare ale clienților  vor fi memorate într-un vector, 
 * astfel încât accesul să fie:
 *      a[1].nume       a[2].datae.an       a[3].dataf.luna        a[4].suma
 * 
 */
struct abonat {
    char nume[30];
    float suma;
    struct {
        int luna, an;
    } datae, dataf;
} a[100];

// 8
// Să se definească o structură cu numele fracție 
// care memorează x - numitorul și y - numărătorul 
// unei fracții  aritmetice. 
// Trebuie memorate maxim 100 de fracții. 
// Definiți datele astfel încât accesul la componentele
// variabilei f să fie: 
// f.a[0].x     f.a[0].y    f.a[1].x f.a[1].y
struct fractie {
    struct {
        int x, y;
    } a[100];
} f;


/** 1. Scrieți o expresie care este adevărată dacă și numai dacă: 
a. Denumirea medicamentului are prima literă ”P” 
b. Daca este recomandat pentru ”raceala” 
c. Dacă prețul medicamentului aparține intervalului [a, b], 
    unde a, b sunt două numere întregi a<b. 
*/
bool ex1() {
    struct medicament {  
        char denumire[30];  
        char afecțiune[100]; ///tipul afecțiunii medicale 
        float pret;  
    } x; 


    if (x.denumire[0] == 'P' 
        && strcmp(x.afecțiune, "raceala") == 0
        && x.pret >= a && x.pret <= b) {
    }
}

/** 2. Se consideră următoarea declare : 
Scrieți o expresie care este adevărată dacă și numai dacă: 
a. Verifică dacă nota la limba română este mai mare decât 
    nota la matematică pentru elevul din poziția 
    a doua(vectorul este indexat de la 1) 
b. Dacă primii doi elevi au notele la matematică egale 
c. Dacă primii doi elevi au ales aceiași disciplină opțională 
*/
bool ex2() {
    struct Elev {  
        char nume[20],doptionala[10];  
        float notaR, notaM, notaO;  
    } x[30];

    if (x[2].notaR > x[2].notaM
        && x[1].notaM == x[2].notaM
        && strcmp(x[1].doptionala, x[2].doptionala) == 0);
}

/**
 * 3. Se consideră următoarea declare :  
Scrieți o expresie care este adevărată dacă și numai dacă: 
a. Cele două produse încep cu aceiași literă 
b. Dacă prețul produsului x este mai mare decât prețul produsului y 
c. Dacă produsul x mai este în stoc(cantitate diferită de zero)  
 */
bool ex3() {
    struct Produs {
        char denumire[20], categorie[20]; ///litere mici 
        float cantitate, pret;  
    } x, y; 

    if (x.denumire[0] == y.denumire[0] 
        && x.pret > y.pret
        && x.cantitate > 0);
}

/**
 * 4. Se consideră următoarea declare : 
Scrieți o expresie care este adevărată dacă și numai dacă: 
a. Punctul A se află pe prima bisectoare;
b. Punctul A se află pe abscisă; 
c. Punctul A este în originea sistemului de coordonate xOy.  
 */
bool ex4() {
    struct punct{  
        float x;  
        float y;  
    } A; 

    if (A.x == 0 && A.y == 0) // in origine
    // TODO: abcisa bisec?
}


/**
 * 5. Se consideră următoarea declare : 
Scrieți o expresie care este adevărată dacă și numai dacă: 
a. Segmentul AB este paralel cu axa Oy; 
b. Are unul din capete în origine; 
c. Se află pe axa Ox. 
 */
bool ex5() {
    struct punct{  
        float x;  
        float y;  
    } A, B; 

    // a. Segmentul AB este paralel cu axa Oy;
    if (A.x == B.x ) {} 

    // b. Are unul din capete în origine; 
    if ((A.x == 0 && A.y==0) || (B.x == 0 && B.y == 0));
    
    // c. Se află pe axa Ox. 
    if (A.y == 0 && B.y == 0);
}

/** 6 Scrieți o expresie care verifică dacă 
 * cercurile C1 și C2 sunt: 
 */
bool ex6() {
    struct punct{ 
        float x; 
        float y; 
    }; 
    struct cerc{ 
        punct O; ///coordonatele centrului cercului  
        float raza; 
    } C1,C2; 

    // a. exterioare 
    if ((C1.O.x - C2.O.x) * (C1.O.x - C2.O.x) 
        + (C1.O.y - C2.O.y) * (C1.O.y - C2.O.y) > 
        (C1.raza + C2.raza)*(C1.raza + C2.raza)) ;

    // b. tangente exterior/interior 
    if ((C1.O.x - C2.O.x) * (C1.O.x - C2.O.x) 
        + (C1.O.y - C2.O.y) * (C1.O.y - C2.O.y) == 
        (C1.raza + C2.raza)*(C1.raza + C2.raza)) ;

    // c. concentrice 
    if (C1.O.x == C2.O.x && C1.O.y == C2.O.y) {}
}

/**
 * 7. Se consideră următoarea declare:  
 Scrieți o expresie care este adevărată dacă și numai dacă 
 */
bool ex7() {
    struct punct{ 
        float x; 
        float y; 
    } P; 
    struct cerc{ 
        punct O; ///coordonatele centrului cercului  
        float raza; 
    } C1; 

    // a. Centrul cercului C1 coincide cu punctul P 
    if (C1.O.x == P.x && C1.O.y == P.y);

    // b. Punctul P este în interiorul cercului C1 
    if (abs(P.x - C1.O.x) < C1.raza
        && abs(P.y - C1.O.y < C1.raza)); // abs = modul |x|

    // c. Punctul P este în exteriorul cercului C1 
    if (abs(P.x - C1.O.x) > C1.raza
        && abs(P.y - C1.O.y > C1.raza)); 
}


/** 8. Se consideră următoarea declare: 
Scrieți o expresie care este adevărată dacă și numai dacă: 
*/
bool ex8() {
    struct punct{ 
        float x; 
        float y; 
    } P;

    struct segment{ 
        punct A,B; 
    } S; 

    struct cerc{ 
        punct O; ///coordonatele centrului cercului  
        float raza; 
    } C;

    // a. Raza cercului C este egală cu lungimea segmentului S 
    if (  (S.A.x - S.B.x)*(S.A.x - S.B.x) 
        + (S.A.y - S.B.y)*(S.A.y - S.B.y) 
        == C.raza*C.raza )

    // b. Punctul P este mijlocul segmentului S 
    if ((S.A.x + S.A.x)/2 == P.x && (S.A.y + S.B.y)/2 == P.y);

    // c. Punctul P coincide cu centrul centrului cercului C 
    if (P.x == C.O.x && P.y == C.O.y );
}

/**
 * 1. Se consideră următoarea declarare:  
    Dacă avem citite coordonatele centrelor 
    și raza pentru două cercuri C1 și C2 
 */
bool set2ex1() {
    struct punct{  
        float x;  
        float y;  
    };  
    struct cerc{ 
        punct O; ///coordonatele centrului cercului  
        float raza;  
    } C1,C2; 

    // scrieți o secvență de program care  
    // verifică dacă cele două cercuri 
    // au două puncte comune(sunt secante). 
    if ((C1.O.x - C2.O.x) * (C1.O.x - C2.O.x) 
        + (C1.O.y - C2.O.y) * (C1.O.y - C2.O.y) < 
        (C1.raza + C2.raza)*(C1.raza + C2.raza)) ;
}

/**
 *2. Se consideră un număr complex z=re + i*im. 
    Fie următoarea declarare a unui nou tip de date:  
    Dacă se cunoaște partea reală și partea imaginară a
     două numere complexe scrise în forma algebrica z1 și z2 
     scrieți o secvență de program care 
     atribuie variabilei z suma celor două numere complexe date.  
 */
void set2ex2() {
    struct complex{  
        int pre; /// partea reală a unui număr complex 
        int pim; /// partea imaginară a unui număr complex 
    }   z1, z2, z;  

    z.pre = z1.pre;
    z.pim = z1.pim;
}

/**
 *3. Se consideră un număr complex z=re + i*im. 
    Fie următoarea declarare a unui nou tip de date:  
    Dacă se cunoaște partea reală și partea imaginară a
     două numere complexe scrise în forma algebrica z1 și z2 
     scrieți o secvență de program care atribuie variabilei 
     z produsul celor două numere complexe date. 
 */
void set2ex3() {
    struct complex{  
        int pre; /// partea reală a unui număr complex 
        int pim; /// partea imaginară a unui număr complex 
    }   z1, z2, z;  

    z.pre = z1.pre * z2.pre - z1.pim * z2.pim;
    z.pim = z1.pre * z2.pim + z1.pim * z2.pre;
}



/**
 * 4. Fie următoarea declare de tip: 
Scrieți o secvență de program care calculează 
si atribuie variabilei f suma dintre cele două fracții f1 și f2. 
Nu este  nevoie de citirea datelor. 
 */
void set2ex4() {
    struct fractie{  
        int x; /// numaratorul 
        int y; /// numitorul unei fractii de forma x/y  
    } f1, f2, f;  

    f.x = f1.x * f2.y + f2.x * f1.y;
    f.y = f1.y * f2.y;
}

/**5. Se consideră următoarea declare:  
Scrieți o secvență de program care mărește 
cu 20 % prețul mașinii x și afișează pe ecran marca, 
culoarea și noul  preț.
*/
void set2ex5() {
    struct masina {  
        char marca[20], culoare[10];  
        int anF;  
        float pret;
    } x;
    x.pret = x.pret * 1.20;
    cout << x.marca << " " << x.culoare << " " << x.pret << endl;
}

/**
 * 6. Se consideră următoarea declare:  
Scrieți o secvență de program care calculează valoarea totală 
a celor n produse din depozit.(vectorul este  indexat de la 1).  
 */
void set2ex6() {
    struct produs {
        char denumire[20], categorie[20]; 
        float cantitate, pret;  
    } x[101]; 
    int n; 

    float suma = 0;
    for (int i=1; i<=n; i++) {
        suma = suma + x[i].pret;
    }
    cout << suma << endl;
}


/**
 * 7. Se consideră următoarea declare:  
Scrieți o secvență de program care calculează 
diametrul cercului C, lungimea segmentului S, 
si distanța  punctului P față de originea sistemului de coordonate xOy. 
 */
#include <iostream>
#include <cmath>
void set2p7() {
    struct punct{ 
        float x; 
        float y; 
    } P; 
    struct segment{ 
        punct A,B; 
    } S; 
    struct cerc{ 
        punct O; ///coordonatele centrului cercului 
        float raza; 
    } C; 

    float diametru = C.raza * 2;

    float lungimeS = sqrt(  (S.A.x - S.B.x)*(S.A.x - S.B.x)
                          + (S.A.y - S.B.y)*(S.A.y - S.B.y) );

    float distanta = sqrt(P.x * P.x + P.y * P.y);
}


/**
 * 8. Se consideră următoarea declare:  
unde: 
∙ în variabila P sunt memorate coordonatele unui punct în planul xOy 
∙ în variabila D se memorează coordonatele vârfului stânga sus și 
    dreapta jos a unui dreptunghi care  are laturile paralele cu axele 
    Scrieți o secvență de program care calculează aria dreptunghiului 
    și verifică dacă punctul P este unul din vârfurile dreptunghiului dat. 
 */
void set2p8() {
    struct punct{ 
        float x; 
        float y; 
    } P; 
    struct dreptunghi{ 
        punct A,B; 
    } D; 

    float lun = D.B.x - D.A.x;
    float lat = D.A.y - D.B.y;

    float Aria = lun * lat;
    
    if ( (P.x == D.A.x) && (P.y == D.A.y)
        || (P.x == D.B.x) && (P.y = D.B.y)
        || (P.x == D.B.x) && (P.y == D.A.y)
        || (P.x == D.A.x) && (P.y == D.B.y)
    ){}
}

int main() {
    strcpy(m.marca, "Audi");
    m.capacitate = 1928;
    m.data.zi = 07;
    m.data.luna = 11;
    m.data.an = 2006;

    return 0;
}
