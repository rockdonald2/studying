#include <iostream>
#include <vector>
#include <fstream>

using ull = unsigned long long;

void maximum_rendezes(std::vector<ull> &tomb);

int main() {
    std::ifstream be_all("../be_1.txt");

    int n = 0;
    if (be_all.is_open()) {
        be_all >> n;
    } else {
        std::cout << "Nem sikerult a bemeneti allomany beolvasasa.\n";
    }

    std::vector<ull> tomb(n);
    if (be_all.is_open()) {
        for (int i = 0; i < n; ++i) {
            be_all >> tomb[i];
        }
    } else {
        std::cout << "Nem sikerult a bemeneti allomany beolvasasa.\n";
    }

    be_all.close();

    maximum_rendezes(tomb);

    std::ofstream ki_all("../ki_1.txt");

    if (ki_all.is_open()) {
        for (const auto &e : tomb) {
            ki_all << e << '\n';
        }
    } else {
        std::cout << "Nem sikerult a kimeneti allomany beolvasasa.\n";
    }

    ki_all.close();

    return 0;
}

void maximum_rendezes(std::vector<ull> &tomb) {
    int ind_max;

    for (int i = tomb.size() - 1; i > 0; --i) {
        ind_max = i;

        for (int j = i - 1; j >= 0; --j) {
            if (tomb[ind_max] < tomb[j]) {
                ind_max = j;
            }
        }

        if (ind_max != i) {
            int id = tomb[i];
            tomb[i] = tomb[ind_max];
            tomb[ind_max] = id;
        }
    }
}