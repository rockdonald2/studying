// Sorozatokhoz sorozat rendelése
// Halmazműveletek

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
vector<T> Keresztmetszet(const vector<T> &X, const vector<T> &Y);

int main() {
    vector<int> X {1, 2, 3, 5};
    vector<int> Y {2, 5, 1, 3};

    auto Z = Keresztmetszet(X, Y);

    for (const auto &e : Z) {
        cout << e << ' ';
    }

    return 0;
}

template <typename T>
vector<T> Keresztmetszet(const vector<T> &X, const vector<T> &Y) {
    vector<T> Z;

    for (int i = 0; i < X.size(); ++i) {
        int j = 0;

        while (j < Y.size() && X[i] != Y[j]) {
            ++j;
        }

        if (j < Y.size()) {
            Z.push_back(X[i]);
        }
    }

    return Z;
}