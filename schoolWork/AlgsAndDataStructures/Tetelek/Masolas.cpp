// Sorozathoz sorozat rendelés
// Másolás

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
vector<T> Masolas(const vector<T> &X);

int main() {
    vector<double> bemenet {1.0, 2.0, 3.0, 4.0, 5.0};

    auto kimenet = Masolas(bemenet);

    for (const auto &i : kimenet) {
        cout << i << ' ';
    }

    return 0;
}

template <typename T>
vector<T> Masolas(const vector<T> &X) {
    vector<T> Y;

    for (const auto &i : X) {
        Y.push_back(i + 1);
    }

    return Y;
}