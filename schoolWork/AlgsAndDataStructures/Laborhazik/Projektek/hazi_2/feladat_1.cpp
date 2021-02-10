//
// 1. Feladat forráskódja
//

/*
Hallgató neve: Lukács Zsolt
Csoport: 1. csoport
Feladat sorszáma: 1.
*/

#include <iostream>

std::pair<long long, int> karakterisztika(const long long &a, const long long &b);

int main() {
    /* ALGORITMUS LEÍRÁSA
     *
     * Be a, b - beolvassuk a két természetes számot
     * Lehív karakterisztika(a, b) - lehívjuk a függvényt, amely kiszámolja az intervallum számaink karakterisztikáját
     *      - amíg i < b, ahol i a-ról kezd
     *      - Számold ki jelenlegi = i karakterisztikáját,
     *          ahol:
     *              - hajtsd végre a karakterisztika számítás folyamatát,
     *                  ahol: ha jelenlegi páros oszd 2-vel,
     *                        ha jelenlegi páratlan szorozd 3-al és adj hozzá 1-et.
     *              - ismételd amíg a feltétel teljesül
     *              - ellenőrízd le a jelenlegi szám karakterisztikája magasabb-e, mint a jelenlegi maximumé, ha igen
     *                  mentsd le ezt a párt.
     * Kiír legmagasabb karakterisztikájú szám
     * */

    // Be a, b
    long long a, b;
    do {
        std::cin >> a >> b;
    } while (a < 0 || b < 0);

    // Lehív karakterisztika(a, b)
    // Visszatérés után -> Kiír maximum karakterisztikájú szám
    std::cout << karakterisztika(a, b).first << std::endl;

    return 0;
}

std::pair<long long, int> karakterisztika(const long long &a, const long long &b) {
    // max pár tárolója
    std::pair<long long, int> max;

    for (long long i = a; i <= b; i++) {
        long long jelenlegi = i;
        int lepesek = 0;

        while (jelenlegi != 1) {
            if (!(jelenlegi % 2)) {
                jelenlegi /= 2;
            } else {
                jelenlegi = jelenlegi * 3 + 1;
            }

            lepesek++;
        }

        // leellenőrízzük nagyobb-e, mint a max. karakterisztikája
        if (lepesek > max.second) {
            max.first = i;
            max.second = lepesek;
        }
    }

    return max;
}