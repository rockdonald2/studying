#include <iostream>
#include <iomanip>
#include <string>

/* 
Hallgató neve: Lukács Zsolt
Csoport: 1. csoport
Feladat sorszáma: 4.
*/
void idealis_testsuly() {
    /*
     * Alkalmazzuk a matematikai képletet az ideális testsúly kiszámolásához.
     * Egy elágazással oldjuk meg a nemek közti különbséget
     * */

    std::string nem;
    // bebiztosítjuk azt, hogy mindenképp jó a nem paraméter, amely alternatív paraméter, két értéket vehet fel
    do {
        std::cout << "nem = ";
        std::cin >> nem;
    } while (nem != "no" && nem != "ferfi");

    double magassag;
    do {
        std::cout << "magassag = ";
        std::cin >> magassag;
    } while (magassag <= 0);

    int eletkor;
    do {
        std::cout << "eletkor = ";
        std::cin >> eletkor;
    } while (eletkor <= 0);

    // elengedő a képletet csak egyszer alkalmazni, hiszen a nemek közötti különbség a 0.9-es együttható jelenti
    double idealis = 50 + 0.75 * (magassag - 150) + static_cast<double>((eletkor - 20)) / 40;

    if (nem == "no") {
        idealis *= 0.9;
    }

    std::cout << std::setprecision(4);
    std::cout << "Idealis testsuly: " << idealis << " kg\n";
}

int main() {
    idealis_testsuly();

    return 0;
}