//
// 5. Feladat forráskódja
//

/*
Hallgató neve: Lukács Zsolt
Csoport: 1. csoport
Feladat sorszáma: 5.
*/

#include <iostream>
#include <vector>
#include <algorithm>

void rendez_kuszobok_szerint(std::vector<int> &arr, const std::vector<int> &kuszobok);
void kiir_kuszobok_szerint(const std::vector<int> &arr, const std::vector<int> &kuszobok);

int main() {
    /*
     * ALGORITMUS LEÍRÁSA
     *
     * Be n, arr(n) - beolvassuk a tömb hosszát és annak elemeit
     * Legyen kuszobok = {1000, 700}
     * Lehív rendez_kuszobok_szerint(arr, kuszobok) - amely szétválogatja a tömb elemeit a kuszobok szerint,
     *      ahol:
     *          - minden küszöb esetében egyszer végzünk szétválogatást
     *          - a szétválogatáskor mindig keresünk egy olyan elemet, amely nincs jó helyt a válogatásban
     *              és megcseréljük egy olyan elemmel, amely jó helyre kerülne csere után
     * Lehív kiir_kuszobok_szerint(arr, kuszobok) - amely kiírja a tömb elemeit a kimenet szerinti csoportosítással,
     *      ahol:
     *          - Legyen kezdes = 0, amely az épp kiírandó érték indexét tárolja,
     *          - Vedd k = egyik küszöb, amíg van küszöb,
     *              - Kiír minden olyan elem, amely a küszöbnél nagyobb, szóközzel utána,
     *              - Kiír újsor, amennyiben nincs több ilyen elem
     *          - Vedd a maradék elemet, amely az utolsó küszöbnél kisebb és írd ki
     * */

    // Be n
    int n;
    std::cin >> n;

    // Be arr(n)
    std::vector<int> arr(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // Legyen kuszobok = {1000, 700}
    const std::vector<int> kuszobok {1000, 700};

    // Lehív rendez_kuszobok_szerint(arr, kuszobok)
    rendez_kuszobok_szerint(arr, kuszobok);
    // Lehív kiir_kuszobok_szerint(arr, kuszobok)
    kiir_kuszobok_szerint(arr, kuszobok);

    return 0;
}

void rendez_kuszobok_szerint(std::vector<int> &arr, const std::vector<int> &kuszobok) {
    // két mutatót fogunk használni, a "kezdes" azon intervallum alsó határa, amelyen belül
    // még a szétválogatás megkell történjen, a "kezdes" változó annak az elemnek a sorszáma, amely
    // nincs jó helyt a válogatásban
    size_t kezdes = 0;
    // a vege hátulról kezdve keres egy olyan elemet, amely nincs jó helyt
    size_t vege = arr.size() - 1;

    // többször kell szétválogatnunk, minden küszöb esetében egyszer
    for (const auto &k : kuszobok) {
        // mindig az új valogatás a sorozat végéről indul,
        // míg az alsó határa a "kezdes" sorszám lesz
        vege = arr.size() - 1;

        // amíg a két mutató nem találkozik, amíg van olyan elem, amivel lehetne cserélni
        while (kezdes < vege) {
            // ha a "kezdes" sorszámú elem nincs jó helyt,
            // és találtunk egy olyan elemet, amellyel fellehetne cserélni, hogy az jó helyt legyen
            // megcseréljük
            if (arr[kezdes] < k && arr[vege] >= k) {
                std::swap(arr[kezdes], arr[vege]);
                kezdes++;
                vege--;
            } else if (arr[kezdes] >= k) {
                // ha a jelenlegi alsó határon levő elem jó helyt van, továbblépünk 1-el
                kezdes++;
            } else {
                // ha nincs jó helyt a "kezdes" sorszámú elem, de a felső határ eleme is rossz lenne az adott helyt,
                // nem végzünk cserét, ezt átlépjük
                vege--;
            }
        }
    }
}

void kiir_kuszobok_szerint(const std::vector<int> &arr, const std::vector<int> &kuszobok) {
    size_t kezdes = 0;

    for (const auto &k : kuszobok) {
        while (kezdes < arr.size() && arr[kezdes] >= k) {
            std::cout << arr[kezdes++] << ' ';
        }

        // minden küszöbvégnél beillesztünk egy újsort
        std::cout << "\n";
    }

    while (kezdes < arr.size()) {
        std::cout << arr[kezdes++] << ' ';
    }
}