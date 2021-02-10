#include <iostream>
#include <vector>

using namespace std;

const int m = 8;
static vector<int> K(m + 1, -1);

int c = 0;

void Kiralyno(const int &i);
bool Nem_Tamad(const int &i);
void Kiir();

int main() {
    Kiralyno(1);

    return 0;
}

void Kiralyno(const int &i) {
    for (int j = 1; j <= m; ++j) {
        K[i] = j;

        if (Nem_Tamad(i)) {
            if (i < m) {
                Kiralyno(i + 1);
            } else {
                ++c;
                Kiir();
            }
        }
    }
}

bool Nem_Tamad(const int &i) {
    bool nem = true;

    int j = 1;
    while (j <= (i - 1) && nem) {
        if (K[i] == K[j] || ((i - j) == abs(K[i] - K[j]))) {
            nem = false;
        } else {
            ++j;
        }
    }

    return nem;
}

void Kiir() {
    cout << c << ": \n";

    for (int j = 1; j <= m; ++j) {
        cout << K[j] << '\t';
    }

    cout << "\n\n";
}