#include <iostream>
#include <vector>

using namespace std;

const int n = 7;
static const vector<int> b{0, 25, 50, 100, 150, 200, 250, 300};
static vector<int> darab(n + 1, 0);

void Fizet(const int &i, const int &S);
void Kiir(const int &i);

int main() {
    Fizet(1, 300);

    return 0;
}

void Fizet(const int &i, const int &S) {
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
                Fizet(i + 1, maradt);
            }
        }
    }
}

void Kiir(const int &i) {
    for (int j = 1; j <= n - 1; ++j) {
        cout << darab[j] << "*" << b[j] << " + ";
    }

    cout << darab[n] << "*" << b[n];

    cout << '\n';
}