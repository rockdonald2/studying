// Sorozatokhoz sorozat rendelése
// Halmazműveletek

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
vector<T> Egyesites_1(const vector<T> &X, const vector<T> &Y);

template <typename T>
vector<T> Egyesites_2(const vector<T> &X, const vector<T> &Y);

template <typename T>
vector<T> Egyesites_3(vector<T> &X, vector<T> &Y);

template <typename T>
vector<T> Egyesites_4(vector<T> &X, vector<T> &Y);

int main() {
    vector<int> X {3, 4, 5};
    vector<int> Y {1, 2, 3};

    auto Z = Egyesites_4(X, Y);

    for (const auto &e : Z) {
        cout << e << ' ';
    }

    return 0;
}

template <typename T>
vector<T> Egyesites_1(const vector<T> &X, const vector<T> &Y) {
    size_t i = 0;
    size_t j = 0;

    vector<T> Z;

    while (i < X.size() && j < Y.size()) {
        if (X[i] < Y[j]) {
            Z.push_back(X[i]);
            ++i;
        } else {
            Z.push_back(Y[j]);
            ++j;
        }
    }

    while (i < X.size()) {
        Z.push_back(X[i]);
        ++i;
    }

    while (j < Y.size()) {
        Z.push_back(Y[j]);
        ++j;
    }

    return Z;
}

template <typename T>
vector<T> Egyesites_2(const vector<T> &X, const vector<T> &Y) {
    size_t i = 0;
    size_t j = 0;

    vector<T> Z;

    while (i < X.size() && j < Y.size()) {
        if (X[i] < Y[j]) {
            Z.push_back(X[i]);
            ++i;
        } else {
            if (X[i] == Y[j]) {
                Z.push_back(X[i]);
                ++i;
                ++j;
            } else {
                Z.push_back(Y[j]);
                ++j;
            }
        }
    }

    while (i < X.size()) {
        Z.push_back(X[i]);
        ++i;
    }

    while (j < Y.size()) {
        Z.push_back(Y[j]);
        ++j;
    }

    return Z;
}

template <typename T>
vector<T> Egyesites_3(vector<T> &X, vector<T> &Y) {
    size_t i = 0;
    size_t j = 0;

    X.push_back(Y[Y.size() - 1] + 1);
    Y.push_back(X[X.size() - 1] + 1);

    vector<T> Z;

    for (size_t db = 0; db < (X.size() + Y.size() - 2); ++db) {
        if (X[i] < Y[j]) {
            Z.push_back(X[i]);
            ++i;
        } else {
            Z.push_back(Y[j]);
            ++j;
        }
    }

    X.erase(X.begin() + X.size() - 1, X.end());
    Y.erase(Y.begin() + Y.size() - 1, Y.end());
    return Z;
}


template <typename T>
vector<T> Egyesites_4(vector<T> &X, vector<T> &Y) {
    size_t i = 0;
    size_t j = 0;

    X.push_back(Y[Y.size() - 1] + 1);
    Y.push_back(X[X.size() - 1] + 1);
    vector<T> Z;

    while (i < X.size() - 1 || j < Y.size() - 1) {
        if (X[i] < Y[j]) {
            Z.push_back(X[i]);
            ++i;
        } else {
            if (X[i] == Y[j]) {
                Z.push_back(X[i]);
                ++i;
                ++j;
            } else {
                Z.push_back(Y[j]);
                ++j;
            }
        }
    }

    X.erase(X.begin() + X.size() - 1, X.end());
    Y.erase(Y.begin() + Y.size() - 1, Y.end());
    return Z;
}