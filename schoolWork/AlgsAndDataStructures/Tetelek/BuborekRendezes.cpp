// Rendezések

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

template <typename T>
void Buborek_Rendezes(vector<T> &X);

int main() {
    vector<int> X {4, 1, 6, 3, 78, 1};

    Buborek_Rendezes(X);

    for (const auto &e : X) {
        cout << e << ' ';
    }

    return 0;
}

template <typename T>
void Buborek_Rendezes(vector<T> &X) {
    bool rendben;
    int nn;
    int k = X.size();

    do {
        nn = k - 1;
        rendben = true;

        for (int i = 0; i < nn; ++i) {
            if (X[i] > X[i + 1]) {
                rendben = false;
                swap(X[i], X[i + 1]);
                k = i + 1;
            }
        }
    } while (!rendben);
}