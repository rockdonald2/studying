#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void valogatasos_rendezes(vector<T> &X);

int main() {
    vector<int> X {5, 3, 2, 5, 1, 4};

    valogatasos_rendezes(X);

    for (const auto &e : X) {
        cout << e << ' ';
    }

    return 0;
}

template<typename T>
void valogatasos_rendezes(vector<T> &X) {
    vector<T> rendezett_sor(X.size());
    vector<bool> rendezett_sor_index(X.size(), false);

    for (int i = 0; i < X.size(); ++i) {
        int k = 0;

        for (int j = 0; j < X.size(); ++j) {
            if (X[i] > X[j]) {
                ++k;
            }
        }

        while (rendezett_sor_index[k]) {
            ++k;
        }

        rendezett_sor[k] = X[i];
        rendezett_sor_index[k] = true;
    }

    X = rendezett_sor;
}