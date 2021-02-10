#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

const int n = 4; // királynők száma, sakktábla sorainak és oszlopainak száma
static vector<int> K(n + 1, 0);

void Kiralyno(const int &i);
bool Nem_tamad(const int &i);
void Kiir();

int main() {
    Kiralyno(1);

    return 0;
}

void Kiralyno(const int &i) {
    for (int j = 1; j <= n; ++j) {
        K[i] = j;

        if (Nem_tamad(i)) {
            if (i < n) {
                Kiralyno(i + 1);
            } else {
                Kiir();
            }
        }
    }
}

bool Nem_tamad(const int &i) {
    int j = 1;
    bool nem = true;

    while (j <= (i - 1) && nem) {
        if (K[i] == K[j] || (i - j == abs(K[i] - K[j]))) {
            nem = false;
        } else {
            ++j;
        }
    }

    return nem;
}

void Kiir() {
    for (int i = 1; i <= n; ++i) {
        int l = K[i];

        for (int z = 1; z < l; ++z) {
            cout << "[ ] ";
        }

        cout << "[ x ] ";

        for (int z = l  + 1; z <= n; ++z) {
            cout << "[ ] ";
        }

        cout << "\n";
    }

    cout << "\n\n\n";
}