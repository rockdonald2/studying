//
// 2. Feladat forráskódja
//

/*
Hallgató neve: Lukács Zsolt
Csoport: 1. csoport
Feladat sorszáma: 2.
*/

#include <iostream>
#include <cmath>

int legkisebb_oszto(const int &szam);

int main() {
    /*
     * ALGORITMUS LEÍRÁSA
     *
     * Be n - Beolvassuk az n természetes számot
     * Lehív legkisebb_oszto(n) - lehívjuk a függvényt, amely kiszámolja a természetes szám legkisebb osztóját,
     *      ahol:
     *          - kiszámoljuk a szám gyökét,
     *          - megnézzük páros-e, ha az, akkor a ciklusba nem fogunk belépni
     *          - kezdve 3-től a szám gyökéig, megkeressük a szám legkisebb osztóját,
     *              az által, hogy az első számnál, ami osztja megállunk,
     *              HA,
     *                  az oszto értéke nagyobb lesz, mint a gyöké, azt jelenti, hogy a szám prím, vagy 1,
     *                  és akkor ez lesz a legkisebb osztója, vagy 1
     * Kiír a visszatérített legkisebb osztót
     * */

    // Be n
    int n;
    do {
        std::cin >> n;
    } while (n < 0);

    // Lehív legkisebb_oszto(n)
    // Visszatérés után -> Kiír legkisebb osztó
    std::cout << legkisebb_oszto(n) << std::endl;

    return 0;
}

int legkisebb_oszto(const int &szam) {
    // kiszámoljuk a szám gyökét, elegendő addig teszteli az osztást
    const int gyok = floor(pow(szam, 0.5));
    int oszto = 2;

    if (szam % oszto) {
        oszto = 3;
        // kezdve 3-től a gyökéig, megkeressük az első számot ami osztja, kettesével haladva
        while (oszto <= gyok) {
            if (!(szam % oszto)) {
                // ha osztja valamelyik szám, leállunk a ciklussal
                break;
            }

            oszto += 2;
        }
    }

    // ha az osztó nagyobb, mint a gyök akkor a szám prím, vagy 1
    if (oszto > gyok) {
        oszto = szam;
    }

    return oszto;
}