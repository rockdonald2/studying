#include <iostream>
#include "norbi.h"

using namespace std;

int main(){
    int pontszam, n;
    string neve;
    lista verseny;
    init(verseny);
    listaT *p;

    cout << "Ugrasok szama: ";
    cin >> n;

    for (int i = 0; i <= n; i++){
        cout << "Az ugro neve: ";
        cin >> neve;
        cout << endl << "Elert pontszam: ";
        cin >> pontszam;
        p = keres(verseny, pontszam);
        if (p != NULL)
            ugras1(verseny, pontszam, neve);
        else
            ugras2(verseny, pontszam, neve);
        cout << "Az elso harom versenyzo: ";
        top3(verseny);
    }

}