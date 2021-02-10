#include <iostream>

using namespace std;

void Koltoztesd(const int &n);

int main() {
    int n;
    cin >> n;

    Koltoztesd(n);

    return 0;
}

void Koltoztesd(const int &n) {
    int oszto = 1;

    int seged = n;
    while (seged >= 10) {
        oszto *= 10;
        seged /= 10;
    }

    int id = n;
    do {
        id = id / oszto + (id % oszto) * 10;
        cout << id << '\n';
    } while (id != n);
}