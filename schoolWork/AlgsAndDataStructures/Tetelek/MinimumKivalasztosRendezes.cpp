// Rendezések

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void Kivalasztos_Rendezes(vector<T> &X);

int main() {
    vector<int> X {4, 1, 6, 3, 78};

    Kivalasztos_Rendezes(X);

    for (const auto &e : X) {
        cout << e << ' ';
    }

    return 0;
}

template <typename T>
void Kivalasztos_Rendezes(vector<T> &X) {
    for (int i = 0; i < X.size() - 1; ++i) {
        int ind_min = i;

        for (int j = i + 1; j < X.size(); ++j) {
            if (X[j] < X[ind_min]) {
                ind_min = j;
            }
        }

        if (ind_min != i) {
            int seged = X[i];
            X[i] = X[ind_min];
            X[ind_min] = seged;
        }
    }
}