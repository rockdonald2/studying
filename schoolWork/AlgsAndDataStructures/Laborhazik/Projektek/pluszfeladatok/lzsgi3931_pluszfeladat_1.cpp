/*
Hallgató neve: Lukács Zsolt
Csoport: 1. csoport
Pluszfeladat
*/


#include <iostream>
#include <vector>

std::vector<int> max_szorzat(const std::vector<int> &a);

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    auto m_s = max_szorzat(arr);

    for (const auto &e : m_s) {
        std::cout << e << ' ';
    }

    return 0;
}

std::vector<int> max_szorzat(const std::vector<int> &a) {
    // külön nyilvántartom a 3 max elemet
    std::vector<int> max_elemek;

    // külön nyilvántartom a 2 min elemet, hiszen szorzatuk + lesz
    std::vector<int> min_elemek;

    for (const auto &i : a) {
        // hozzáadom az elemet a max_elemek tömbhöz, ha üres
        if (max_elemek.empty()) {
            max_elemek.push_back(i);
        } else {
            // ha hosszabb, mint 3 elem a max_elemek tömb, egy elemet törölni kell belőle, a legkisebbet
            if (max_elemek.size() < 3) {
                max_elemek.push_back(i);
            } else {
                int min_index = 0;

                for (size_t j = 0; j < max_elemek.size(); ++j) {
                    if (max_elemek[j] < max_elemek[min_index]) {
                        min_index = j;
                    }
                }

                if (i > max_elemek[min_index]) {
                    max_elemek[min_index] = i;
                }
            }
        }

        // hozzáadom az elemet a min_elemek tömbhöz, ha üres
        if (min_elemek.empty()) {
            min_elemek.push_back(i);
        } else {
            // ha a min_elemek tömb hosszabb, mint 2 elem, a legnagyobbat törölni kell
            if (min_elemek.size() < 2) {
                min_elemek.push_back(i);
            } else {
                int max_index = 0;

                for (size_t j = 0; j < min_elemek.size(); ++j) {
                    if (min_elemek[j] > min_elemek[max_index]) {
                        max_index = j;
                    }
                }

                if (i < min_elemek[max_index]) {
                    min_elemek[max_index] = i;
                }
            }
        }
    }

    // megnézzük mennyi a jelenlegi szorzat, és melyik a max_elemek tömb legnagyobb eleme
    int max_szorzat = 1;
    int max_elem_index = 0;
    for (size_t i = 0; i < max_elemek.size(); ++i) {
        max_szorzat *= max_elemek[i];

        if (max_elemek[i] > max_elemek[max_elem_index]) {
            max_elem_index = i;
        }
    }

    // ha a két min elemmel alkotott szorzata nagyobb, akkor az a 3 max szorzatú elem
    if ((max_elemek[max_elem_index] * min_elemek[0] * min_elemek[1]) > max_szorzat) {
        return std::vector<int>{max_elemek[max_elem_index], min_elemek[0], min_elemek[1]};
    } else {
        // ellenkező esetben a 3 max eleme a bemeneti tömbnek
        return max_elemek;
    }
}