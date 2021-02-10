#include <iostream>

/* 
Hallgató neve: Lukács Zsolt
Csoport: 1. csoport
Feladat sorszáma: 3.
*/
void bekerites() {
    /*
     * A feladat megoldásához kerületet számolunk, majd ezt hasonlítjuk össze a megadott dróthosszal.
     * Amennyiben a kerület nagyobb, a dróthossz nem elegendő, amennyiben kisebb, többletünk van.
     */

    int hossz;
    do {
        std::cout << "h = ";
        std::cin >> hossz;
    } while (hossz <= 0);

    int szel;
    do {
        std::cout << "sz = ";
        std::cin >> szel;
    } while (szel <= 0);

    int drot;
    do {
        std::cout << "drot = ";
        std::cin >> drot;
    } while (drot <= 0);

    // kerület megegyezzik a hosszúság és szélesség összegének a kétszeresével
    int kerulet = 2 * (hossz + szel);

    // azt keressük, van-e elegendő drótunk a kerület bekerítésére
    if (kerulet > drot) {
        std::cout << (kerulet - drot) << " hosszusagu drot szukseges meg\n";
    } else if (kerulet < drot) {
        std::cout << (drot - kerulet) << " drot maradt a bekerites utan\n";
    } else {
        std::cout << "A drot pont elegendo volt\n";
    }
}

int main() {
    bekerites();

    return 0;
}