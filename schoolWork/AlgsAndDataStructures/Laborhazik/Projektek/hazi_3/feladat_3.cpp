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
#include <algorithm>
#include <fstream>

using ull = unsigned long long;

void beszuro_rendezes(std::vector<ull> &arr);

int main() {
    /* ALGORITMUS LEÍRÁSA
     * Be n, arr(n) - beolvassuk a tömböt és a tömb elemeit
     * Lehív beszuro_rendezes(arr),
     *      ahol:
     *          - beszuró rendezést végzünk el, ahol:
     *              - haladunk a tömb második elemétől kezdve,
     *                  mindig az aktuális elemet egy segédváltozóban tárolva,
     *                  visszafelé haladva az ennél nagyobb elemeket egy hellyel előrébb toljuk,
     *                  majd miután nem találunk ennél nagyobb elemet, a megállás utáni helyre
     *                  bemásoljuk az aktuális segédváltozó értékét
     * Kiír rendezett tömb
     * */

    std::ifstream bemeneti_all("be_1-4.txt");

    int n = 0;
    if (bemeneti_all.is_open()) {
        bemeneti_all >> n;
    } else {
        std::cout << "Nem sikerult a bemeneti allomany megnyitasa. \nEllenorizd le a bemeneti allomany eleresi utvonalat.\n";
    }

    std::vector<ull> arr(n);
    if (bemeneti_all.is_open()) {
        for (size_t i = 0; i < n; ++i) {
            bemeneti_all >> arr[i];
        }
    } else {
        std::cout << "Nem sikerult a bemeneti allomany megnyitasa. \nEllenorizd le a bemeneti allomany eleresi utvonalat.\n";
    }

    bemeneti_all.close();

    beszuro_rendezes(arr);

    std::ofstream kimeneti_all("ki_1-4.txt");

    if (kimeneti_all.is_open()) {
        for (const auto &e : arr) {
            kimeneti_all << e << '\n';
        }
    } else {
        std::cout << "Nem sikerult a kimeneti allomany megnyitasa. \nEllenorizd le a kimeneti allomany eleresi utvonalat.\n";
    }

    kimeneti_all.close();

    return 0;
}

void beszuro_rendezes(std::vector<ull> &arr) {
    // állapotváltozók,
    // a segéd az épp kimentett elemet tárolja
    // a j pedig a visszafelé haladás segédváltozója
    int seged;
    int j;

    for (int i = 1; i < arr.size(); ++i) {
        // kimentjük az aktuális értéket, amelynek a helyét keressük a rendezett sorozatban
        seged = arr[i];
        // visszafelé haladunk ennek a helyétől
        j = i - 1;

        // amíg van elemünk és ameddig csak nagyobb elemeket találunk
        while (j >= 0 && arr[j] > seged) {
            // egy hellyel előrébb toljuk a nagyobb elemeket
            arr[j + 1] = arr[j];
            j--;
        }

        // majd behelyezzük a megállási pont utáni helyre az aktuális elemet
        arr[j + 1] = seged;
    }
}