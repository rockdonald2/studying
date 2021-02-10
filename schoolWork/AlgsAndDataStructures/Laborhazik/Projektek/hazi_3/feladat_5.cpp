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
#include <algorithm>
#include <string>

using ll = long long;

std::string volgyszam_vizsgalat(const std::vector<ll> &szamjegyek);
std::vector<ll> atalakit_tombbe(ll szam);
bool ellenoriz_tipus(const std::vector<ll> &szamjegyek, const std::string &szam_tipus,
                     bool (*elso_feltetel)(const std::vector<ll> &, const int &, const int &),
                     bool (*masodik_feltetel)(const std::vector<ll> &, const int &, const int &),
                     const int &also_hatar);
bool novekvo_sorozat(const std::vector<ll> &szamjegyek, const int &also_hatar, const int &felso_hatar);
bool csokkeno_sorozat(const std::vector<ll> &szamjegyek, const int &also_hatar, const int &felso_hatar);
void valtoztat_tipus(const std::vector<ll> &szamjegyek, const std::string &szam_tipus, int &also_hatar);

int main() {
    /* ALGORITMUS LEÍRÁSA
     *  Be szam - beolvassuk a bemeneti számot,
     *  Lehív atalakit_tombbe(szam), ahol:
     *      - átalakítjuk a bemeneti számot egy tömbbé, hiszen a műveleteinket könnyebben tudjuk
     *          ebben a típusban elvégezni
     *      - repetítiven 10-el osszuk, a maradékot pedig a tömbbe helyezzük
     *      - akár ezt megtehetnénk a völgyszámvizsgálat alprogramon belül is
     *  Lehív volgyszam_vizsgalat(szamjegyek), ahol:
     *      - alapja a megoldásnak az alsó határ tologatás, ezzel vágjuk le a számjegyeket az illető szám elejéről,
     *      - minden vizsgálat az aktuális természet megállapításával kezdődik, az alsó határt és az azutáni értéket felhasználva,
     *          HA a szám vége nem teljesíti a természet követelményeit növeljük az alsó határt, levágva 1 számjegyet
     *      - vizsgáljuk a természet feltételeinek teljesülését az ellenoriz_tipus függvénnyel, hegyszám esetében
     *          ez egy növekvő sorozat, majd egy csökkenő sorozat, völgyszám esetén pedig egy csökkenő sorozat, majd egy növekvő,
     *          az inflexiós pont mentén
     *      - ha nem teljesíti, a teljesülés változó értéke hamis lesz, valamint, ha hamis akkor annyi számjegyet vágunk le az elejéről,
     *          amíg természet nem vált és elölről kezdjük a vizsgálatot, hiszen nem képes a természet feltételeit teljesíteni
     * Kiír természet
     * */

    std::ifstream bemeneti_all("be_5.txt");

    ll szam;
    if (bemeneti_all.is_open()) {
        bemeneti_all >> szam;
    } else {
        std::cout << "Nem sikerult a bemeneti allomany megnyitasa. \nEllenorizd le a bemeneti allomany eleresi utvonalat.\n";
    }

    bemeneti_all.close();

    std::ofstream kimeneti_all("ki_5.txt");

    if (kimeneti_all.is_open()) {
        kimeneti_all << volgyszam_vizsgalat(atalakit_tombbe(szam));
    } else {
        std::cout << "Nem sikerult a kimeneti allomany megnyitasa. \nEllenorizd le a kimeneti allomany eleresi utvonalat.\n";
    }

    kimeneti_all.close();

    return 0;
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

std::string volgyszam_vizsgalat(const std::vector<ll> &szamjegyek) {
    // alsó határ mindig azt az indexet fogja tárolni, ahonnan a vizsgálatot indítjuk
    // az az előtti számok irrelevánsak, levágásra kerültek
    int also_hatar = 0;
    // tárolja az aktuális természetet, amit vizsgálunk
    std::string szam_tipus;

    // ez fogja tárolni a feltételek teljesülését
    // akkor igaz, ha a szám teljesíti valamely természet feltételeit
    bool teljesules;

    // amíg elég hosszú a számunk, hogy két sorozatot alkosson
    while ((szamjegyek.size() - also_hatar) > 2) {
        // eldöntjük milyen természetvizsgálat lesz, az első két számjegy alapján
        (szamjegyek[also_hatar] < szamjegyek[also_hatar + 1]) ? szam_tipus = "hegy" : szam_tipus = "volgy";

        // ha a jelenlegi természetet a számjegyek utolsó párja nem teljesíti levágjuk az első számjegyet,
        // amíg természet nem vált
        if (szam_tipus == "hegy" && szamjegyek[szamjegyek.size() - 2] <= szamjegyek[szamjegyek.size() - 1]
            || szam_tipus == "volgy" && szamjegyek[szamjegyek.size() - 2] >= szamjegyek[szamjegyek.size() - 1]) {
            valtoztat_tipus(szamjegyek, szam_tipus, also_hatar);
            continue;
        }

        // elvégezzük a megfelelő természet szerinti vizsgálatot
        // a teljesülés fogja tárolni a döntés eredményét
        if (szam_tipus == "hegy") {
            teljesules = ellenoriz_tipus(szamjegyek, szam_tipus, novekvo_sorozat, csokkeno_sorozat, also_hatar);
        } else if (szam_tipus == "volgy") {
            teljesules = ellenoriz_tipus(szamjegyek, szam_tipus, csokkeno_sorozat, novekvo_sorozat, also_hatar);
        }

        // ha a vizsgált természet feltételei teljesültek, végeredményhez jutottunk
        if (teljesules) {
            break;
        } else {
            // ha nem teljesül, vágjunk le annyi számot az elejéről, amíg természetet nem vált
            valtoztat_tipus(szamjegyek, szam_tipus, also_hatar);
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

bool ellenoriz_tipus(const std::vector<ll> &szamjegyek, const std::string &szam_tipus,
                     bool (*elso_feltetel)(const std::vector<ll> &, const int &, const int &),
                     bool (*masodik_feltetel)(const std::vector<ll> &, const int &, const int &),
                     const int &also_hatar) {
    int inflexios_ind;

    // minden esetben megkell kapnunk a természet szerinti inflexiós pontot
    if (szam_tipus == "hegy") {
        inflexios_ind = std::max_element(szamjegyek.begin() + also_hatar, szamjegyek.end()) - szamjegyek.begin();
    } else if (szam_tipus == "volgy") {
        inflexios_ind = std::min_element(szamjegyek.begin() + also_hatar, szamjegyek.end()) - szamjegyek.begin();
    }

    // majd ellenőrízzük a természet feltételeinek jelenlétét
    if (elso_feltetel(szamjegyek, also_hatar, inflexios_ind) &&
        masodik_feltetel(szamjegyek, inflexios_ind + 1, szamjegyek.size())) {
        return true;
    } else {
        return false;
    }
}

bool novekvo_sorozat(const std::vector<ll> &szamjegyek, const int &also_hatar, const int &felso_hatar) {
    // ellenőrzi, hogy az alsó és felsőhatár közötti számjegyek növekvő sorozatot alkotnak-e
    bool rendben = true;

    int i = also_hatar + 1;

    while (i < felso_hatar && rendben) {
        if (szamjegyek[i - 1] > szamjegyek[i]) {
            rendben = false;
        }

        ++i;
    }

    return rendben;
}

bool csokkeno_sorozat(const std::vector<ll> &szamjegyek, const int &also_hatar, const int &felso_hatar) {
    // ellenőrzi, hogy az alsó és felsőhatár közötti számjegyek csökkenő sorozatot alkotnak-e
    bool rendben = true;

    int i = also_hatar + 1;

    while (i < felso_hatar && rendben) {
        if (szamjegyek[i - 1] < szamjegyek[i]) {
            rendben = false;
        }

        ++i;
    }

    return rendben;
}

void valtoztat_tipus(const std::vector<ll> &szamjegyek, const std::string &szam_tipus, int &also_hatar) {
    // ameddig az adott természet szerinti kezdő feltétel teljesül növeljük az alsó határt és van legalább 3 számjegyünk
    while (
            ((szamjegyek.size() - also_hatar > 2)) &&
            ((szam_tipus == "volgy" && szamjegyek[also_hatar] >= szamjegyek[also_hatar + 1]) ||
            (szam_tipus == "hegy" && szamjegyek[also_hatar] <= szamjegyek[also_hatar + 1])
            )) {
        ++also_hatar;
    }
}