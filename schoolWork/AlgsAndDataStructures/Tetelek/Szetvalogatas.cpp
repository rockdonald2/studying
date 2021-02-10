// Sorozatokhoz sorozatok rendelése

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
vector<vector<T>> Szetvalogatas_1(const vector<T> &X);

template <typename T>
vector<T> Szetvalogatas_2(const vector<T> &X);

template <typename T>
void Szetvalogatas_3(vector<T> &X);

int main() {
    vector<int> X {100, 900, 500, 200};

    /* auto YZ = Szetvalogatas_1(X);

    for (const auto &e : YZ) {
        std::cout << '[';

        for (const auto &w : e) {
            cout << w << ", ";
        }

        std::cout << "]\n";
    } */

    /* auto Y = Szetvalogatas_2(X);

    for (const auto &e : Y) {
        cout << e << ' ';
    } */

    Szetvalogatas_3(X);

    for (const auto &e : X) {
        cout << e << ' ';
    }

    return 0;
}

template <typename T>
vector<vector<T>> Szetvalogatas_1(const vector<T> &X) {
    vector<vector<int>> XY(2);

    for (size_t i = 0; i < X.size(); ++i) {
        if (X[i] >= 500) {
            XY[0].push_back(X[i]);
        } else {
            XY[1].push_back(X[i]);
        }
    }

    return XY;
}

template <typename T>
vector<T> Szetvalogatas_2(const vector<T> &X) {
    vector<T> Y;

    for (size_t i = 0; i < X.size(); ++i) {
        if (X[i] >= 500) {
            Y.insert(Y.begin(), X[i]);
        } else {
            Y.push_back(X[i]);
        }
    }

    return Y;
}

template <typename T>
void Szetvalogatas_3(vector<T> &X) {
    size_t i = 0;
    size_t j = X.size() - 1;

    while (i < j) {
        if (X[i] < 500 && X[j] >= 500) {
            T temp = X[i];
            X[i] = X[j];
            X[j] = temp;

            ++j;
            --j;
        } else if (X[i] >= 500) {
            ++i;
        } else {
            --j;
        }
    }
}