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
#include <cmath>
#include <fstream>

double polinom(const int &n, const std::vector<double> &allandok, const double &x);
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
     *      - a rekurzív eljáráson belül addig ismételjük meg a x^nagyságrend * polinomiális állandó összegzést,
     *          amíg pozitív a nagyságrendünk, x helyére behelyettesítve az aktuális pontot,
     *          nagyságrend helyére az aktuális n értéket, az állandót a tömbből kapjuk meg
     * */

    std::ifstream bemeneti_all("../hazi_3/be_7.txt");

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

    std::ofstream kimeneti_all("../hazi_3/ki_7.txt");

    if (kimeneti_all.is_open()) {
        kimeneti_all << polinom(n, allandok, pont);
    } else {
        std::cout << "Nem sikerult a kimeneti allomany megnyitasa. \nEllenorizd le a kimeneti allomany eleresi utvonalat.\n";
    }

    kimeneti_all.close();

    return 0;
}

double polinom(const int &n, const std::vector<double> &allandok, const double &x) {
    // ez fogja tárolni a végső eredményét a polinomvizsgálatnak
    double eredmeny = 0;

    polinom_kieg(n, allandok, x, eredmeny);

    return eredmeny;
}

void polinom_kieg(const int &n, const std::vector<double> &allandok, const double &x, double &eredmeny) {
    if (n >= 0) {
        // ismételjük meg az "aktuális x^nagyságrend * állandó összegzést, amíg van pozitív nagyságrendünk
        eredmeny += (pow(x, n) * allandok[allandok.size() - n - 1]);

        // lehívjuk a rekurzív eljárást eggyel kisebb nagyságrenddel,
        // az azt megelőző részt már az eredmény változónk tartalmazza
        polinom_kieg(n - 1, allandok, x, eredmeny);
    }
}