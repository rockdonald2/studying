//
// 6. Feladat forráskódja
//

/*
Hallgató neve: Lukács Zsolt
Csoport: 1. csoport
Feladat sorszáma: 6.
*/

using ull = unsigned long long;

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

std::vector<ull> beolvas_szamok();
std::vector<ull> lcm(const std::vector<ull> &elso_szam_p_o, const std::vector<ull> &masodik_szam_p_o);

int main() {
    /*
     * ALGORITMUS LEÍRÁSA
     * Be két szám prím osztóit
     *      - Lehívva a beolvas_szamok() függvényt,
     *          - amely beolvas egy sornyi számot, szóközökkel elválasztva, és egy stringstream-ben tárolja
     *              ahonnan kinyerjük a számokat és egy tömbben tároljuk, amit térítünk
     * Legyen lcm_p_o = a két szám primszám osztói alapján számolt lcm prím osztói,
     *      - Lehívva az lcm(elso_szam_p_o, masodik_szam_p_o) függvényt,
     *          ahol:
     *              - létrehozunk két mutatót, mindkettőt 0 indexel inicializálva,
     *              - amíg mindkét mutató értéke a tömb hosszok alatt van, ismételjük a ciklust, amelyben:
     *                      - ha a két szám megegyezik, hozzáadjuk ezt a számot egyszer az lcm tömbhöz,
     *                      - ha nem egyezik meg, a kisebbiket adjuk hozzá, a nagyobb mutatóját nem növeljük, a kisebbiket igen.
     *              - majd mivel a tömbök hossza nem feltétlen egyezik meg, azon tömbnek a maradék osztóit adjuk hozzá
     *                  az lcm-hez, amelyben még vannak megnézetlen elemek
     * Kiír lcm_p_o tömb elemei
     * */

    // Be két szám prím osztói
    auto elso_szam_p_o = beolvas_szamok();
    auto masodik_szam_p_o = beolvas_szamok();
    // Legyen lcm_p_o = a két szám primszám osztói alapján számolt lcm prím osztói

    // feltételezhetjük osztók esetében azt is, hogy ezek mindig sorrendben vannak megadva
    // mondhatni ez a rész felesleges, de ha nincsenek sorrendben az összefűzés nem helyes
    std::sort(elso_szam_p_o.begin(), elso_szam_p_o.end());
    std::sort(masodik_szam_p_o.begin(), masodik_szam_p_o.end());

    auto lcm_p_o = lcm(elso_szam_p_o, masodik_szam_p_o);

    // Kiír lcm_p_o tömb elemei
    for (const auto &i : lcm_p_o) {
        std::cout << i << ' ';
    }

    return 0;
}

std::vector<ull> beolvas_szamok() {
    std::vector<ull> tarolo;

    std::string idg_input;
    getline(std::cin, idg_input);
    std::stringstream feldolgoz_input(idg_input);

    ull szam;
    while (feldolgoz_input >> szam) {
        tarolo.push_back(szam);
    }

    return tarolo;
}

std::vector<ull> lcm(const std::vector<ull> &elso_szam_p_o, const std::vector<ull> &masodik_szam_p_o) {
    // két mutató inicializálva 0-val, ezekkel fogunk végiglépkedni a két tömbön szimultán
    int elso_mutato = 0;
    int masodik_mutato = 0;

    std::vector<ull> lcm_p_o;

    // amíg mindkét mutató értéke határon belül van
    while (elso_mutato < elso_szam_p_o.size() && masodik_mutato < masodik_szam_p_o.size()) {
        // ha az egyik prím osztó kisebb, mint a másik, a kisebbiket adjuk hozzá
        // mindig növelve a hozzáadott értékre mutató mutató értékét
        if (elso_szam_p_o[elso_mutato] < masodik_szam_p_o[masodik_mutato]) {
            lcm_p_o.push_back(elso_szam_p_o[elso_mutato++]);
        } else if (elso_szam_p_o[elso_mutato] > masodik_szam_p_o[masodik_mutato]) {
            lcm_p_o.push_back(masodik_szam_p_o[masodik_mutato++]);
        } else {
            // ha a két prím osztó megegyezik, csak egyszer adjuk hozzá
            lcm_p_o.push_back(elso_szam_p_o[elso_mutato]);
            elso_mutato++;
            masodik_mutato++;
        }
    }

    // hozzáadjuk azokat a maradék értékeket, amelyek megnézetlenek, ezek is osztói az lcm-nek

    while (elso_mutato < elso_szam_p_o.size()) {
        lcm_p_o.push_back(elso_szam_p_o[elso_mutato++]);
    }

    while (masodik_mutato < masodik_szam_p_o.size()) {
        lcm_p_o.push_back(masodik_szam_p_o[masodik_mutato++]);
    }

    return lcm_p_o;
}