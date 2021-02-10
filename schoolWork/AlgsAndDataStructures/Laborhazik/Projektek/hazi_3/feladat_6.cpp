//
// 6. Feladat forráskódja
//

/*
Hallgató neve: Lukács Zsolt
Csoport: 1. csoport
Feladat sorszáma: 6.
*/

#include <iostream>
#include <string>
#include <fstream>

using ull = unsigned long long;

std::string torzstenyezok(const ull &szam);
void torzstenyezo_kieg(ull &szam, const ull &elozo_oszto, const ull &kov_oszto, const int &exp_szamlalo, std::string &tarolo);

int main() {
    /* ALGORITMUS LEÍRÁSA
     * Be szam - beolvassuk a vizsgálat számot
     * Lehív torzstenyezok(szam), ahol:
     *      - törzstényezőkre bontjuk a számot
     *      - addig osztjuk a számot, 2-vel kezdve, amíg el nem érkezünk az 1-hez,
     *      - minden esetben a bemeneti paramétereket változtatva jutunk el állapotváltozáshoz:
     *          1. ll &szam - az éppen törzstényezőkre bontandó szám aktuális formája, már elosztva valamilyen számmal,
     *          2. const ll &elozo_oszto - az előző osztóját tárolja a számnak, ha nem volt ilyen, akkor -1,
     *          3. const ll &kov_oszto - a következő vizsgált osztója a számnak, ez még nem garantáltan osztója is,
     *          4. const int &exp_szamlalo - az aktuális hatványát vizsgálja az előző osztónak,
     *          5. string &tarolo - a végeredmény stringet jelenti, amely az eredményünk lesz
     *      - az algoritmuson belül, ha elérkeztünk 1-hez, akkor az a megállási feltételünk, és
     *          amennyiben az utolsó osztójának már többszörödik hatványával osztjuk, akkor ezt hozzáfűzzük a kimeneti
     *          stringhez,
     *      - a osztósági vizsgálatkor, amennyiben osztója, csak akkor fűzzük hozzá a kimeneti stringhez az osztót,
     *          amennyiben első hatványával osztjuk, ha az előző osztó is ugyanez a szám volt, már a második hatványa,
     *          vagy annál több, akkor nem adjuk hozzá
     *          Majd lehívjuk ugyanazzal a számmal újra az alprogramot, az osztósági vizsgálathoz
     *      - ha nem osztója, hozzáadjuk az aktuális hatványt, ha van ilyen, és minden esetben, ha az előtt volt egy
     *          előző osztója, akkor az elválasztót: " * ", és lehívjuk a soron következő számmal az alprogramot
     * Kiír törzstényezők
     * */

    std::ifstream bemeneti_all("be_6.txt");

    ull szam;
    if (bemeneti_all.is_open()) {
        bemeneti_all >> szam;
    } else {
        std::cout << "Nem sikerult a bemeneti allomany megnyitasa. \nEllenorizd le a bemeneti allomany eleresi utvonalat.\n";
    }

    bemeneti_all.close();

    std::ofstream kimeneti_all("ki_6.txt");

    if (kimeneti_all.is_open()) {
        kimeneti_all << torzstenyezok(szam);
    } else {
        std::cout << "Nem sikerult a kimeneti allomany megnyitasa. \nEllenorizd le a kimeneti allomany eleresi utvonalat.\n";
    }

    kimeneti_all.close();

    return 0;
}

std::string torzstenyezok(const ull &szam) {
    // végeredményt tároló string, ez fogja a törzstényezőket tartalmazó stringet jelenteni
    std::string tarolo;
    ull akt_szam = szam;

    // a rekurzív eljárás első hívása, az alapértelmezett paraméterekkel,
    // az osztósági vizsgálatot 2-től kezdjük, és nincs előző osztója a számnak
    torzstenyezo_kieg(akt_szam, -1, 2, 0, tarolo);

    return tarolo;
}

void torzstenyezo_kieg(ull &szam, const ull &elozo_oszto, const ull &kov_oszto, const int &exp_szamlalo, std::string &tarolo) {
    if (szam == 1) {
        // ha szam == 1 akkor megkaptuk az összes törzstényezőt, végeredmény

        // ha azt megelőzően az előző osztó többszörödik hatványnál járt,
        // akkor ezt a hatványt hozzáadjuk
        if (exp_szamlalo >= 2) {
            tarolo += "^" + std::to_string(exp_szamlalo);
        }

        // akkor teljesül, ha a szam == 1, mint bemeneti adat
        if (tarolo == "") {
            tarolo += std::to_string(szam);
        }
    } else {
        if (!(szam % kov_oszto)) {

            // ha osztója a jelenlegi kov_oszto a számnak, csak akkor adjuk hozzá, ha első hatványadikkor fordult elő
            if (elozo_oszto != kov_oszto) {
                tarolo += std::to_string(kov_oszto);
            }

            szam /= kov_oszto;

            // lehívjuk a rekurzív eljárást ugyanazzal az osztóval, de már következő hatvánnyal
            torzstenyezo_kieg(szam, kov_oszto, kov_oszto, exp_szamlalo + 1, tarolo);
        } else {
            // ha az előző osztó többszörödik hatványnál járt, akkor a hatványt hozzáadjuk
            if (exp_szamlalo >= 2) {
                tarolo += "^" + std::to_string(exp_szamlalo);
            }

            // ha min 1-szer osztotta a számot a jelenlegi vizsgált szám, akkor hozzáadjuk az elválasztót
            if (exp_szamlalo >= 1) {
                tarolo += " * ";
            }

            // lehívjuk a soron következő számmal a rekurzív eljárást
            torzstenyezo_kieg(szam, elozo_oszto, kov_oszto + 1, 0, tarolo);
        }
    }
}