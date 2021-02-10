// Sorozatokhoz sorozat rendelése
// Halmazműveletek

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void Halmazza_alakitas(vector<T> &X);

int main() {
    vector<int> X {1, 2, 3, 3, 3, 4, 5, 5};

    Halmazza_alakitas(X);

    for (const auto &e : X) {
        cout << e << ' ';
    }

    return 0;
}

template <typename T>
void Halmazza_alakitas(vector<T> &X) {
    int i = 0;
    int N = X.size();

    while (i < N) {
        int j = i + 1;

        while (j < N && X[i] != X[j]) {
            ++j;
        }

        if (j < N) {
            X[j] = X[N - 1];
            --N;
        } else {
            ++i;
        }
    }

    X.erase(X.begin() + N, X.end());
}