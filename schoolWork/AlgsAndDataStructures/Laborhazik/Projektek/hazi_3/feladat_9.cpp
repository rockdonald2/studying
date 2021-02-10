//
// 9. Feladat forráskódja
//

/*
Hallgató neve: Lukács Zsolt
Csoport: 1. csoport
Feladat sorszáma: 9.
*/

using ll = long long;

#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

ll orosz_szorzas(const ll &szam1, const ll &szam2);

int main() {
    /* ALGORITMUS LEÍRÁSA
     * Be szam1, szam2 - beolvassuk a vizsgált számokat, amelyek összeszorzunk
     * Lehív orosz_szorzas(szam1, szam2), ahol:
     *      - mindig az lesz az első paraméterje a rekurzív függvénynek, amelynek az értéke kisebb,
     *          így biztosítjuk, hogy a legkevesebb lépésszám kelljen az eredményhez való eljutáshoz
     *      - a rekurzív függvényen belül, az 1-vel való egyenlőség a megállási feltétel,
     *          amíg eljutunk 1-ig mindig a kisebbik számot osszuk kettővel, míg a nagyobbat szorozzuk kettővel;
     *              - az orosz szorzási módszer szerint a páratlan szam2 értékekek összege képezi a szorzás eredményét,
     *                  így csak azokat adjuk hozzá az eredményhez;
     * Kiír szorzási eredmény
     * */

    std::ifstream bemeneti_all("be_9.txt");

    ll szam1;
    ll szam2;
    if (bemeneti_all.is_open()) {
        bemeneti_all >> szam1 >> szam2;
    } else {
        std::cout << "Nem sikerult a bemeneti allomany megnyitasa. \nEllenorizd le a bemeneti allomany eleresi utvonalat.\n";
    }

    bemeneti_all.close();

    std::ofstream kimeneti_all("ki_9.txt");

    // mindig a szam1 kell a kisebbik paraméter legyen, biztosítva a minimális ismétlésszámot az eredményhez való eljutáshoz
    if (szam1 > szam2) {
        std::swap(szam1, szam2);
    }

    if (kimeneti_all.is_open()) {
        kimeneti_all << orosz_szorzas(szam1, szam2);
    } else {
        std::cout << "Nem sikerult a kimeneti allomany megnyitasa. \nEllenorizd le a kimeneti allomany eleresi utvonalat.\n";
    }

    kimeneti_all.close();

    return 0;
}

ll orosz_szorzas(const ll &szam1, const ll &szam2) {
    // a megállási feltételünk az 1-el való egyenlőség
    if (szam1 == 1) {
        return szam2;
    } else if (szam1 % 2) {
        // amennyiben a jelenlegi szam1 szám páratlan, akkor az aktuális szam2 szám az eredmény részét fogja képezni
        return szam2 + orosz_szorzas(std::floor(szam1 / 2), szam2 * 2);
    }

    // ha a jelenlegi szam1 szám páros, akkor a szam2 paraméter értéke az eredmény részét nem képezi
    return orosz_szorzas(std::floor(szam1 / 2), szam2 * 2);
}