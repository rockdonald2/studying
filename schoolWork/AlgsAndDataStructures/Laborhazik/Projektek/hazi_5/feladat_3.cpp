#include <iostream>
#include "RendezettLista.h"

void hozzaad(RendezettLista* l);

int main() {
    /* ALGORITMUS LEÍRÁSA
     * Létrehoz opcio, folytat, verseny
     *      - az aktuális művelet opciókódja, folytatási feltétel, a versenyt nyilvántartó rendezett lista
     * Amíg a felhasználó nem adta meg a kilépési opció kódját ismételjük:
     *      1. Bekér aktuális opciókód
     *      2. Ha az opciókod = 1, rögzítünk egy újabb ugrást, ahol:
     *              - bekérjük az ugró adatait, annak nevét és pontszámát szóközzel elválaszva,
     *              - megkeressük az új ugró helyét a versenyben,
     *              - beszúrjuk a neki megfelelő helyre,
     *                  - HA már létezett ez az ugró a listában, frissítjük az adatát, úgy, hogy töröljük és újra
     *                  beszúrjuk, amennyiben nagyobb lett a pontszáma;
     *      3. Ha az opciókod = 2, kiírjuk az első hármat
     *      4. Ha az opciókod = 3, kiírjuk a teljes listát
     *      5. Ha az opciókod = 4, kilépünk a programból
     * */

    int opcio;
    bool folytat = true;

    auto *verseny = new RendezettLista;

    while (folytat) {
        std::cout << "\n1: Ujabb ugras\n2: Elso harom kiirasa\n3: Osszes kiirasa\n4: Kilepes\n";

        std::cout << "Opcio: ";
        std::cin >> opcio;
        std::cin.get();

        switch (opcio) {
            case 1: {
                hozzaad(verseny);

                verseny->Kiir();

                break;
            }
            case 2: {
                verseny->Kiir3();
                break;
            }
            case 3: {
                verseny->Kiir();
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

void hozzaad(RendezettLista* l) {
    std::pair<std::string, int> versenyzo;

    std::cout << "Add meg a versenyzo nevet es pontszama szokozzel elvalasztva: ";
    std::cin >> versenyzo.first >> versenyzo.second;

    auto *helye = l->Keres(versenyzo.first, versenyzo.second);

    if (helye) {
        if (helye->nev == versenyzo.first && helye->psz < versenyzo.second) {
            l->Torles(versenyzo.first, versenyzo.second);
            l->Koze(l->Keres(versenyzo.first, versenyzo.second), versenyzo.first, versenyzo.second);
        } else if (helye->nev != versenyzo.first) {
            l->Koze(helye, versenyzo.first, versenyzo.second);
        }
    } else {
        l->Vegere(versenyzo.first, versenyzo.second);
    }

    l->Kiir3();
}
