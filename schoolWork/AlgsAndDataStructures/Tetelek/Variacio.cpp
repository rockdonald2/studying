#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int n = 2; // székek száma
const int m = 3; // gyerekek száma
static const vector<int> nev{0, 1, 2, 3, 4, 5};
static vector<int> x(n + 1, 0);

void Variacio(const int &i);
bool Meg_nem_ul(const int &i);
void Kombinacio(const int &i);
void Kiir();

int main() {
    Variacio(1);

    return 0;
}

void Variacio(const int &i) {
    for (int j = 1; j <= m; ++j) {
        x[i] = nev[j];

        if (Meg_nem_ul(i)) {
            if (i < n) {
                Variacio(i + 1);
            } else {
                Kiir();
            }
        }
    }
}

void Kombinacio(const int &i) {
    for (int j = x[i - 1] + 1; j <= (m - n + i); ++j) {
        x[i] = nev[j];

        if (i < n) {
            Kombinacio(i + 1);
        } else {
            Kiir();
        }
    }
}

bool Meg_nem_ul(const int &i) {
    for (int j = 1; j <= (i - 1); ++j) {
        if (x[i] == x[j]) {
            return false;
        }
    }

    return true;
}

void Kiir() {
    for (int j = 1; j <= n; ++j) {
        cout << x[j] << ' ';
    }

    cout << '\n';
}