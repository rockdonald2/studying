#include <iostream>
#include <iomanip>
#include <cmath>

/* 
Hallgató neve: Lukács Zsolt
Csoport: 1. csoport
Feladat sorszáma: 9.
*/
double terulet_szamitas(const double &elsoO, const double &masodikO, const double &harmadikO) {
    // koszinusz-tételből megkapjuk az 'c' oldallal szemben levő szög konszinuszát
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

void nevezetes_korok() {
    /*
     * Alkalmazzuk a szükséges matematikai képleteket a két nevezetes kör megtalálásához.
     * Szükségtelen a negatív input ellenőrzése, hiszen az egyenlőtlenség alapból ellenőrzi ezt.
     * */

    double elsoO;
    double masodikO;
    double harmadikO;

    std::cin >> elsoO >> masodikO >> harmadikO;

    if (!alkothat_haromszoget(elsoO, masodikO, harmadikO)) {
        std::cout << "Nem alkothatnak haromszoget\n";
        return;
    }

    double terulet = terulet_szamitas(elsoO, masodikO, harmadikO);

    // a háromszögbe írható kör sugara megegyezik a terület kétszerese osztva a három oldal összegével
    double be_irhato_kor_sugara = (2 * terulet) / (elsoO + masodikO + harmadikO);

    // a háromszög köré írható kör sugara megegyezik a három oldal szorzata, osztva a terület négyszeresével
    double kore_irhato_kor_sugara = (elsoO * masodikO * harmadikO) / (4 * terulet);

    double kor_terulete = M_PI * (be_irhato_kor_sugara * be_irhato_kor_sugara);

    std::cout << std::setprecision(4);
    std::cout << "Haromszogbe irhato kor sugara: " << be_irhato_kor_sugara << "\nHaromszog kore irhato kor sugara: " << kore_irhato_kor_sugara << "\nHaromszogbe irhato kor terulete: " << kor_terulete << std::endl;
}

int main() {
    nevezetes_korok();

    return 0;
}