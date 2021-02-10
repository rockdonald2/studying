#ifndef BUSZLEFELSZALLAS_H_INCLUDED
#define BUSZLEFELSZALLAS_H_INCLUDED

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
using namespace std;

typedef string NevTipus;

struct szemely
{
    NevTipus nev;
    szemely * kov;
};

struct BuszonLevok //verem
{
    szemely * elso;
};

struct Leszallok //lista
{
    szemely * elso;
    szemely * utolso;
};

struct Felszallok //várakozási sor
{
    szemely * elso;
    szemely * utolso;
};

void inicializal_buszon_levok (BuszonLevok *& buszon)
{
    buszon -> elso = NULL;
}

void inicializal_leszallok(Leszallok *& le)
{
    le -> elso = NULL;
    le -> utolso = NULL;
}

void inicializal_felszallok(Felszallok *& fel)
{
    fel -> elso = NULL;
    fel -> utolso = NULL;
}

bool ures_buszon_levok (BuszonLevok * buszon) //igazat térít ha üres a verem, különben hamisat
{
    if (buszon -> elso == NULL) return true;
    else return false;
}

bool ures_leszallok (Leszallok * le) //igazat térít ha üres a lista, különben hamisat
{
    if (le -> elso == NULL) return true;
    else return false;
}

bool ures_felszallok (Felszallok * fel) //igazat térít ha üres a rendezett lista, különben hamisat
{
    if (fel -> elso == NULL) return true;
    else return false;
}

void UjBuszraSzallo (BuszonLevok *& buszon, NevTipus ujnev) // beszúr a verembe
{
    szemely * uj = new szemely;
    uj -> nev = ujnev;
    uj -> kov = buszon -> elso;
    buszon -> elso = uj;
}

void UjLeszallo (Leszallok *& le, NevTipus ujnev) // beszúr a listába
{
    szemely * uj = new szemely;
    uj -> nev = ujnev;
    uj -> kov = NULL;
    if (ures_leszallok(le)) le -> elso = uj;
    else le -> utolso -> kov = uj;
    le -> utolso = uj;
}

void UjFelszallo (Felszallok *& fel, NevTipus ujnev) //beszúr a várakozási sorba
{
    szemely * uj = new szemely;
    uj -> nev = ujnev;
    uj -> kov = NULL;
    if (ures_felszallok(fel)) fel -> elso = uj;
    else fel -> utolso -> kov = uj;
    fel -> utolso = uj;
}

void TorolBuszonLevot (BuszonLevok *& buszon) //töröl a veremből - mindig a tetejéről
{
    szemely * seged = buszon -> elso;
    buszon -> elso = buszon -> elso -> kov;
    delete seged;
}

void TorolLeszallot (Leszallok *& le, szemely * hely) //töröl a listából adott helyről
{
    if (hely == le -> elso) //ha az első tagot kell töröljem
    {
        le -> elso = le -> elso -> kov;

        if (le->elso == NULL) le->utolso = NULL;

        delete hely;
    }
    else if (hely -> kov == NULL) // ha az utolsó tagot kell töröljem
    {
        szemely * seged = le -> elso;
        while (seged -> kov -> kov)
        {
            seged = seged -> kov;
        }
        seged -> kov = NULL;
        le -> utolso = seged;
        delete hely;
    }
    else
    {
        szemely * seged = hely -> kov;
        * hely = * hely->kov;
        if (seged == le -> utolso) le -> utolso = hely; // ha kitöröltem az utolsó előttit, az utolsó pointert előrébb kell tegyem, mert az eredeti utolsót rámásoltam az utolsó előttire
        delete seged;
    }
}

void TorolOsszesFelszallot (Felszallok *& fel) //kiüríti a felszállók listáját
{
    while (fel -> elso)
    {
        szemely * seged = fel -> elso;
        fel -> elso = fel -> elso -> kov;
        delete seged;
    }
}

szemely * KeresLeszallot (Leszallok * le, NevTipus keresett) //visszatéríti a címét a leszálló személynek vagy NULL-t ha nem kapott ilyen személyt
{
    szemely * lepegeto = le -> elso;
    bool talalt = false;
    while (lepegeto && !talalt)
    {
        if (keresett == lepegeto -> nev) talalt = true;
        else lepegeto = lepegeto -> kov;
    }
    return lepegeto;
}

void Leszallas(BuszonLevok *& buszon, Leszallok *& le, Felszallok *& fel) // a verem tetején levő személyt megkeresi a leszállók listájában. Ha nem kapja meg, azt jelenti, hogy vissza kell szálljon az adott személy a buszra és ezért a felszállókhoz teszem. Ha megkapja a személyt a leszállók listáján, akkor törlöm innen a nevét. Minden esetben törlöm a verem tetején levő személyt.
{
    szemely * lepegeto = buszon -> elso; // a lépegetővel a vermen megyek ameddig a verem ki nem ürül vagy ameddig a leszállók listája ki nem ürül
    while (!ures_leszallok(le) && !ures_buszon_levok(buszon))
    {
        szemely * hely = KeresLeszallot(le, lepegeto -> nev);
        //megnézem ha az adott személy (a verem tetején) le szeretne-e szállni az adott megállónál, vagyis benne van-e a leszállók névsorában
        if (hely) //vagyis az adott személy le szeretne leszállni
            //ha le szeretne szállni, törlöm a leszállók listájából és a veremből. Különben a Felszallo várakozási sor végére kerül és utána törlöm a veremből. Mivel minden esetben törlök a veremből, ezért ezt az if-en kívülre teszem
            TorolLeszallot(le, hely);
        else
            UjFelszallo(fel, lepegeto -> nev);
        // a személyt aki aktuálisan a verem tetején van, törölni is kell a veremből, hiszen vagy véglegesen távozik vagy átkerült a felszállók várakozási lista végére
        lepegeto = lepegeto -> kov;
        TorolBuszonLevot(buszon);
    }
}

void Felszallas(BuszonLevok *& buszon, Felszallok *& fel) // a felszállók várakozási sorából az elsőt mindig beteszem a verembe, míg nem lesz több felszállóm.
/*FELTÉTEL: a busz kapacitása végtelen */
{
    szemely * lepegeto = fel -> elso;
    while (lepegeto)
    {
        UjBuszraSzallo(buszon, lepegeto -> nev);
        lepegeto = lepegeto -> kov;
    }
    TorolOsszesFelszallot(fel);
}

void Megallo(BuszonLevok *& buszon, Leszallok *& le, Felszallok *& fel)
{
    Leszallas(buszon, le, fel); //leszállnak az emberek
    Felszallas(buszon, fel); //felszállnak az emberek
}

void KiirBuszonLevok (BuszonLevok * buszon)
{
    if (ures_buszon_levok(buszon)) cout << "A busz ures.";
    else
    {
        cout << "A buszon levo szemelyek:\n";
        szemely * lepegeto = buszon -> elso;
        while (lepegeto)
        {
            cout << lepegeto -> nev << "\n";
            lepegeto = lepegeto -> kov;
        }
        cout << endl;
    }

}

void KiirLeszallok (Leszallok * le)
{
    cout << "Leszallo szemelyek:\n";
    szemely * lepegeto = le -> elso;
    while (lepegeto)
    {
        cout << lepegeto -> nev << "\n";
        lepegeto = lepegeto -> kov;
    }
}

void KiirFelszallok (Felszallok * fel)
{
    cout << "Felszallo szemelyek:\n";
    szemely * lepegeto = fel -> elso;
    while (lepegeto)
    {
        cout << lepegeto -> nev << " ";
        lepegeto = lepegeto -> kov;
    }
}

#endif // BUSZLEFELSZALLAS_H_INCLUDED
