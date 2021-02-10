//
// 6. Feladat forráskódja
//

/*
Hallgató neve: Lukács Zsolt
Csoport: 1. csoport
Feladat sorszáma: 6.
*/

#include <iostream>
#include <fstream>

void hanoi_torony(const int &n, const std::string &elso_rud, const std::string &masodik_rud, const std::string
&harmadik_rud, std::ofstream &ki);

int main() {
    /*
     * ALGORITMUS LEÍRÁSA
     * Be n,
     * Lehív hanoi_torony, ahol:
     *      - n - 1 korongot átköltöztetünk az első rúdról a harmadikra,
     *      - a megmaradt korongot áthelyezzük a másodikra,
     *      - n - 1 korongot átköltöztetünk a harmadik rúdról az elsőre
     *          (minden lépésben a legkisebb korongot mozgatom, hiszen arra nem helyezhetek semmit)
     * */

    int n;
    std::cout << "n = ";
    std::cin >> n;

    std::ofstream kimeneti_all("ki_6.txt");

    if (kimeneti_all.is_open()) {
        hanoi_torony(n, "A", "B", "C", kimeneti_all);
    } else {
        std::cout << "Nem sikerult a kimeneti allomany megnyitasa. \nEllenorizd le a kimeneti allomany eleresi utvonalat.\n";
    }

    kimeneti_all.close();

    return 0;
}

void hanoi_torony(const int &n, const std::string &elso_rud, const std::string &masodik_rud, const std::string
&harmadik_rud, std::ofstream &ki) {
    if (n == 1) {
        ki << "Koltoztess egy korongot " << elso_rud << "-rol a " << masodik_rud << "-re\n";
    } else {
        hanoi_torony(n - 1, elso_rud, harmadik_rud, masodik_rud, ki);
        hanoi_torony(1, elso_rud, masodik_rud, harmadik_rud, ki);
        hanoi_torony(n - 1, harmadik_rud, masodik_rud, elso_rud, ki);
    }
}