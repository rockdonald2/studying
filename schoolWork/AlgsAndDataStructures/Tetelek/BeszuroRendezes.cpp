// Rendezések

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void Beszuro_Rendezes(vector<T> &X);

int main() {
    vector<int> X {4, 1, 6, 3, 78};

    Beszuro_Rendezes(X);

    for (const auto &e : X) {
        cout << e << ' ';
    }

    return 0;
}

template <typename T>
void Beszuro_Rendezes(vector<T> &X) {
    for (int i = 1; i < X.size(); ++i) {
        T seged = X[i];
        int j = i - 1;

        while (j >= 0 && X[j] > seged) {
            X[j + 1] = X[j];
            --j;
        }

        X[j + 1] = seged;
    }
}