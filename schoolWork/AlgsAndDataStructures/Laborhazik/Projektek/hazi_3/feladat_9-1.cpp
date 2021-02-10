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
#include <cmath>

ll orosz_szorzas(const ll &szam1, const ll &szam2);
void orosz_szorzas_kieg(const ll &szam1, const ll &szam2, ll &eredmeny);

int main() {
    /* ALGORITMUS LEÍRÁSA
     * Be szam1, szam2 - beolvassuk a vizsgált számokat, amelyek összeszorzunk
     * Lehív orosz_szorzas(szam1, szam2), ahol:
     *      - mindig az lesz az első paraméterje a rekurzív eljárásnak, amelynek az értéke kisebb,
     *          így biztosítjuk, hogy a legkevesebb lépésszám kelljen az eredményhez való eljutáshoz
     *      - a rekurzív eljáráson belül, amíg az első paraméterérték nem 0, osztjuk a kisebbik számot,
     *          2-vel, a maradékot elhagyva, a nagyobbikat szorozzuk 2-vel, lehívva újra az eljárást,
     *      - azonban, minden ismétléskor, ha az aktuális szam1 paraméterérték páratlan, hozzáadjuk az eredményhez,
     *          ez jelenti a szorzás műveletet jelenleg,
     *              ! ezt már az első lehíváskor is megejtjük, tehát, ha már a bemeneti paraméterérték
     *                is páratlan, akkor a kezdeti szam2 értéket is hozzáadjuk az eredményhez
     * */

    ll szam1;
    ll szam2;
    std::cin >> szam1 >> szam2;

    std::cout << orosz_szorzas(szam1, szam2) << '\n';

    return 0;
}

/*ll orosz_szorzas(const ll &szam1, const ll &szam2) {
    // a végső szorzáseredményünket tároló változó
    ll eredmeny = 0;

    // mindig az első az első paraméterünk, amelyik kisebb, a második a nagyobbik érték
    (szam1 > szam2) ? orosz_szorzas_kieg(szam2, szam1, eredmeny) : orosz_szorzas_kieg(szam1, szam2, eredmeny);

    return eredmeny;
}*/

ll orosz_szorzas(const ll &szam1, const ll &szam2) {
    // amíg az első paraméterünk, amelyet osztunk 2-vel, nem 0, folytatjuk az eljárást
    if (szam1 == 1) {
        return szam2;
    } else if (szam1 % 2) {
        // ha páratlan az aktuális szam1 paraméterérték hozzáadjuk az eredményhez a nagyobbik paramétert, ha nem, nem teszünk semmit
        return szam2 + orosz_szorzas(std::floor(szam1 / 2), szam2 * 2);
    }

    // elvégezzük a folyamat lényegét, a nagyobbik számot szorozzuk 2-vel,
    // a kisebbiket pedig osztjuk 2-vel és lehívjuk újra az eljárást
    return orosz_szorzas(std::floor(szam1 / 2), szam2 * 2);
}

/*
 * void orosz_szorzas_kieg(const ll &szam1, const ll &szam2, ll &eredmeny) {
    // amíg az első paraméterünk, amelyet osztunk 2-vel, nem 0, folytatjuk az eljárást
    if (szam1 == 0) {
        return;
    } else if (szam1 % 2) {
        // ha páratlan az aktuális szam1 paraméterérték hozzáadjuk az eredményhez a nagyobbik paramétert, ha nem, nem teszünk semmit
        eredmeny += szam2;
    }

    // elvégezzük a folyamat lényegét, a nagyobbik számot szorozzuk 2-vel,
    // a kisebbiket pedig osztjuk 2-vel és lehívjuk újra az eljárást
    orosz_szorzas_kieg(std::floor(szam1 / 2), szam2 * 2, eredmeny);
}
 * */