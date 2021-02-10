#include <iostream>
#include <string>
#include "VarakozasiSor.h"
#include "Lista.h"

void hozzaad(VarakozasiSor* v, Lista* l);

int main() {
    /* ALGORITMUS LEÍRÁSA
     * Létrehoz opcio, folytat, varakozok és bentlevok
     *      - az aktuális művelet opciókódja, folytatási feltétel, a varakozokat
     *        tároló várakozási sor és bentlévőket tároló rögzített hosszúságú lista
     * Amíg a felhasználó nem adta meg a kilépési opció kódját ismételjük:
     *      1. Bekér aktuális opciókód
     *      2. Ha az opciókod = 1, bekér egy új párost (Név Esemény) formában szóközzel elválasztva, amikor:
     *          - ha az esemény érkezés, ha a bentlévők listája még nem telt be, hozzáadja az adott személyt a bentlévők
     *          listájához;
     *              - ha megtelt hozzáadja a várakozási sorhoz
     *          - ha az esemény távozás, töröljük az illető személyt a bentlévők listájából, ha a várakozási sor nem
     *          üres,
     *              beszúrjuk a várakozási sor első elemét a bentlévők listájába
     *      3. Ha az opciókod = 2, kiírjuk a bentlévők listáját
     *      4. Ha az opciókod = 3, kiírjuk a várakozók sorát
     *      5. Ha az opciókod = 4, kilépünk a programból
     * */

    int opcio;
    bool folytat = true;

    int n;
    std::cout << "Hany szemely tartozkodhat az uzletben: ";
    std::cin >> n;
    std::cin.get();

    auto *varakozok = new VarakozasiSor;
    auto *bentlevok = new Lista(true, n);

    while (folytat) {
        std::cout << "\n1: Paros megadasa\n2: Uzletben levok kiirasa\n3: Varakozok kiirasa\n4: Kilepes\n";

        std::cout << "Opcio: ";
        std::cin >> opcio;
        std::cin.get();

        switch (opcio) {
            case 1: {
                hozzaad(varakozok, bentlevok);

                bentlevok->Kiir();
                varakozok->Kiir();

                break;
            }
            case 2: {
                bentlevok->Kiir();
                break;
            }
            case 3: {
                varakozok->Kiir();
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

void hozzaad(VarakozasiSor* v, Lista* l) {
    std::pair<std::string, int> par;

    std::cout << "Add meg a nevet es az esemenyt (1 - erkezes; -1 - tavozas) szokozzel elvalasztva: ";
    std::cin >> par.first >> par.second;

    if (par.second == 1) {
        if (l->Tele()) {
            v->Beszur(par.first);
        } else {
            l->BeszurElol(par.first);
        }
    } else {
        l->Torol(par.first);

        if (!l->Tele()) {
            if (!v->Ures()) {
                l->BeszurElol(v->Lemasol()->info);
                v->Kivesz();
            }
        }
    }
}