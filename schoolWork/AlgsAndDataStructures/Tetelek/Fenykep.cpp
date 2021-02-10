#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void Targy(const int &i, const int &j, vector<vector<unsigned int>> &tg, int &meret);

int main() {
    std::ifstream fenykep("fenykep.in");

    int m;
    int n;
    if (fenykep.is_open()) {
        fenykep >> m >> n;
    } else {
        cout << "Nem sikerult az input fajl beolvasasa.\n";
    }

    vector<vector<unsigned int>> tg(n + 2);
    for (int i = 0; i < (n + 2); ++i) {
        tg[i] = vector<unsigned int>(m + 2);

        for (int j = 0; j < (m + 2); ++j) {
            tg[i][j] = 0;
        }
    }

    if (fenykep.is_open()) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                fenykep >> tg[i][j];
            }
        }
    } else {
        cout << "Nem sikerult az input fajl beolvasasa.\n";
    }

    for (const auto &s : tg) {
        for (const auto &o : s) {
            cout << o;
        }

        cout << '\n';
    }

    int meret;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (tg[i][j] == 1) {
                meret = 0;
                Targy(i, j, tg, meret);
                cout << i << " " << j << " meret: " << meret << '\n';
            }
        }
    }

    return 0;
}

void Targy(const int &i, const int &j, vector<vector<unsigned int>> &tg, int &meret) {
    if (tg[i][j] == 1) {
        tg[i][j] = 2;
        ++meret;
        Targy(i - 1, j - 1, tg, meret);
        Targy(i - 1, j, tg, meret);
        Targy(i - 1, j + 1, tg, meret);
        Targy(i + 1, j - 1, tg, meret);
        Targy(i + 1, j, tg, meret);
        Targy(i + 1, j + 1, tg, meret);
        Targy(i, j - 1, tg, meret);
        Targy(i, j + 1, tg, meret);
    }
}