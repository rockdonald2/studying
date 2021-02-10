//
// 1. Feladat forráskódja
//

/*
Hallgató neve: Lukács Zsolt
Csoport: 1. csoport
Feladat sorszáma: 1.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using ull = unsigned long long;

void buborek_rendezes(std::vector<ull> &arr);

int main() {
    /* ALGORITMUS LEÍRÁSA
     * Be n, arr(n) - beolvassuk a tömb hosszát, és a tömb elemeit
     * Lehív buborek_rendezes(arr),
     *      ahol:
     *          - buborékrendezést végzünk el, amely:
     *              - addig fog egymás melletti elemeket cserélni, amíg a tömb nincs rendezve,
     *                  amíg az elemek páronként nincsenek a megfelelő helyen
     *              - a megállási feltétel a rendben változó, amennyiben nincs újabb csere, abban az esetben megállunk,
     *              - mindig elegendő az utolsó csere helyéig vizsgálni a tömböt, az azutáni elemek már a helyükön vannak sorrendben,
     *                  - azért feltételezhetjük ezt, mert az adott vizsgált elem minden azt megelőzőnél nagyobb volt,
     *                      de kisebb az azutáni elemeknél
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

    buborek_rendezes(arr);

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

void buborek_rendezes(std::vector<ull> &arr) {
    // állapotváltozók,
    // a rendben a megállási feltétel,
    // az utolsó csere hely az utolsó elem indexét tárolja, ahová cseréltünk,
    // a max bejárandó hossz azért szükséges mert megkell őríznünk, hogy melyik indexig szükséges az adott körben
    // vizsgálni a tömböt
    bool rendben;
    int utolso_csere_helye = arr.size();
    int max_bejarando_hossz;

    do {
        // mindig az utolsó csere helyét megelőző indexig kell mennünk, hiszen páronként vizsgáljunk az elemeket
        // az azt követő elemmel
        max_bejarando_hossz = utolso_csere_helye - 1;
        rendben = true;

        for (int i = 0; i < max_bejarando_hossz; ++i) {
            // páronként hasonlítsuk össze az egymásmelletti elemeket
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                // ha csere történt, akkor még nincs rendezve a tömb az adott körben
                rendben = false;
                // lementjük az utolsó csere helyét, következő körben csak eddig szükséges vizsgálni a tömböt
                utolso_csere_helye = i + 1;
            }
        }
    } while (!rendben);
}