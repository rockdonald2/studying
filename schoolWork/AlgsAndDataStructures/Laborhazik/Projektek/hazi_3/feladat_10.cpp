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
     *      - négyzetgyököt számolunk 6 tizedes pontosággal rekurzívan, 6 tizedes pontosággal kiírva
     *      - a rekurzív eljárás 3 paramétert használ:
     *          1. const int &n - az aktuális pontossági szint
     *          2. const ld &szam - az aktuális vizsgált szám, amelynek a gyökét számoljuk,
     *          3. map<int, ld> &memo - ideiglenes tároló, ez teszi lehetővé, hogy a különböző pontossági szinteket tároljuk
     *              és később őket összevessük a megállási feltétel beállításához;
     *              Majd a végén innen is térítünk.
     *      - a rekurzív függvényrész az xn = 0.5 * (xn-1 + a/xn-1), amelynek a megállási feltételeze az, hogy
     *          eljutottunk ahhoz, hogy xn és xn-1 közötti különbség kisebb, mint epszilon(0,000001)
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
    std::map<int, ld> memo;

    // a 0. pontossági szint a számmal egyezik meg
    memo[0] = szam;

    // 0. pontosságról építjük fel a gyökünket
    return negyzetgyok_kieg(1, szam, memo);
}

ld negyzetgyok_kieg(const int &n, const ld &szam, std::map<int, ld> &memo) {
    // kiszámoljuk az aktuális pontossági szintnek megfelelő értéket
    memo[n] = 0.5 * (memo[n - 1] + szam / memo[n - 1]);

    // ha a különbség ennél nagyobb, számottevően változott két iteráció között az érték, még nem jutottunk el a megfelelő pontossághoz
    if ((memo[n - 1] - memo[n]) > 0.000001) {
        return negyzetgyok_kieg(n + 1, szam, memo);
    } else {
        // ha nem változik számottevően megvan a 6 tizedes pontosság, téríthetünk
        return memo[n];
    }
}