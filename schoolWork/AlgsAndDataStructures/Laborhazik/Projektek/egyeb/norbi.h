#include <iostream>

using namespace std;

struct listaT{
    string nev;
    int pont;
    listaT *kov;
};

struct lista{
    listaT *fej;
    listaT *uto;
};

void init(lista &verseny){
    verseny.fej = NULL;
    verseny.uto = NULL;
}

listaT* keres(lista verseny, int pontszam){
    listaT *p;
    bool nincs = true;
    new listaT;
    p = verseny.fej;
    while (nincs && p){
        if (p->pont > pontszam)
            nincs = false;
        else
            p = p->kov;
    }
    return p;
}

//uj ugras bejegyzese
void ugras1(lista &verseny, int pontszam, string ujnev){
    listaT *p = new listaT;
    keres(verseny, pontszam);
    listaT *q = new listaT;
    *q = *p;
    p->nev = ujnev;
    p->pont = pontszam;
    if (p == verseny.uto)
        verseny.uto = q;
}

void ugras2(lista &verseny, int pontszam, string ujnev){
    listaT *p = new listaT;
    p->pont = pontszam;
    p->nev = ujnev;
    p->kov = NULL;
    verseny.uto->kov = p;
    verseny.uto = p;
}

//elso 3 ugras kiirasa
void top3(lista &verseny){
    if (verseny.fej->kov->kov){
        listaT *p = verseny.fej;
        for (int i = 1; i <= 3; i++){
            cout << p->nev << "versenyzo pontszama: " << p->pont << endl;
            p = p->kov;
        }
    }
    else cout << "Meg nem tortent meg 3 ugras";
}
