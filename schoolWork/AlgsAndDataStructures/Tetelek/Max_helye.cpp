// Sorozatszámítás
// 1 sorozathoz érték rendelése

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
size_t Max_helye(const vector<T> &X);

template <typename T>
vector<size_t> Minden_max_1(const vector<T> &X);

template <typename T>
vector<size_t> Minden_max_2(const vector<T> &X);

int main() {
    // cout << Max_helye(vector<int>{1, 1, 1, 2, 3, 4, 5, 5, 5}) << endl;

    auto eredmeny = Minden_max_2(vector<int>{1, 1, 1, 2, 3, 4, 5, 5, 5});
    for (const auto &i : eredmeny) {
        cout << i << ' ';
    }

    return 0;
}

template <typename T>
size_t Max_helye(const vector<T> &X) {
    size_t hely = 0;

    for (size_t i = 1; i < X.size(); ++i) {
        if (X[hely] < X[i]) {
            hely = i;
        }
    }

    return hely;
}

template <typename T>
vector<size_t> Minden_max_1(const vector<T> &X) {
    T max = X[0];

    for (size_t i = 1; i < X.size(); ++i) {
        if (max < X[i]) {
            max = X[i];
        }
    }

    vector<size_t> indexek;

    for (size_t i = 0; i < X.size(); ++i) {
        if (X[i] == max) {
            indexek.push_back(i);
        }
    }

    return indexek;
}

template <typename T>
vector<size_t> Minden_max_2(const vector<T> &X) {
    T max = X[0];
    vector<size_t> indexek {0};

    for (size_t i = 1; i < X.size(); ++i) {
        if (max < X[i]) {
            max = X[i];
            indexek.clear();
            indexek.push_back(i);
        } else {
            if (max == X[i]) {
                indexek.push_back(i);
            }
        }
    }

    return indexek;
}