#include <iostream>
#include <string>
#include "DuplanLancolt.h"

int main() {
    /* ALGORITMUS LEÍRÁSA
     * Létrehoz szo, és sorozat,
     *      - ahol a szo, az aktuálisan beolvasott szó;
     *      - a sorozat pedig a duplán láncolt lista, ami a szavakat tárolja
     * Amíg a felhasználó nem adta meg a kilépési opció kódját ismételjük:
     *      1. Bekér aktuális opciókód
     *      2. Ha az opciókod = 1, beolvassuk a szavakat szóközzel elválasztva, majd *-al jelölve a végét,
     *          hozzáfűzve a láncolt lista végére
     *      3. Ha az opciókod = 2, kiírjuk a szavakat a kért sorrendek szerint,
     *      4. Ha az opciókod = 3, kilépünk a programból
     * */

    auto *sorozat = new DuplanLancolt;
    std::string szo;

    int opcio;
    bool folytat = true;

    while (folytat) {
        std::cout << "\n1: Szavak beolvasasa\n2: Szavak kiirasa\n3: Kilepes\n";

        std::cout << "Opcio: ";
        std::cin >> opcio;
        std::cin.get(); // newline miatt

        switch (opcio) {
            case 1: {
                std::cout << "Adj meg szavakat szokozzel elvalasztva, *-al jelolve a veget\n";

                do {
                    std::cin >> szo;

                    if (szo != "*") {
                        sorozat->Be_Vegere(szo);
                    }
                } while (szo != "*");

                sorozat->Kiir_Elolrol();
                sorozat->Kiir_Hatulrol();

                break;
            }
            case 2: {
                sorozat->Kiir_Elolrol();
                sorozat->Kiir_Hatulrol();

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