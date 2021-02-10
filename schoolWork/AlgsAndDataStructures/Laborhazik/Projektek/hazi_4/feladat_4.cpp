//
// 4. Feladat forráskódja
//

/*
Hallgató neve: Lukács Zsolt
Csoport: 1. csoport
Feladat sorszáma: 4.
*/

#include <iostream>
#include <fstream>

using ld = long double;
using uint = unsigned int;

ld gyors_hatvany(const ld &szam, const uint &kitevo);

int main() {
    /*
     * ALGORITMUS LEÍRÁSA
     * Be szam, kitevo,
     * Lehív gyors_hatvany, ahol:
     *      - oszd meg és uralkodj módszerrel kiszámoljuk az a^k hatványt,
     *          az által, hogy felhasználjuk a korábbi hatványeredményeket,
     *          és a megfelelőképpen a hatvány paritása alapján korrigáljuk
     * */

    std::ifstream bemeneti_all("be_4.txt");

    ld szam;
    uint kitevo;
    if (bemeneti_all.is_open()) {
        bemeneti_all >> szam >> kitevo;
    } else {
        std::cout << "Nem sikerult a bemeneti allomany megnyitasa. \nEllenorizd le a bemeneti allomany eleresi utvonalat.\n";
    }

    bemeneti_all.close();

    std::ofstream kimeneti_all("ki_4.txt");

    if (kimeneti_all.is_open()) {
        if (kitevo != 0) {
            kimeneti_all << gyors_hatvany(szam, kitevo) << '\n';
        } else {
            kimeneti_all << '1' << '\n';
        }
    } else {
        std::cout << "Nem sikerult a kimeneti allomany megnyitasa. \nEllenorizd le a kimeneti allomany eleresi utvonalat.\n";
    }

    kimeneti_all.close();

    return 0;
}

ld gyors_hatvany(const ld &szam, const uint &kitevo) {
    if (kitevo == 1) {
        return szam;
    } else {
        // megszerezzük a hatványt megelőző hatványeredményt
        ld id = gyors_hatvany(szam, kitevo / 2);

        // kitevő paritása alapján korrigáljuk az eredményt
        if (kitevo % 2) {
            return id * id * szam;
        } else {
            return id * id;
        }
    }
}