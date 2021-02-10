#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void targy(const int &i, const int &j, vector<vector<int>> &tg, int &meret);

int main() {
    ifstream fenykep("../fenykep.in");

    int m;
    fenykep >> m;
    int n;
    fenykep >> n;

    vector<vector<int>> tg(n + 2);
    for (int i = 0; i < (n + 2); ++i) {
        tg[i] = vector<int>(m + 2);

        for (int j = 0; j < (m + 2); ++j) {
            tg[i][j] = 0;
        }
    }

    for (int i = 1; i < (n + 1); ++i) {
        for (int j = 1; j < (m + 1); ++j) {
            fenykep >> tg[i][j];
        }
    }

    for (const auto &e : tg) {
        for (const auto &t : e) {
            cout << t;
        }
        cout << '\n';
    }

    int meret;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (tg[i][j] == 1) {
                meret = 0;
                targy(i, j, tg, meret);
                cout << i << " " << j << " meret: " << meret << endl;
            }
        }
    }

    return 0;
}

void targy(const int &i, const int &j, vector<vector<int>> &tg, int &meret) {
    if (tg[i][j] == 1) {
        tg[i][j] = 2;
        ++meret;
        targy(i - 1, j - 1, tg, meret);
        targy(i - 1, j, tg, meret);
        targy(i - 1, j + 1, tg, meret);
        targy(i + 1, j + 1, tg, meret);
        targy(i + 1, j, tg, meret);
        targy(i + 1, j + 1, tg, meret);
        targy(i, j - 1, tg, meret);
        targy(i, j + 1, tg, meret);
    }
}