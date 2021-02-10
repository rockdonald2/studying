#include <iostream>
#include <vector>

using namespace std;

vector<int> b{0, 10, 25, 50, 100};
const int n = 4;
vector<int> darab(n + 1);

void SOsszeg(const int &i, const int &S);
void Kiir(const int &j);

int main() {
    SOsszeg(1, 100);

    return 0;
}

void SOsszeg(const int &i, const int &S) {
    if (i == n) {
        if (S % b[n] == 0) {
            darab[n] = S / b[n];

            Kiir(n);
        }
    } else {
        for (int j = 0; j <= S / b[i]; ++j) {
            darab[i] = j;
            int maradt = S - j * b[i];

            if (maradt == 0) {
                Kiir(i);
            } else {
                SOsszeg(i + 1, maradt);
            }
        }
    }
}

void Kiir(const int &j) {
    for (int i = 1; i <= j; ++i) {
        cout << b[i] << " * " << darab[i] << '\n';
    }

    cout << '\n';
}