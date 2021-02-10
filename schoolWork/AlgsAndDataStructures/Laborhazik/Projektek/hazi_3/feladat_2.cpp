//
// 2. Feladat forráskódja
//

/*
Hallgató neve: Lukács Zsolt
Csoport: 1. csoport
Feladat sorszáma: 2.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using ull = unsigned long long;

void minimum_kivalasztos_rendezes(std::vector<ull> &arr);

int main() {
    /* ALGORITMUS LEÍRÁSA
     * Be n, arr(n) - beolvassuk a tömb hosszát és annak elemeit
     * Lehív minimum_kivalasztos_rendezes(arr),
     *      ahol:
     *          - minimum kiválasztáson alapuló rendezést végzünk el, amelyben:
     *              - végighaladunk a tömb utolsó előtti eleméig, azért kell az utolsó előttiig, mert másképp nem marad két elemünk összehasonlítani
     *                  minden iterációkor kiválasztva a tömb minimum elemét,
     *                  a hátralevő tömbrészből, amely rendelkezésünkre áll attól az elemtől kezdve, ahonnan a vizsgálatot kezdtük,
     *                  és ahová a minimum elemet bekell helyeznünk, felcseréléssel
     * Kiír rendezett tömb
     * */

    std::ifstream bemeneti_all("be_1-4.txt");

    int n = 0;
    if (bemeneti_all.is_open()){
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

    minimum_kivalasztos_rendezes(arr);

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

void minimum_kivalasztos_rendezes(std::vector<ull> &arr) {
    // ebben fogjuk megőrízni az aktuális minimum elem indexét
    int min_elem_ind;

    for (size_t i = 0; i < arr.size() - 1; ++i) {
        // mindig feltételezzük, hogy a kezdés helye a minimum elem
        min_elem_ind = i;

        // kezdve a kezdéstől, a hátralevő tömbrészből megkeressük a minimum elemet
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[min_elem_ind]) {
                min_elem_ind = j;
            }
        }

        // ha eltérő minimum elemet kaptunk, mint a kezdés helye, megcseréljük őket
        if (min_elem_ind != i) {
            std::swap(arr[i], arr[min_elem_ind]);
        }
    }
}