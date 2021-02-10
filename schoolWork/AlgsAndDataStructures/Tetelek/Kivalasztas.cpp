// Sorozatszámítás
// 1 sorozathoz érték rendelése

#include <iostream>
#include <vector>

using namespace std;

template <typename D>
size_t kivalasztas(const vector<D> &X, const D &T);

int main() {
    vector<int> X{1, 2, 3, 4, 5};

    cout << kivalasztas(X, 4) << endl;

    return 0;
}

template <typename D>
size_t kivalasztas(const vector<D> &X, const D &T) {
    size_t hely = 0;

    while (X[hely] != T) {
        ++hely;
    }

    return hely;
}