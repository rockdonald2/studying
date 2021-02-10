// Rendezések

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void Felcsereleses_Rendezes(vector<T> &X);

int main() {
    vector<int> X {4, 1, 6, 3, 78};

    Felcsereleses_Rendezes(X);

    for (const auto &e : X) {
        cout << e << ' ';
    }

    return 0;
}

template <typename T>
void Felcsereleses_Rendezes(vector<T> &X) {
    for (int i = 0; i < X.size() - 1; ++i) {
        for (int j = i + 1; j < X.size(); ++j) {
            if (X[i] > X[j]) {
                int id = X[i];
                X[i] = X[j];
                X[j] = id;
            }
        }
    }
}