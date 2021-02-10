//
// 4. Feladat forráskódja
//

/*
Hallgató neve: Lukács Zsolt
Csoport: 1. csoport
Feladat sorszáma: 4.
*/

#include <algorithm>
#include <iostream>
#include <vector>

void torol_kuszob_alatt(std::vector<int> &arr, const int &kuszob);

int main() {
    /*
     * ALGORITMUS LEÍRÁSA
     *
     * Be n, arr(n) - beolvass a tömb hosszát, majd a tömb elemeit
     * Lehív torol_kuszob_alatt(arr, kuszob), ahol a kuszob = 5 -
     *      ahol:
     *          - a folyamat megőrzi a sorrendet, az által, hogy két mutatót használ,
     *              ahol:
     *                  - a határ azt a pozíciót jelöli, amelytől kezdve az elemek nem szükségesek számunkra,
     *                      hiszen azok tőrlödnek,
     *                  - a ciklus során megőrízve a sorrendet, rámásoljuk előlről kezdve az 5-nél nagyobb elemeket,
     *                      az eredeti tömbünkre,
     *                  - majd a végén, az új határ első elemétől törlünk a tömb végéig mindent.
     * Kiír korrigált tömb
     * */

    // Be n
    int n;
    std::cin >> n;

    // Be arr(n)
    std::vector<int> arr(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // Lehív torol_kuszob_alatt(arr, kuszob)
    torol_kuszob_alatt(arr, 5);

    // Kiír korrigált tömb
    for (const auto &it : arr) {
        std::cout << it << " ";
    }

    return 0;
}

void torol_kuszob_alatt(std::vector<int> &arr, const int &kuszob) {
    // ez fogja jelölni a korrigált tömb számosságát
    int hatar = -1;

    for (size_t i = 0; i < arr.size(); ++i) {
        // felülírjuk a tömb elemeit az 5-nél nagyobb értékekkel, amik sorban következnek
        if (arr[i] >= kuszob) {
            arr[++hatar] = arr[i];
        }
    }

    // kitöröljük az új határt követő összes értéket
    arr.erase(arr.begin() + hatar + 1, arr.end());
}