#include <iostream>
#include <vector>

using namespace std;

void reszhalmazok(const int &i);
void kiir(const int &i);

const int n = 3;
static vector<int> x(n + 1, 0);

int main() {
    reszhalmazok(1);

    return 0;
}

void reszhalmazok(const int &i) {
    for (int j = x[i - 1] + 1; j <= n; ++j) {
        x[i] = j;
        kiir(i);
        reszhalmazok(i + 1);
    }
}

void kiir(const int &i) {
    cout << "{ " << x[1];

    for (int j = 2; j <= i; ++j) {
        cout << ", " << x[j];
    }

    cout << " }\n";
}