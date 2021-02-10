#include <iostream>

/* 
Hallgató neve: Lukács Zsolt
Csoport: 1. csoport
Feladat sorszáma: 1.
*/
void csereld_fel_segedvaltozoval(int& elsoSz, int& masodikSz) {
    /* ideiglenes változóval lementjük az első számat, majd megcseréljük őket */
    int idg = elsoSz;
    elsoSz = masodikSz;
    masodikSz = idg;
}

void csereld_fel_segedvaltozo_nelkul(int& elsoSz, int& masodikSz) {
    /* elsőhöz hozzáadjuk a másodikat, majd ebből az összegből határozzuk meg a többit */
    elsoSz += masodikSz;
    masodikSz = elsoSz - masodikSz;
    elsoSz = elsoSz - masodikSz;
}

void csereld_fel() {
    /*
     * Alapvetően, nem más teszünk, mint beolvassuk a szükséges bemenetek,
     * majd megcseréljük a számokat, először segédváltozóval,
     * amikoris ideiglenesen tároljuk valamelyik változó értékét, miközben a másik kettőt megcseréljük.
     * Másodsorban, pedig segédváltozó nélkül összeadási művelettel.
     * */


    /* beolvassuk a szükséges adatokat */
    int elsoSz;
    std::cout << "x = ";
    std::cin >> elsoSz;

    int masodikSz;
    std::cout << "y = ";
    std::cin >> masodikSz;

    csereld_fel_segedvaltozoval(elsoSz, masodikSz);
    std::cout << "\nx = " << elsoSz << "\ny = " << masodikSz << "\n\n";

    /* kétszer felcserélve a számokat az eredeti sorrendet kapjuk */
    csereld_fel_segedvaltozo_nelkul(elsoSz, masodikSz);
    std::cout << "x = " << elsoSz << "\ny = " << masodikSz << "\n";
}

int main() {
    csereld_fel();

    return 0;
}