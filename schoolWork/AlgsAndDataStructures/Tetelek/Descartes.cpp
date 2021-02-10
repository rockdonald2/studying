#include <iostream>
#include <vector>

using namespace std;

void descartes_szorzat(const int &i);
void kiir();

const int m = 2;
const int n = 3;
static vector<int> x(n + 1, 0);

int main() {
    descartes_szorzat(1);

    return 0;
}

void descartes_szorzat(const int &i) {
    for (int j = 1; j <= m; ++j) {
        x[i] = j;

        if (i < n) {
            descartes_szorzat(i + 1);
        } else {
            kiir();
        }
    }
}

void kiir() {
    cout << "{ " << x[1];

    for (int j = 2; j <= n; ++j) {
        cout << ", " << x[j];
    }

    cout << " }\n";
}