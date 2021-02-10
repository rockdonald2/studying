//
// 7. Feladat forráskódja
//

/*
Hallgató neve: Lukács Zsolt
Csoport: 1. csoport
Feladat sorszáma: 7.
*/

#include <iostream>
#include <vector>
#include <fstream>

double polinom(const int &n, const std::vector<double> &allandok, const double &pont);
void polinom_kieg(const int &n, const std::vector<double> &allandok, const double &x, double &eredmeny);

int main() {
    /* ALGORITMUS LEÍRÁSA
     * Be n, allandok, pont - beolvassuk a polinom nagyságrendjét, annak állandóit, és a vizsgált x pontot
     * Lehív polinom(n, allandok, pont), ahol:
     *      - a rekurzív eljárás négy paraméterrel fog rendelkezni:
     *          1. const int &n - a függvény éppen aktuális nagyságrendje, amit vizsgálunk, a legmagasabb rendtől
     *              haladunk visszafelé,
     *          2. const vector<double> &allandok - a függvény állandóinak tömbje,
     *          3. const double &x - a vizsgált x pont,
     *          4. double &eredmeny - eredményt tartalmazó valós adat
     *      - a rekurzív eljárás a Horner-algoritmuson alapszik, amelyben:
     *          - nem alkalmazunk hatványra emelést, hanem alkalmazzuk az alábbi utasítássorozatot:
     *              eredmeny <- 0
     *              n <- a nagyságrend (polinomiális hatvány) amivel dolgozunk
     *              eredmeny <- pont * eredmeny + allando (elölről haladva; x^4 állandójával kezdve)
     *              n <- n - 1
     *              eredmeny <- pont * eredmeny + allandó
     *
     *              ...
     *
     *              ha n < 0 - megállunk
     *         - példaképpen: 2x^4 + x^3 - x^1 + 5; x = 2
     *              eredmeny <- 0
     *              n <- 4
     *              eredmeny <- 2 * 0 + 2
     *              n <- 3
     *              eredmeny <- 2 * 2 + 1
     *              n <- 2
     *              eredmeny <- 2 * 5 + 0
     *              n <- 1
     *              eredmeny <- 2 * 10 - 1
     *              n <- 0
     *              eredmeny <- 2 * 19 + 5
     *
     *              n < 0 - megállunk
     *
     *              eredmeny = 43
     * Kiír eredmény
     * */

    std::ifstream bemeneti_all("be_7.txt");

    int n = 0;
    if (bemeneti_all.is_open()) {
        bemeneti_all >> n;
    } else {
        std::cout << "Nem sikerult a bemeneti allomany megnyitasa. \nEllenorizd le a bemeneti allomany eleresi utvonalat.\n";
    }

    std::vector<double> allandok(n + 1);
    if (bemeneti_all.is_open()) {
        for (size_t i = 0; i < (n + 1); ++i) {
            bemeneti_all >> allandok[i];
        }
    } else {
        std::cout << "Nem sikerult a bemeneti allomany megnyitasa. \nEllenorizd le a bemeneti allomany eleresi utvonalat.\n";
    }

    double pont;
    if (bemeneti_all.is_open()) {
        bemeneti_all >> pont;
    } else {
        std::cout << "Nem sikerult a bemeneti allomany megnyitasa. \nEllenorizd le a bemeneti allomany eleresi utvonalat.\n";
    }

    bemeneti_all.close();

    std::ofstream kimeneti_all("ki_7.txt");

    if (kimeneti_all.is_open()) {
        kimeneti_all << polinom(n, allandok, pont);
    } else {
        std::cout << "Nem sikerult a kimeneti allomany megnyitasa. \nEllenorizd le a kimeneti allomany eleresi utvonalat.\n";
    }

    kimeneti_all.close();

    return 0;
}

double polinom(const int &n, const std::vector<double> &allandok, const double &pont) {
    double eredmeny = 0;

    polinom_kieg(n, allandok, pont, eredmeny);

    return eredmeny;
}

void polinom_kieg(const int &n, const std::vector<double> &allandok, const double &x, double &eredmeny) {
    // Horner-algoritmusát felhasználva megkapjuk az eredményt;
    // szükséges egy kiegészítő eredmény paraméter, az utolsó eredmény nyilvántartásához
    if (n >= 0) {
        eredmeny = x * eredmeny + allandok[allandok.size() - n - 1];
        polinom_kieg(n - 1, allandok, x, eredmeny);
    }
}