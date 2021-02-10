#include <iostream>

/* 
Hallgató neve: Lukács Zsolt
Csoport: 1. csoport
Feladat sorszáma: 2.
*/
void novekvo_sorrend() {
    /*
     * Egybeágyazott feltételes kifejezéseket használunk a növekvő sorrend felállításához.
     * Minden esetben azzal kezdjük, hogy az első szám viszonyát vizsgáljuk a másodikhoz.
     * Másodsorban, a vizsgálat után vagy az első (ha az első kisebb, mint a második),
     * vagy a második (ha az első nagyobb vagy egyenlő, mint a második) viszonyát vizsgáljuk a harmadikhoz.
     * Legfeljebb 3 összehasonlítással jutunk el a végső sorrendhez.
     * */

    int elsoSz;
    std::cout << "x = ";
    std::cin >> elsoSz;

    int masodikSz;
    std::cout << "y = ";
    std::cin >> masodikSz;

    int harmadikSz;
    std::cout << "z = ";
    std::cin >> harmadikSz;

    // ha az első szám kisebb, mint a második
    if (elsoSz < masodikSz) {
        // már csak azt kell leellenőrízzük, hogy az első, a harmadiknál is kisebb-e
        if (elsoSz < harmadikSz) {
            // ha igen az első szám a legkisebb
            std::cout << elsoSz << ", ";

            // a másik két szám közötti viszonyt még nem ismerjük, megnézzük, melyik a kisebb kettejük közül
            if (masodikSz < harmadikSz) {
                std::cout << masodikSz << ", " << harmadikSz << "\n";
            } else {
                std::cout << harmadikSz << ", " << masodikSz << "\n";
            }
        } else {
            // ha az első kisebb, mint a második, azonban az első nagyobb, mint a harmadik
            std::cout << harmadikSz << ", " << elsoSz << ", " << masodikSz << "\n";
        }
    // ha az első,nagyobb vagy egyenlő, mint a második
    } else if (elsoSz >= masodikSz) {
        // és a második, kisebb, mint a harmadik
        if (masodikSz < harmadikSz) {
            // tudjuk, hogy a második a legkisebb
            std::cout << masodikSz << ", ";

            // de az első és a harmadik közötti viszonyt, még nem tudjuk
            if (elsoSz < harmadikSz) {
                std::cout << elsoSz << ", " << harmadikSz << "\n";
            } else {
                std::cout << harmadikSz << ", " << elsoSz << "\n";
            }
        } else {
            // ha a második nagyobb vagy egyenlő, mint a harmadik, akkor már tudjuk is a sorrendet
            std::cout << harmadikSz << ", " << masodikSz << ", " << elsoSz << "\n";
        }
    }
}

int main() {
    novekvo_sorrend();

    return 0;
}