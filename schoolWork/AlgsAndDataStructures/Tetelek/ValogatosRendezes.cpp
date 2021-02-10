// Rendezések

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void Valogatos_Rendezes(vector<T> &X);

int main() {
    vector<int> X {4, 1, 6, 3, 78};

    Valogatos_Rendezes(X);

    for (const auto &e : X) {
        cout << e << ' ';
    }

    return 0;
}

template <typename T>
void Valogatos_Rendezes(vector<T> &X) {
    vector<T> rendezett_sor(X.size());

    size_t k = 0;
    for (size_t i = 0; i < X.size(); ++i) {
        k = 0;

        for (size_t j = 0; j < X.size(); ++j) {
            if (X[i] > X[j]) {
                ++k;
            }
        }

        rendezett_sor[k] = X[i];
    }

    X = rendezett_sor;
}