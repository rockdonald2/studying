#include <iostream>
#include <iomanip>
#include <math.h>

/* 
Hallgató neve: Lukács Zsolt
Csoport: 1. csoport
Feladat sorszáma: 6.
*/
double terulet_szamitas(const double &elsoO, const double &masodikO, const double &harmadikO) {
    // koszinusz-tételből megkapjuk az 'c' oldallal szemben levő szög koszinuszát
    double cos = (pow(elsoO, 2) + pow(masodikO, 2) - pow(harmadikO, 2)) / (2 * elsoO * masodikO);
    // majd a trigonometriai alapegyenletből kiszámoljuk ugyanannak a szögnek a szinuszát
    double sin = sqrt(1 - pow(cos, 2));
    // azzal kiszámoljuk az a oldalhoz tartozó magasságot
    double ma = masodikO * sin;
    // végül a terület
    double terulet = (elsoO * ma) / 2;

    return terulet;
}

bool alkothat_haromszoget(const double &elsoO, const double &masodikO, const double &harmadikO) {
    // háromszög egyenlőtlenség szerint, egy háromszög bármely oldala, kisebb, mint a másik két oldal összege,
    // ha ez nem teljesül, nem képezhető a három szakaszból háromszög
    if (elsoO >= (masodikO + harmadikO) || masodikO >= (elsoO + harmadikO) || harmadikO >= (elsoO + masodikO)) {
        return false;
    }

    return true;
}

void haromszog_terulet() {
    /*
     * Alkalmazunk a fenti matematikai képleteket a terület kiszámolásához.
     * Minden esetben figyelünk a helyes inputra, valamint arra is, hogy alkothat-e a három megadott szakasz háromszöget.
     * */

    double elsoO;
    do {
        std::cout << "a = ";
        std::cin >> elsoO;
    } while (elsoO <= 0);

    double masodikO;
    do {
        std::cout << "b = ";
        std::cin >> masodikO;
    } while (masodikO <= 0);

    double harmadikO;
    do {
        std::cout << "c = ";
        std::cin >> harmadikO;
    } while (harmadikO <= 0);

    if (alkothat_haromszoget(elsoO, masodikO, harmadikO)) {
        std::cout << std::setprecision(4);
        std::cout << "A haromszog terulete: " << terulet_szamitas(elsoO, masodikO, harmadikO) << "\n";
    } else {
        std::cout << "Nem alkothatnak haromszoget\n";
    }
}

int main() {
    haromszog_terulet();

    return 0;
}