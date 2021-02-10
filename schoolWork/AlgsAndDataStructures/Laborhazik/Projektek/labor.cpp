#include <iostream>
#include <vector>

using namespace std;

void zarojel(const int &i, const int &ny, const int &z);
const int n = 4;
vector<char> x(n + 1, ' ');

int main() {
    x[1] = '(';
    x[n] = ')';
    zarojel(2, 1, 0);

    return 0;
}

void zarojel(const int &i, const int &ny, const int &z) {
    if (i == n) {
        for (const auto &e : x) {
            cout << e;
        }
        cout << '\n';
    } else {
        if (ny < (n / 2)) {
            x[i] = '(';
            zarojel(i + 1, ny + 1, z);
        }

        if (z < ny) {
            x[i] = ')';
            zarojel(i + 1, ny, z + 1);
        }
    }
}