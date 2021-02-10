// Sorozatszámítás
// 1 sorozathoz érték rendelése

#include <iostream>
#include <vector>

using namespace std;

template <typename D>
size_t Keres_1(const vector<D> &X, const D &T);

template <typename D>
size_t Keres_2(const vector<D> &X, const D &T);

int main() {
    cout << Keres_2(vector<int>{1, 2, 3, 4, 5}, 3) << endl;

    return 0;
}

template <typename D>
size_t Keres_1(const vector<D> &X, const D &T) {
    size_t hely = -1;

    size_t i = 0;
    while (i < X.size() && hely == -1) {
        if (X[i] == T) {
            hely = i;
        } else {
            i += 1;
        }
    }

    return hely;
}

template <typename D>
size_t Keres_2(const vector<D> &X, const D &T) {
    size_t i = 0;

    while (i < X.size() && X[i] != T) {
        i += 1;
    }

    return i < X.size() ? i : -1;
}