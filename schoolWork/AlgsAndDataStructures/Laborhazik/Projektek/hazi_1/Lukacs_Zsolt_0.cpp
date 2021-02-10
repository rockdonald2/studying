#include <iostream>
#include <vector>
#include <array>
#include <iomanip>

/* 
Hallgató neve: Lukács Zsolt
Csoport: 1. csoport
Feladat sorszáma: 0.
*/
void osszeg_szorzat_atlag() {
    /*
     * Alapvetően, bekér a 'szamokSzama'-nak megfelelő számot, majd
     * kiszámítja a kért mennyiségeket.
     * Amennyiben több számot szeretnék használni két dolgot kell tennem:
     *  1. módosítani a 'szamokSzama' változót,
     *  2. a változásnak megfelelően a 'betuk' vektorhoz új betűket hozzáfűzni.
     * */

    /* létrehozzuk a számokat tároló vektort, és a betűket tartalmazó tömböt, amelyet a beolvasásnál használunk */
    const unsigned int szamokSzama = 3;
    std::vector<int> szamok = std::vector<int>();
    std::array<char, szamokSzama> betuk {'x', 'y', 'z'};

    /* beolvassuk a számjainkat */
    for (unsigned int i = 0; i < szamokSzama; i++) {
        int szam;
        std::cout << betuk[i] << " = ";
        std::cin >> szam;
        szamok.push_back(szam);
    }

    int osszeg = 0;
    int szorzat = 1;
    double atlag = 0;

    /* kiszámoljuk a kért mennyiségeket */
    for (auto szam : szamok) {
        osszeg += szam;
        szorzat *= szam;
    }

    atlag = static_cast<double>(osszeg) / szamokSzama;

    /* beállítjuk a pontosságot, ahhoz, hogy két tizedes pontosságot kapjunk */
    std::cout << std::setprecision(3);
    std::cout << "osszeg = " << osszeg << "\nszorzat = " << szorzat << "\natlag = " << atlag << "\n";
}

int main() {
    osszeg_szorzat_atlag();

    return 0;
}