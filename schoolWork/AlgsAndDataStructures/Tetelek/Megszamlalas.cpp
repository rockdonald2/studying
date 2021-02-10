// Sorozatszámítás
// 1 sorozathoz érték rendelése

#include <iostream>
#include <vector>

using namespace std;

template<typename D>
size_t Megszamlalas(const vector<D> &X, const D &T);

int main() {
    cout << Megszamlalas(vector<int>{1, 2, 3, 4, 5}, 1) << endl;

    return 0;
}

template<typename D>
size_t Megszamlalas(const vector<D> &X, const D &T) {
    size_t db = 0;

    for (const auto &i : X) {
        if (i == T) {
            db += 1;
        }
    }

    return db;
}