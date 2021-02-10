#include <iostream>
#include <iomanip>
#include <cmath>

/* 
Hallgató neve: Lukács Zsolt
Csoport: 1. csoport
Feladat sorszáma: 5.
*/
void masodfoku_polinom_megoldasa() {
    /*
     * Alkalmazzuk a matematikai képletet a két megoldás megtalálására
     * */

    double a_par;
    std::cout << "a = ";
    std::cin >> a_par;

    double b_par;
    std::cout << "b = ";
    std::cin >> b_par;

    double c_par;
    std::cout << "c = ";
    std::cin >> c_par;

    // másodfokú polinom deltájának kiszámítása
    double delta = sqrt(pow(b_par, 2) - 4 * a_par * c_par);

    // x1,x2 értékek kiszámításának képlete
    double elsoM = (-b_par + delta) / (2 * a_par);
    double masodikM = (-b_par - delta) / (2 * a_par);

    std::cout << std::setprecision(4);
    elsoM != masodikM ? std::cout << "Megoldasok: " << elsoM << ", " << masodikM << "\n" : std::cout << "Megoldasok: " << elsoM << "\n";
}

int main() {
    masodfoku_polinom_megoldasa();

    return 0;
}