#include <iostream>
#include <vector>

using namespace std;

const int n = 4;
vector<char> x(n + 1, ' ');

void Zarojelek(const int &i, const int &ny, const int &z);

int main() {
    x[1] = '(';
    x[n] = ')';
    Zarojelek(2, 1, 0);

    return 0;
}

void Zarojelek(const int &i, const int &ny, const int &z) {
    if (i == n) {
        for (const auto &e : x) {
            cout << e;
        }

        cout << '\n';
    } else {
        if (ny < (n / 2)) {
            x[i] = '(';
            Zarojelek(i + 1, ny + 1, z);
        }

        if (z < ny) {
            x[i] = ')';
            Zarojelek(i + 1, ny, z + 1);
        }
    }
}