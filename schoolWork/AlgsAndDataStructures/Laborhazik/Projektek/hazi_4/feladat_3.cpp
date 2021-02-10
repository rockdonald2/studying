//
// 3. Feladat forráskódja
//

/*
Hallgató neve: Lukács Zsolt
Csoport: 1. csoport
Feladat sorszáma: 3.
*/

#include <iostream>
#include <vector>
#include <fstream>

void epits(const std::vector<std::pair<std::string, int>> &kockak, const int &k, std::vector<int> &tarolo, const int
&i, std::ofstream &ki);
void kiir(std::vector<int> &tarolo, const std::vector<std::pair<std::string, int>> &kockak, std::ofstream &ki);
bool megfelel(std::vector<int> &tarolo, const int &i, const std::vector<std::pair<std::string, int>> &kockak);

int main() {
    /*
     * ALGORITMUS LEÍRÁSA
     * Be n, k, n. kocka színe és oldalainak hossza,
     * Létrehozzuk k hosszúságú segédtömböt, amely az éppen aktuális lehetséges megoldás tárolója lesz,
     * Lehív epits, ahol:
     *      - sorban haladva javasolunk a torony aktuális helyére 1-1 építőkockát,
     *      - javaslat után mindig ellenőrízzük a feltétel teljesülését, mely szerint nincs egymásra azonos színű
     *      kocka helyezve, valamint a kockák mérete szerint csökkenő sorozatot alkotnak lentről felfelé,
     *      - amennyiben az aktuális javaslatot elfogadjuk, a torony következő szintjére lépünk s oda javasolunk egy
     *      újabb kockát,
     *      - addig ismételjük, amíg van még szabad szintje a toronynak,
     *      - ha elhelyeztünk minden szintre egy kockát, és teljesítik a fenti feltételt, kiírjuk a végeredményt,
     *      - a belső feltételeket ellenőrzö eljárás páronként vizsgálja meg a kockákat, a megfelelőséget vizsgálva
     *      - paraméterek:
     *              - const vector<pair<string, int>> - a kockákat tároló tömb, pár adattípusban tárolja a színt és
     *              hosszt,
     *              - const int &k - a torony szintjeinek száma,
     *              - vector<int> &tarolo - az aktuálisan generált megoldást tároló segédtömb, a kockák sorszámát
     *              tárolja, és nem annak adatait,
     *              - const int &i - éppen melyik szintre javasolunk kockát
     * */

    std::ifstream bemeneti_all("be_3.txt");

    int n;
    int k;
    if (bemeneti_all.is_open()) {
        bemeneti_all >> n >> k;
    } else {
        std::cout << "Nem sikerult a bemeneti allomany megnyitasa. \nEllenorizd le a bemeneti allomany eleresi utvonalat.\n";
    }

    std::vector<std::pair<std::string, int>> kockak(n);
    if (bemeneti_all.is_open()) {
        for (int i = 0; i < n; ++i) {
            bemeneti_all >> kockak[i].first >> kockak[i].second;
        }
    } else {
        std::cout << "Nem sikerult a bemeneti allomany megnyitasa. \nEllenorizd le a bemeneti allomany eleresi utvonalat.\n";
    }

    bemeneti_all.close();

    std::vector<int> tarolo(k);

    std::ofstream kimeneti_all("ki_3.txt");

    if (kimeneti_all.is_open()) {
        epits(kockak, k, tarolo, 0, kimeneti_all);
    } else {
        std::cout << "Nem sikerult a kimeneti allomany megnyitasa. \nEllenorizd le a kimeneti allomany eleresi utvonalat.\n";
    }

    kimeneti_all.close();

    return 0;
}

void epits(const std::vector<std::pair<std::string, int>> &kockak, const int &k, std::vector<int> &tarolo, const int
&i, std::ofstream &ki) {
    for (int j = 0; j < kockak.size(); ++j) {
        // a torony i. szintjére javasoljuk a j. kockát
        tarolo[i] = j;

        // ellenőrízzük a belső feltételek teljesülését
        if (megfelel(tarolo, i, kockak)) {
            if (i < (k - 1)) {
                // ha teljesül, és még van szabad szint, következő szintre lépünk
                epits(kockak, k, tarolo, i + 1, ki);
            } else {
                // ellenkező esetben kiírjuk a végeredményt
                kiir(tarolo, kockak, ki);
            }
        }
    }
}

void kiir(std::vector<int> &tarolo, const std::vector<std::pair<std::string, int>> &kockak, std::ofstream &ki) {
    // kiírja az elhelyezett kockák sorszámát
    for (const auto &e : tarolo) {
        ki << (e + 1) << ' ';
    }

    ki << '\n';
}

bool megfelel(std::vector<int> &tarolo, const int &i, const std::vector<std::pair<std::string, int>> &kockak) {
    // leellenőrzi, hogy van-e egymásra helyezve azonos színű kocka, illetve vizsgálja a csökkenő sorozat
    // teljesülését is
    // igazat térít, ha mindkét belső feltétel egyidejűleg teljesül
    if (i >= 1) {
        if (kockak[tarolo[i - 1]].first != kockak[tarolo[i]].first) {
            if (kockak[tarolo[i - 1]].second > kockak[tarolo[i]].second) {
                return true;
            }
        }

        return false;
    } else {
        return true;
    }
}