/** HOLGYES ORSOLYA DOROTTYA
GI, 1. csoport, 3921
Kolozsváron tapasztalhattátok, hogy a 25-ös mindig tele van. Annyira, hogy amikor valaki le szeretne szállni akkor
mások is le kell szálljanak hogy helyet adjanak. Közben a megállóban is tolakodnak felfelé.
Tároljuk a buszon tartózkodó személyeket egy veremben, valamint a le-felszállni kívánkozó személyeket várakozási sorban.
Első lépésben inicializáljuk a buszon tartózkodókat a veremben.

A folyamat a következő:

- Beolvassa a leszálló személyeket majd tárolja(lehet bármilyen dinamikus adatszerkezet pl. lista, várakozási sor)

- Beolvassa a felszálló személyeket majd tárolja a várakozási sorban

- A verem tetejétől kezdve "szállítja le" a személyeket a buszról majd akik nem szeretnének végleg leszállni bekerülnek
a felszállók várakozási sorába.

- Miután az összes leszállni kívánkozó személy kikerül a leszállok várakozási sorából a felszállók "felülnek"
(bekerülnek a verembe)

- Ez addig ismétlődik míg a busz ki nem ürül vagy ki nem lépűnk egy erre megadott opcióval.

Minden megállóban legalább 1 személy fel vagy leszáll, de  fel/leszállhat több is.**/

#include <iostream>
#include "orsi.h"
using namespace std;

void leszall(BuszonLevok *& buszon, Leszallok *& le, Felszallok *& fel)
{
    NevTipus nev;
    cout << "\nAdd meg a leszallokat egy szokozzel elvalsztva * vegjelig: ";
    cin >> nev;
    while (nev != "*")
    {
        UjLeszallo(le, nev);
        cin >> nev;
    }
    cin.get();
}

void felszall(BuszonLevok *& buszon, Felszallok *& fel)
{
    NevTipus nev;
    cout << "\nAdd meg a felszallokat egy szokozzel elvalsztva * vegjelig: ";
    cin >> nev;
    while (nev != "*")
    {
        UjFelszallo(fel, nev);
        cin >> nev;
    }
    cin.get();
}

int main()
{
    BuszonLevok * buszon = new BuszonLevok;
    inicializal_buszon_levok(buszon);
    Leszallok * le = new Leszallok;
    inicializal_leszallok(le);
    Felszallok * fel = new Felszallok;
    inicializal_felszallok(fel);
    int sorszam;
    bool kilep = false;
    do
    {
        cout <<"Valaszd ki a kivant muvelet sorszamat az alabbiak kozul:\n1 - Uj megallo \n2 - Kilepes\nMuvelet sorszama = ";
        cin >> sorszam;
        cin.get();
        switch (sorszam)
        {
            case 1: // új megálló
            {
                KiirBuszonLevok(buszon);
                leszall(buszon, le, fel);
                felszall(buszon, fel);
                // KiirLeszallok(le);
                // KiirFelszallok(fel);
                // Felszallas(buszon, fel);
                Megallo(buszon, le, fel);
                KiirBuszonLevok(buszon);
                cout << "\n\nNyomj egy Entert hogy visszalepj a menube!";
                cin.get();
                break;
            }
            default: //kilepes
            {
                kilep = true;
            }
        }
        system("cls");
    } while (!kilep && !ures_buszon_levok(buszon));
    return 0;
}
