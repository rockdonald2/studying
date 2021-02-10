#include <iostream>
#include <vector>

using namespace std;

void reszhalmazok(const int &i);
void kiir();

static vector<int> x(20, 0);
const int k = 2;
const int n = 3;

int main() {
    reszhalmazok(1);

    return 0;
}

void reszhalmazok(const int &i) {
    for (int j = x[i - 1] + 1; j <= (n - k + i); ++j) {
        x[i] = j;

        if (i < k) {
            reszhalmazok(i + 1);
        } else {
            kiir();
        }
    }
}

void kiir() {
    cout << "{ " << x[1];

    for (int i = 2; i <= k; ++i) {
        cout << ", " << x[i];
    }

    cout << " }\n";
}