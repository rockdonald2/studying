//
// 5. Feladat forráskódja
//

/*
Hallgató neve: Lukács Zsolt
Csoport: 1. csoport
Feladat sorszáma: 5.
*/

#include <vector>
#include <iostream>
#include <fstream>

using ll = long long;

void merge_sort(std::vector<ll> &tomb, const int &bal, const int &jobb);
void osszefesul(std::vector<ll> &tomb, const int &bal, const int &kozep, const int &jobb);

int main() {
    /*
     * ALGORITMUS LEÍRÁSA
     * Be n, tomb(n),
     * Lehív merge_sort, ahol:
     *      - az összefésülésen alapuló rendezés esetében addig bontjuk a bemeneti sorozatot két részre, amíg
     *      egyelemű sorozatokat nem kapunk, amikor megkezdődhet az összefésülés, amely során két rendezet sorozatból
     *      előállítunk egy harmadik, szintén rendezetett sorozatot,
     *      - az összefésülési algoritmus esetében a hagyomány, egyenlőséget nem vizsgáló tételt alkalmazzuk,
     *      hiszen nem halmaz végeredményt akarunk, hanem n + m elemet tartalmazót, amely a bemeneti sorozatok minden
     *      elemét tartalmazza,
     *          - a soron következő két elem összehasonlításából eldöntjük melyiket helyezzük a harmadikba,
     *          addig ismételve, míg valamelyik sorozat végére nem érünk, kilépés után pedig a másik sorozat
     *          megmaradt elemeit helyezzük az eredménysorozatba,
     *          - annyi plusz lépéssel egészül ki az összefésülési algoritmus, hogy a bal és jobb határokat tároló
     *          számláló szerint először kiválogatjuk azokat az értékeket, amelyeket az aktuális részsorozatban össze
     *          kell fésülni
     * */

    std::ifstream bemeneti_all("be_5.txt");

    int n;
    if (bemeneti_all.is_open()) {
        bemeneti_all >> n;
    } else {
        std::cout << "Nem sikerult a bemeneti allomany megnyitasa. \nEllenorizd le a bemeneti allomany eleresi utvonalat.\n";
    }

    std::vector<ll> tomb(n);
    if (bemeneti_all.is_open()) {
        for (int i = 0; i < n; ++i) {
            bemeneti_all >> tomb[i];
        }
    } else {
        std::cout << "Nem sikerult a bemeneti allomany megnyitasa. \nEllenorizd le a bemeneti allomany eleresi utvonalat.\n";
    }

    merge_sort(tomb, 0, n - 1);

    std::ofstream kimeneti_all("ki_5.txt");

    if (kimeneti_all.is_open()) {
        for (const auto &e : tomb) {
            kimeneti_all << e << '\n';
        }
    } else {
        std::cout << "Nem sikerult a kimeneti allomany megnyitasa. \nEllenorizd le a kimeneti allomany eleresi utvonalat.\n";
    }

    kimeneti_all.close();

    return 0;
}

void merge_sort(std::vector<ll> &tomb, const int &bal, const int &jobb) {
    // addig ismételjük, amíg nincs egyelemű részsorozatunk
    if (bal < jobb) {
        // meghatározzuk a részsorozat középső elemet
        int kozep = bal + (jobb - bal) / 2;

        // elindulunk tőle balra, két részre osztani
        merge_sort(tomb, bal, kozep);
        // tőle jobbra, két részre osztani
        merge_sort(tomb, kozep + 1, jobb);

        // majd a rendezett sorozatokat összefésüljük
        osszefesul(tomb, bal, kozep, jobb);
    }
}

void osszefesul(std::vector<ll> &tomb, const int &bal, const int &kozep, const int &jobb) {
    // kiválogatjuk az aktuális részsorozat összefésülendő értékeit
    std::vector<ll> bal_oldal;
    for (int i = bal; i <= kozep; ++i) {
        bal_oldal.push_back(tomb[i]);
    }

    std::vector<ll> jobb_oldal;
    for (int i = kozep + 1; i <= jobb; ++i) {
        jobb_oldal.push_back(tomb[i]);
    }

    int i = 0;
    int j = 0;
    int k = bal;

    // majd összefésüljük ezeket, először a soron következő két elem összehasonlításával
    while (i < bal_oldal.size() && j < jobb_oldal.size()) {
        if (bal_oldal[i] < jobb_oldal[j]) {
            tomb[k] = bal_oldal[i];
            ++i;
        } else {
            tomb[k] = jobb_oldal[j];
            ++j;
        }

        ++k;
    }

    // majd a megmaradt elemek eredménysorozatba helyezésével
    while (i < bal_oldal.size()) {
        tomb[k] = bal_oldal[i];
        ++k;
        ++i;
    }

    while (j < jobb_oldal.size()) {
        tomb[k] = jobb_oldal[j];
        ++k;
        ++j;
    }
}