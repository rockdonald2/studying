//
// 10. Feladat forráskódja
//

/*
Hallgató neve: Lukács Zsolt
Csoport: 1. csoport
Feladat sorszáma: 10.
*/

#include <iostream>
#include <map>
#include <iomanip>
#include <fstream>

using ull = unsigned long long;
using ld = long double;

ld negyzetgyok(const ull &szam);
ld negyzetgyok_kieg(const int &n, const ld &szam, std::map<int, ld> &memo);

int main() {
    /* ALGORITMUS LEÍRÁSA
     * Be szám - beolvassa az aktuális bemeneti számot
     * Lehív negyzetgyok(szam), ahol:
     *      - négyzetgyököt számolunk 20 tizedes pontosággal rekurzívan, 6 tizedes pontosággal kiírva
     *      - a rekurzív eljárás 3 paramétert használ:
     *          1. const int &n - az aktuális pontossági szint
     *          2. const ld &szam - az aktuális vizsgált szám, amelynek a gyökét számoljuk,
     *          3. map<int, ld> &memo - ideiglenes tároló, amely azt előzi meg, hogy kétszer kelljen ugyanazt a rekurzív függvényrészt
     *              lehívni. Megakadályozza, hogy ugyanazzal a paraméterrel kétszer hívjuk meg a függvényt,
     *              mert lementjük a paraméternek megfelelő értéket.
     *      - a rekurzív függvényrész az xn = 0.5 * (xn-1 + a/xn-1), amelynek a megállási feltételeze az, hogy
     *          eljutottunk a 0. tizedes pontossághoz, ami = a kezdeti számunk, és az n = 0 paraméterérték.
     *      - a rekurzív függvény lényegében 0. tizedespontosságtól kezdve építi fel a pontossági szinteket, a matematikai
     *          leírásnak megfelelően
     * Kiír szám gyöke
     * */

    std::ifstream bemeneti_all("be_10.txt");

    ull szam;
    if (bemeneti_all.is_open()) {
        bemeneti_all >> szam;
    } else {
        std::cout << "Nem sikerult a bemeneti allomany megnyitasa. \nEllenorizd le a bemeneti allomany eleresi utvonalat.\n";
    }

    bemeneti_all.close();

    std::ofstream kimeneti_all("ki_10.txt");

    if (kimeneti_all.is_open()) {
        kimeneti_all << std::fixed << std::setprecision(5) << negyzetgyok(szam);
    } else {
        std::cout << "Nem sikerult a kimeneti allomany megnyitasa. \nEllenorizd le a kimeneti allomany eleresi utvonalat.\n";
    }

    kimeneti_all.close();

    return 0;
}

ld negyzetgyok(const ull &szam) {
    // hány ismétlési szint történjen,
    // ennyi tizedesig lesz pontos a végső eredményünk
    const int pontossag = 20;
    // akár 6-szeres pontosságot is alkalmazhatnánk, de a feladat csak a kiírásra vonatkozik és a művelet ismétlésére nem

    // ideiglenes tároló, amely egy adott paraméterösszetételnek megfelelő értéket tárolja,
    // megelőzve, hogy kétszer hívjuk meg a rekurzív függvényt ugyanazzal a paraméterrel
    std::map<int, ld> memo;

    return negyzetgyok_kieg(pontossag, szam, memo);
}

ld negyzetgyok_kieg(const int &n, const ld &szam, std::map<int, ld> &memo) {
    if (n == 0) {
        // megállási feltétel, ha eljutottunk a 0. tizedesnyi szintig, amely a kezdeti számmal egyezik meg
        return szam;
    }

    // lementjük az aktuális értéket, a paraméterértéknek megfelelően
    memo[n - 1] = negyzetgyok_kieg(n - 1, szam, memo);

    // majd végrehajtjuk a matematikai részt
    return 0.5 * (memo[n - 1] + szam / memo[n - 1]);

    /*
     * Ezt úgy kell elképzelni, hogy az első lehíváskor az n egészen 0-ig fog csökkenni, eljutunk a 0. tizedesnyi pontossághoz,
     * majd innen haladunk visszafelé, lementve az aktuális xn-1 értéket a memo-ba a függvénynek megfelelően,
     * minden egyes újabb xn iteráció, egy újabb pontossági szintet eredményez
     * */
}