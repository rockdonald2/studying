#include <iostream>
#include <string>
#include <sstream>
#include "Verem.h"
#include "VarakozasiSor.h"

void inicializal(Verem *v);
void hozzaad(VarakozasiSor *s, const std::string &uzenet);
bool folyamat(Verem *buszonLevok, VarakozasiSor *leSzallok, VarakozasiSor *felSzallok);

int main() {
    /* ALGORITMUS LEÍRÁSA
     * Létrehoz opcio, folytat, buszonLevok, leSzallok, felSzallok
     *      - az aktuális művelet opciókódja, folytatási feltétel,
     *          a buszon tartozkodó személyek verme, a leszálló és felszálló személyek várakozási sora
     * Amíg a felhasználó nem adta meg a kilépési opció kódját ismételjük:
     *      1. Bekér aktuális opciókód
     *      2. Ha az opciókod = 1, elindítjuk a le- és felszállási folyamatot, ahol:
     *          - először bekérjük a leszálló személyek neveit, majd a felszállókét,
     *          - elindítjuk a tényleges folyamatot:
     *              - amíg a leszállók várakozási sora nem üres, megnézzük ki a következő leszálló,
     *                addig vesszük le a buszról a személyeket, amíg meg nem kaptuk az aktuális leszállót,
     *                  - ha megkaptuk ezt a személyt, akkor kivesszük a leszállók sorából, és
     *                    megnézzük ki a következő leszálló;
     *                  - ha nem kaptuk még meg, áttesszük a buszról leszállókat a felszállók sorába;
     *             - ha mindenki leszállt a buszról, visszarakunk mindenkit, aki várakozik, és újraindítjuk a
     *             folyamatot
     *                  - de ekkor figyelve arra, hogy a következő leszálló személyt nem rakjuk vissza
     *             - ha mindenki leszállt, akinek lekellett, visszarakjuk a várakozókat a buszra,
     *                  - ha az kiürült a program véget ért,
     *                  - ha nem, akkor következő opcióval folytatódhat
     *      3. Ha az opciókod = 2, kiírjuk a buszon levőket,
     *      4. Ha az opciókod = 3, kilépünk a programból
     * */

    auto *buszonLevok = new Verem;
    auto *leSzallok = new VarakozasiSor;
    auto *felSzallok = new VarakozasiSor;

    bool folytat = true;
    int opcio;

    inicializal(buszonLevok);

    while (folytat) {
        std::cout << "\n1: Le- es felszallas folyamata\n2: Buszon levok kiirasa\n3: Kilepes\n";

        std::cout << "Opcio: ";
        std::cin >> opcio;
        std::cin.get(); // newline miatt

        switch (opcio) {
            case 1: {
                hozzaad(leSzallok, "Add meg a leszallo szemelyeket szokozzel elvalasztva: ");

                hozzaad(felSzallok, "Add meg a felszallo szemelyeket szokozzel elvalasztva: ");

                if (!folyamat(buszonLevok, leSzallok, felSzallok)) folytat = false;

                buszonLevok->Kiir();

                break;
            }
            case 2: {
                buszonLevok->Kiir();

                break;
            }
            case 4: {
                folytat = false;
                break;
            }
            default:
                folytat = false;
        }
    }

    return 0;
}

void inicializal(Verem *v) {
    std::string tarolo;
    std::cout << "Add meg a buszon tartozkodo szemelyeket szokozzel elvalasztva: ";
    std::getline(std::cin, tarolo);
    std::stringstream idg(tarolo);

    while (idg >> tarolo) {
        v->Beszuras(tarolo);
    }
}

void hozzaad(VarakozasiSor *s, const std::string &uzenet) {
    std::string tarolo;
    std::cout << uzenet;
    std::getline(std::cin, tarolo);
    std::stringstream idg(tarolo);

    while (idg >> tarolo) {
        s->Beszur(tarolo);
    }
}

bool folyamat(Verem *buszonLevok, VarakozasiSor *leSzallok, VarakozasiSor *felSzallok) {
    while (!leSzallok->Ures()) {
        auto aktualis = leSzallok->Lemasol()->info;

        while (!buszonLevok->Ures() && !leSzallok->Ures()) {
            auto eppLeszallo = buszonLevok->Lemasol()->info;
            buszonLevok->Torol();

            if (eppLeszallo != aktualis) {
                felSzallok->Beszur(eppLeszallo);
            } else {
                leSzallok->Kivesz();
                aktualis = leSzallok->Lemasol()->info;
            }
        }

        while (!felSzallok->Ures() && !leSzallok->Ures()) {
            auto eppFelszallo = felSzallok->Lemasol()->info;
            felSzallok->Kivesz();

            if (eppFelszallo != aktualis) {
                buszonLevok->Beszuras(eppFelszallo);
            } else {
                leSzallok->Kivesz();
                aktualis = leSzallok->Lemasol()->info;
            }
        }
    }

    while (!felSzallok->Ures()) {
        buszonLevok->Beszuras(felSzallok->Lemasol()->info);
        felSzallok->Kivesz();
    }

    if (buszonLevok->Ures()) {
        std::cout << "A busz kiurult\n";
        return false;
    }

    return true;
}