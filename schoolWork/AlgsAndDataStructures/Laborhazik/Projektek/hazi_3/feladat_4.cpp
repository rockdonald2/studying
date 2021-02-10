//
// 4. Feladat forráskódja
//

/*
Hallgató neve: Lukács Zsolt
Csoport: 1. csoport
Feladat sorszáma: 4.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using ull = unsigned long long;

void leszamlalo_rendezes(std::vector<ull> &arr);

int main() {
    /* ALGORITMUS LEÍRÁSA
     * Be n, arr(n) - beolvassuk a tömb hosszát és annak elemeit
     * Lehív leszamlalo_rendezes(arr),
     *      ahol:
     *          - leszámláló rendezést végzünk el, ahol:
     *              - segédtömbre lesz szükségünk, amely k hosszúságú, ahol a k a bemeneti tömb legnagyobb értéke + 1,
     *                  hiszen 0-tól indexelünk, optimalizálunk azzal, hogy nem [0, k] intervallumot tárolunk,
     *                  hanem [min_elem, max_elem]-et
     *              - mindig azzal kezdjük, hogy megszámoljuk az egyes bemeneti adatok gyakoriságát,
     *                  az által, hogy a bemeneti adatok az előbb létrehozott segédtömbben indexelhetők
     *              - kumulált gyakoriságokat számolunk,
     *              - majd elvégezzük a tényleges rendezést, amelyben a kumulált gyakoriságokat felhasználva helyezzük
     *                  el az elemeket:
     *                   - hogyan?
     *                   - a kumulált gyakoriság lényegében annak az indexnek az értéke, ahová az adott
     *                      elemnek az utolsó előfordulásának kerülnie kell a rendezett sorban
     *                      - tehát, pl. az utolsó 2-es hová kell kerüljön, amennyiben több 2-esünk van;
     *                   - mindig csökkentjük a kumulált gyakoriságot, hiszen a soron következő előfordulása
     *                      az adott elemnek, már az azt megelőző helyre kell kerülnie, mint az előző előfordulásának
     *            - majd átírjuk a rendezett tömböt a bemeneti tömbünkbe
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

    leszamlalo_rendezes(arr);

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

void leszamlalo_rendezes(std::vector<ull> &arr) {
    // szükségünk lesz a minimum elemre, hiszen a számláló segédtömbünk [min_elem, max_elem + 1] intervallumot fog tartalmazni
    ull min_elem = *(std::min_element(arr.begin(), arr.end()));

    // k hosszúságú segédtömb, amelyet a gyakoriságok nyilvántartására használunk
    std::vector<ull> szamlalo(*(std::max_element(arr.begin(), arr.end())) + 1 - min_elem, 0);
    // kimeneti tömb, ez lesz majd a bemeneti tömb rendezett változata
    std::vector<ull> kimenet(arr.size());

    // megszámoljuk az előfordulási gyakoriságokat az egyes bemeneti adatoknak
    for (const auto &i : arr) {
        // de amikor a számláló segédtömbe növeljük az értéket, a min_elem-el csökkenteni kell, hiszen így válik indexelhetővé,
        // mindig a 0-ás index-en lesz tárolva a minimum elem gyakorisága, a maximum elem gyakorisága pedig a (max_elem + 1) - min_elem-en
        szamlalo[i - min_elem]++;
    }

    // kumulált gyakoriságot számolunk
    for (size_t j = 1; j < szamlalo.size(); ++j) {
        szamlalo[j] += szamlalo[j - 1];
    }

    // rendezzük a tömböt felhasználva a kumulált gyakoriságokat
    for (int j = arr.size() - 1; j >= 0; --j) {
        // a kumulált gyakoriság annak az indexnek az értéke,
        // ahová az arr[j] elem utolsó előfordulásának kerülnie kell
        kimenet[szamlalo[arr[j] - min_elem] - 1] = arr[j];
        // csökkentjük a kumulált gyakoriságot, hiszen a következő előfordulásának már előrébb kell kerülnie
        szamlalo[arr[j] - min_elem]--;
    }

    // majd átírjuk a rendezett tömböt a bemeneti tömbbe, hogy helyben dolgozzunk
    for (size_t j = 0; j < arr.size(); ++j) {
        arr[j] = kimenet[j];
    }
}