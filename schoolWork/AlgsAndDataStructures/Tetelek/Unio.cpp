// Sorozatokhoz sorozat rendelése
// Halmazműveletek

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
vector<T> Unio(const vector<T> &X, const vector<T> &Y);

int main() {
    vector<int> X {1, 2, 3, 5, 6};
    vector<int> Y {2, 5, 1, 3};

    auto Z = Unio(X, Y);

    for (const auto &e : Z) {
        cout << e << ' ';
    }

    return 0;
}

template <typename T>
vector<T> Unio(const vector<T> &X, const vector<T> &Y) {
    vector<T> Z(X);

    size_t i = 0;
    for (size_t j = 0; j < Y.size(); ++j) {
        i = 0;

        while (i < X.size() && X[i] != X[j]) {
            ++i;
        }

        if (i >= X.size()) {
            Z.push_back(X[j]);
        }
    }

    return Z;
}