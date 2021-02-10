// Sorozatszámítás
// 1 sorozathoz érték rendelése

#include <iostream>
#include <vector>

using namespace std;

template <typename D>
bool Dontes_1(const vector<D> &X, const D &T);

template <typename D>
bool Dontes_2(const vector<D> &X, const D &T);

template <typename D>
bool Dontes_3(const vector<D> &X, const D &T);

template <typename D>
bool Dontes_4(const vector<D> &X, const D &T);

int main() {
    if (Dontes_3(vector<int>{1, 2, 3}, 3)) {
        cout << "Talalt\n";
    } else {
        cout << "Nem talalt\n";
    }

    return 0;
}

template <typename D>
bool Dontes_1(const vector<D> &X, const D &T) {
    bool talalt = false;

    for (const auto &i : X) {
        talalt = talalt || (i == T);
    }

    return talalt;
}

template <typename D>
bool Dontes_2(const vector<D> &X, const D &T) {
    bool talalt = false;

    size_t i = 0;
    while (!talalt && i < X.size()) {
        if (X[i] != T) {
            i += 1;
        } else {
            talalt = true;
        }
    }

    return talalt;
}

template <typename D>
bool Dontes_3(const vector<D> &X, const D &T) {
    int i = 0;
    while (i < X.size() && X[i] != T) {
        ++i;
    }

    return i < X.size();
}

template <typename D>
bool Dontes_4(const vector<D> &X, const D &T) {
    bool mind;

    size_t i = 0;
    while (X[i] == T && i < X.size()) {
        i += 1;
    }

    mind = i >= X.size();

    return mind;
}