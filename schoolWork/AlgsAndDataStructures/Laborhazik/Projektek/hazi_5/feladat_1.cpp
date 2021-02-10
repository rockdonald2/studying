#include <iostream>
#include <string>
#include <sstream>
#include "Lista.h"

bool hozzaad(Lista* l, const std::string &uzenet = "Kovetkezo vagy * a leallashoz: ");

int main() {
    /* ALGORITMUS LEÍRÁSA
     * Létrehoz opcio, folytat és jelenlevők
     *      - az aktuális művelet opciókódja, folytatási feltétel és a jelenlevőket
     *        tároló láncolt lista
     * Amíg a felhasználó nem adta meg a kilépési opció kódját ismételjük:
     *      1. Bekér aktuális opciókód
     *      2. Ha opciókod = 1 -> elindítjuk a jelenlevő-megadási ciklust, ami addig kér be neveket,
     *              amíg a speciális karaktert nem adja meg a felhasználó, vagy \r-t nem üt, vagy
     *              amíg ki nem ürül a jelenlevők listája
     *              Ahol a hozzaad függvény:
     *                  - addig kér be újabb neveket, amíg meg nem adjuk a speciális karaktert, vagy üressort;
     *                  - lehívja a "BeszurJelenlevo" eljárást, amely hozzáadja az adott személyt a jelenlevőkhöz,
     *                      ha az már szerepel a jelenlevők listájában törli a személyt
     *                  - ha egy adott törlésnél kiürül a lista a bekérési ciklus leáll
     *      3. Ha opciókod = 2 -> kiírja a jelenlevőket
     *      4. Ha opciókod = 3 -> kilép a programból
     * */

    int opcio;
    bool folytat = true;

    auto *jelenlevok = new Lista;

    hozzaad(jelenlevok, "Add meg a jelenlevoket: ");

    while (folytat) {
        std::cout << "\n1: Megadasi ciklus elinditasa\n2: Jelenlevok kiiras\n3: Kilepes\n";

        std::cout << "Opcio: ";
        std::cin >> opcio;
        std::cin.get();

        switch (opcio) {
            case 1: {
                while (hozzaad(jelenlevok)) {}

                jelenlevok->Kiir();

                break;
            }
            case 2: {
                jelenlevok->Kiir();
                break;
            }
            case 3: {
                folytat = false;
                break;
            }
            default: {
                folytat = false;
            }
        }
    }

    return 0;
}

bool hozzaad(Lista* l, const std::string &uzenet) {
    std::string tarolo;
    std::cout << uzenet;
    std::getline(std::cin, tarolo);
    std::stringstream idg(tarolo);

    bool folytat = true;

    while (idg >> tarolo && folytat) {
        if (tarolo != "*") {
            l->BeszurJelenlevo(tarolo);

            if (l->Ures()) {
                std::cout << "Lista kiurult\n";
                folytat = false;
            }
        } else {
            folytat = false;
        }
    }

    return folytat;
}