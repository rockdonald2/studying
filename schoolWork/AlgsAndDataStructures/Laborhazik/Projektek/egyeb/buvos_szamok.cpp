#include <iostream>
#include <vector>
#include <map>

/*
 * Adott két természetes szám, p és q, amely számrendszereket jelöl, mindegyik 2 és 10 között lesz,
 * Egy term. szám bűvös, ha a p számrendszerben felírt alakjában szereplő számjegyek halmaza azonos,
 * a q számrendszerben felírt alakjában szereplő számjegyek halmazával.
 * Hat. meg az összes 1 és n között levő term. számok közül a bűvös számokat.
 *
 *
 * Megoldási lépések:
 *  1) bekérjük a p és q számrendszereket
 *  2) bekérjük az n határt
 *  3) haladunk 1-től n-ig, generálva a számokat
 *  4) teszteljük a generált számokat
 *  5) kiírjuk
 * */

std::vector<int> atalakit(int szr, int sz);
bool osszevet_halmaz(const std::vector<int> &h1, const std::vector<int> &h2);

int main() {
    int p, q, n;
    std::cin >> p >> q >> n;

    std::vector<int> p_alap, q_alap;
    for (int i = 1; i <= n; ++i) {
        p_alap = atalakit(p, i);
        q_alap = atalakit(q, i);

        if (osszevet_halmaz(p_alap, q_alap)) {
            std::cout << i << " ";
        }
    }

    return 0;
}

std::vector<int> atalakit(int szr, int sz) {
    std::vector<int> szam_halmaz;

    int maradek;
    while (sz) {
        maradek = sz % szr;
        sz /= szr;
        szam_halmaz.insert(szam_halmaz.begin(), maradek);
    }

    return szam_halmaz;
}

bool osszevet_halmaz(const std::vector<int> &h1, const std::vector<int> &h2) {
    if (h1.size() != h2.size()) {
        return false;
    }

    std::map<int, int> h1_map;
    std::map<int, int> h2_map;

    for (unsigned int i = 0; i < h1.size(); ++i) {
        h1_map[h1[i]] ? h1_map[h1[i]] += 1 : h1_map[h1[i]] = 1;
        h2_map[h2[i]] ? h2_map[h2[i]] += 1 : h2_map[h2[i]] = 1;
    }

    return std::equal(h1_map.begin(), h1_map.end(), h2_map.begin(), [] (auto a, auto b) {
        return a.first == b.first && a.second == b.second;
    });
}