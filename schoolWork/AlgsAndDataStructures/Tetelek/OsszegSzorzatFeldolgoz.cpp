// Sorozatszámítás
// 1 sorozathoz érték rendelése

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
T feldolgoz(const vector<T> &X);

int main() {
    cout << feldolgoz(vector<int>{1, 2, 3, 4, 5}) << endl;

    return 0;
}

template <typename T>
T feldolgoz(const vector<T> &X) {
    T S = 0;

    for (const auto &e : X) {
        S += e;
    }

    return S;
}