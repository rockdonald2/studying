// Sorozathoz sorozat rendelés
// Kiválogatás

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

template <typename D>
vector<D> Kivalogatas_1(const vector<D> &X, const D &T);

template <typename D>
void Kivalogatas_2(const vector<D> &X, const D &T);

template <typename D>
void Kivalogatas_3(vector<D> &X, const D &T);

template <typename D>
vector<bool> Kivalogatas_4(vector<D> &X, const D &T);

template <typename D>
void Kivalogatas_5(vector<D> &X, const D &T);

template <typename D>
void Kivalogatas_6(vector<D> &X, const D &T);

int main() {
    vector<int> bemenet {5, 2, 3, 1, 5};

    /*auto kimenet = Kivalogatas_1(bemenet, 5);

    for (const auto &i : kimenet) {
        cout << i << ' ';
    }*/

    //Kivalogatas_2(bemenet, 5);

    /* Kivalogatas_3(bemenet, 5);

    for (const auto &i : bemenet) {
        cout << i << ' ';
    } */

    /* auto kimenet = Kivalogatas_4(bemenet, 5);

    for (const auto &i : kimenet) {
        cout << i << ' ';
    } */

    Kivalogatas_5(bemenet, 5);

    for (const auto &i : bemenet) {
        cout << i << ' ';
    }

    /*Kivalogatas_6(bemenet, 5);

    for (const auto &i : bemenet) {
        cout << i << ' ';
    }*/

    return 0;
}

template <typename D>
vector<D> Kivalogatas_1(const vector<D> &X, const D &T) {
    vector<D> Y;

    for (size_t i = 0; i < X.size(); ++i) {
        if (X[i] == T) {
            Y.push_back(i);
        }
    }

    return Y;
}

template <typename D>
void Kivalogatas_2(const vector<D> &X, const D &T) {
    for (size_t i = 0; i < X.size(); ++i) {
        if (X[i] == T) {
            cout << X[i] << ' ';
        }
    }
}

template <typename D>
void Kivalogatas_3(vector<D> &X, const D &T) {
    size_t i = 0;
    int N = X.size();

    while (i < N) {
        if (X[i] != T) {
            X[i] = X[N - 1];
            N--;
        } else {
            i++;
        }
    }

    X.erase(X.begin() + i, X.end());
}

template <typename D>
vector<bool> Kivalogatas_4(vector<D> &X, const D &T) {
    vector<bool> torolt(X.size(), false);

    for (size_t i = 0; i < X.size(); ++i) {
        torolt[i] = !(X[i] == T);
    }

    return torolt;
}

template <typename D>
void Kivalogatas_5(vector<D> &X, const D &T) {
    int db = 0;

    for (int i = 0; i < X.size(); ++i) {
        if (X[i] == T) {
            X[db] = X[i];
            db++;
        }
    }

    X.erase(X.begin() + db, X.end());
}

template <typename D>
void Kivalogatas_6(vector<D> &X, const D &T) {
    for (size_t i = 0; i < X.size(); ++i) {
        if (X[i] != T) {
            X[i] = -1;
        }
    }
}