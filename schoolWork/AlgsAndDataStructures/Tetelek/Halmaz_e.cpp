// Sorozatokhoz sorozat rendelése
// Halmazműveletek

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
bool Halmaz_e(const vector<T> &X);

int main() {
    vector<int> X {1, 2, 3, 4, 5};

    if (Halmaz_e(X)) {
        cout << "Halmaz\n";
    } else {
        cout << "Nem halmaz\n";
    }

    return 0;
}

template <typename T>
bool Halmaz_e(const vector<T> &X) {
    bool ok = true;
    int i = 0;

    while (i < X.size() && ok) {
        int j = i + 1;

        while (j < X.size() && X[i] != X[j]) {
            ++j;
        }

        ok = j >= X.size();
        ++i;
    }

    return ok;
}