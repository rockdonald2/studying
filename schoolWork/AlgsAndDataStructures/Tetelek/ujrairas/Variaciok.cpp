#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int n = 3;
const int m = 4;
const vector<string> nev{"", "Tamas", "Arpad", "Alpar", "Botond"};
vector<string> x(m + 1, "");

void Variaciok(const int &i);
bool Meg_Nem_Ul(const int &i);
void Kiir();

int main() {
    Variaciok(1);

    return 0;
}

void Variaciok(const int &i) {
    for (int j = 1; j <= m; ++j) {
        x[i] = nev[j];

        if (Meg_Nem_Ul(i)) {
            if (i < m) {
                Variaciok(i + 1);
            } else {
                Kiir();
            }
        }
    }
}

bool Meg_Nem_Ul(const int &i) {
    for (int j = 1; j <= (i - 1); ++j) {
        if (x[i] == x[j]) {
            return false;
        }
    }

    return true;
}

void Kiir() {
    for (int j = 1; j <= m; ++j) {
        cout << x[j] << '\t';
    }

    cout << "\n\n";
}