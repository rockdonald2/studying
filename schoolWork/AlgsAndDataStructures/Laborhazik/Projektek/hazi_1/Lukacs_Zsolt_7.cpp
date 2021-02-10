#include <iostream>

/* 
Hallgató neve: Lukács Zsolt
Csoport: 1. csoport
Feladat sorszáma: 7.
*/
int szokoevek_szama(const int &kezdes, const int &vegzes) {
    int szamlalo = 0;
    int iterator = 1;

    // alapvető logika az algoritmus során, hogy megkeressük a kezdő dátum utáni első szőkőévet,
    // utána már csak 4-esével kell haladnunk

    int idg = kezdes;

    while (idg <= vegzes) {
        if ((!(idg % 4) && (idg % 100)) || !(idg % 400)) {
            szamlalo += 1;
            iterator == 1 ? iterator = 4 : NULL;
        }

        idg += iterator;
    }

    return szamlalo;
}

void szokoevek_ket_ev_kozott() {
    /*
     * A szökőévek kiszámolásakor alkalmazzuk azon tulajdonságukat a szökőéveknek, hogy négyevente fordulnak elő.
     * Megkeressük az első szökőévet majd 4-esével haladunk tovább.
     * Figyelünk a helyes inputra, minden esetben a kezdés dátuma kisebb kell legyen, mint a végzés dátuma.
     * */

    int kezdes;
    std::cout << "elso = ";
    std::cin >> kezdes;

    int vegzes;
    std::cout << "masodik = ";
    std::cin >> vegzes;

    // ha a felhasználó fordított sorrendben adta meg az éveket, megcseréljük
    if (kezdes > vegzes) {
        int idg = kezdes;
        kezdes = vegzes;
        vegzes = idg;
    }

    std::cout << szokoevek_szama(kezdes, vegzes) << " szokoev\n";
}

int main() {
    szokoevek_ket_ev_kozott();

    return 0;
}