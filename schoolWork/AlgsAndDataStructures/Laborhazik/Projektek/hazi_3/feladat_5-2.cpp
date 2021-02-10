//
// 5. Feladat forráskódja
//

/*
Hallgató neve: Lukács Zsolt
Csoport: 1. csoport
Feladat sorszáma: 5.
*/

#include <iostream>
#include <vector>
#include <fstream>

using ll = long long;

std::string volgyszam_vizsgalat(std::vector<ll> &szamjegyek);
std::vector<ll> atalakit_tombbe(ll szam);

int main() {
    /* ALGORITMUS LEÍRÁSA
     *  Be szam - beolvassuk a bemeneti számot,
     *  Lehív atalakit_tombbe(szam), ahol:
     *      - átalakítjuk a bemeneti számot egy tömbbé, hiszen a műveleteinket könnyebben tudjuk
     *          ebben a típusban elvégezni
     *      - repetítiven 10-el osszuk, a maradékot pedig a tömbbe helyezzük
     *      - akár ezt megtehetnénk a völgyszámvizsgálat alprogramon belül is
     *  Lehív volgyszam_vizsgalat(szamjegyek), ahol:
     *      - vizsgáljuk a völgyszám/hegyszám feltételeket
     *      - a végső ítéletünket az alprogramon belépesekor létrehozott két változó alapján döntjük el:
     *          - ahol az első az alsó határt jelöli, ahonnan vizsgáljuk a számokat,
     *              kezdetben ez a szám első számjegye, ami később tolódhat, amennyiben számokat kell levágnunk
     *          - a második az éppen aktuális vizsgálat alanyt tartalmazza, tehát, hogy milyen természetet
     *              völgyszám/hegyszám természetet vizsgálunk
     *      - a valós vizsgálat a while-on belül, ahol:
     *          - minden iterációkor megvizsgáljuk milyen természetet vizsgálunk az aktuális alsó határnak megfelelően,
     *              ha az első két szám növekedik akkor hegyszám lehet, ha csökken völgyszám
     *          - mindig megvizsgáljuk a jelenlegi természet kialakulhat-e,
     *              - ez alatt azt kell érteni, hogy a szám vége megfelel-e az adott természetnek,
     *                  hegyszám esetén ez csökkenő sort jelent,
     *                  völgyszámkor növekvő sort.
     *          - majd leellenőrízzük teljesíti-e a szám az adott természetet, ha nem, addig vágjuk le az elejéről
     *              a számokat, amíg természetet nem vált, és akkor újraindítjuk a vizsgálatot
     *          - ha teljesíti a feltételeket, kilépünk, és meghozzuk a végső ítéletet:
     *              - ha túl rövid ahhoz, hogy növekvő és csökkenő sorozatot alkosson egyszerre, ami min. 3,
     *                  nem tartalmaz egyik természetből sem,
     *              - ha az alsó határ nem változott, akkor önmagában teljesítette valamelyik feltételt,
     *              - ellenkező esetben kiírjuk azt a sort, amely teljesítette valamelyiket
     * */

    std::ifstream bemeneti_all("be_5.txt");

    ll szam;
    if (bemeneti_all.is_open()) {
        bemeneti_all >> szam;
    } else {
        std::cout << "Nem sikerult a bemeneti allomany megnyitasa. \nEllenorizd le a bemeneti allomany eleresi utvonalat.\n";
    }

    bemeneti_all.close();

    auto szamjegyek = atalakit_tombbe(szam);

    std::ofstream kimeneti_all("ki_5.txt");

    if (kimeneti_all.is_open()) {
        kimeneti_all << volgyszam_vizsgalat(szamjegyek);
    } else {
        std::cout << "Nem sikerult a kimeneti allomany megnyitasa. \nEllenorizd le a kimeneti allomany eleresi utvonalat.\n";
    }

    kimeneti_all.close();

    return 0;
}

std::string volgyszam_vizsgalat(std::vector<ll> &szamjegyek) {
    // alsó határ mindig azt az indexet fogja tárolni, ahonnan a vizsgálatot indítjuk
    // az az előtti számok irrelevánsak, levágásra kerültek
    int also_hatar = 0;
    // tárolja az aktuális természetet, amit vizsgálunk
    std::string szam_tipus;

    int inflexios_elem;
    int utolso_pont;

    // amíg elég hosszú a számunk, hogy két sorozatot alkosson
    while ((szamjegyek.size() - also_hatar) > 2) {
        // eldöntjük milyen természetvizsgálat lesz, az első két számjegy alapján
        (szamjegyek[also_hatar] < szamjegyek[also_hatar + 1]) ? szam_tipus = "hegy" : szam_tipus = "volgy";

        // ha a jelenlegi természetet a számjegyek utolsó párja nem teljesíti levágjuk az első számjegyet
        if (szam_tipus == "hegy" && szamjegyek[szamjegyek.size() - 2] <= szamjegyek[szamjegyek.size() - 1]
            || szam_tipus == "volgy" && szamjegyek[szamjegyek.size() - 2] >= szamjegyek[szamjegyek.size() - 1]) {
            also_hatar++;
            continue;
        }

        // a jelenlegi vizsgálati helyet őrzi meg
        // ettől az elemtől kezdve ellenőrízzük a sorozatot,
        // azért az alsó határ + 1, mert mindig visszafelé ellenőrzünk a folyamatban
        utolso_pont = also_hatar + 1;
        if (szam_tipus == "hegy") {
            // megkeressük a hegycsúcsot
            inflexios_elem = *(std::max_element(szamjegyek.begin() + also_hatar, szamjegyek.end()));

            // megnézzük, hogy a hegycsúcs előtti értékek növekvő sorozatot alkotnak-e
            while (szamjegyek[utolso_pont] < inflexios_elem) {
                if (szamjegyek[utolso_pont - 1] > szamjegyek[utolso_pont]) {
                    break;
                }

                ++utolso_pont;
            }

            if (szamjegyek[utolso_pont] == inflexios_elem) {
                ++utolso_pont;

                // megnézzük, hogy a hegycsúcs utáni értékek csökkenő sorozatot alkotnak-e
                while (utolso_pont < szamjegyek.size()) {
                    if (szamjegyek[utolso_pont - 1] < szamjegyek[utolso_pont]) {
                        break;
                    }

                    ++utolso_pont;
                }
            }

            // bármikor hamarabb kiléptünk, mint a számunk hossza, azt jelenti a feltétel nem teljesült
            if (utolso_pont < szamjegyek.size()) {
                // addig vágjuk le az első számokat, amíg természetet vált
                while ((szamjegyek.size() - also_hatar) > 2 &&
                       szamjegyek[also_hatar] < szamjegyek[also_hatar + 1]) {
                    ++also_hatar;
                }
            }
        } else if (szam_tipus == "volgy") {
            // megkeressük a völgypontot
            inflexios_elem = *(std::min_element(szamjegyek.begin() + also_hatar, szamjegyek.end()));

            // megnézzük a völgypont előtti számok csökkenő sorozatot alkotnak-e
            while (szamjegyek[utolso_pont] > inflexios_elem) {
                if (szamjegyek[utolso_pont - 1] < szamjegyek[utolso_pont]) {
                    break;
                }

                ++utolso_pont;
            }

            if (szamjegyek[utolso_pont] == inflexios_elem) {
                ++utolso_pont;

                // megnézzük a völgypont utáni számok növekvő sorozatot alkotnak-e
                while (utolso_pont < szamjegyek.size()) {
                    if (szamjegyek[utolso_pont - 1] > szamjegyek[utolso_pont]) {
                        break;
                    }

                    ++utolso_pont;
                }
            }

            // bármikor hamarabb kiléptünk, mint a számunk hossza, azt jelenti a feltétel nem teljesült
            if (utolso_pont < szamjegyek.size()) {
                // addig vágjuk le a számokat az elejéről amíg természetet nem vált
                while ((szamjegyek.size() - also_hatar) > 2 &&
                       szamjegyek[also_hatar] > szamjegyek[also_hatar + 1]) {
                    ++also_hatar;
                }
            }
        }

        // ha az utolsó pont, amivel azt tartottuk nyilván hol állt meg a vizsgálat, kisebb, mint a hosszom, akkor folytatom,
        // másképp végeredményhez jutottam, mert végigfutott a vizsgálat
        if (utolso_pont < szamjegyek.size()) {
            continue;
        } else {
            break;
        }
    }

    std::string eredmeny = "";

    // ha túl rövid, nincs legalább 3 számjegye, hogy két sorozatot alkosson, elválasztva egy harmadikkal,
    // egyik feltételt sem teljesítette
    if ((szamjegyek.size() - also_hatar) <= 2) {
        eredmeny = "nincs benne hegyszam vagy volgyszam";
    } else if (also_hatar == 0) {
        // ha az alsó határról nem mozdultunk el, nem kellett számot levágjunk
        eredmeny = (szam_tipus += "szam");
    } else {
        // különben kiírjuk azokat a számokat, amik a levágás után maradtak
        for (size_t i = also_hatar; i < szamjegyek.size(); ++i) {
            eredmeny += std::to_string(szamjegyek[i]);
        }
    }

    return eredmeny;
}

std::vector<ll> atalakit_tombbe(ll szam) {
    // kimeneti tömb, amely tartalmazni fogja a számjegyeket
    std::vector<ll> szamjegyek;

    while (szam != 0) {
        // maradékképzéssel sorban levágjuk hátulról a számokat és
        // hozzáadjuk a tömbhöz
        szamjegyek.insert(szamjegyek.begin(), szam % 10);
        szam /= 10;
    }

    return szamjegyek;
}