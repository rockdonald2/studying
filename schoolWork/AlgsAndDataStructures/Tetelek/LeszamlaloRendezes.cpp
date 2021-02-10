// Rendezések

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void leszamlalo_rendezes_stabil(vector<T> &X);
template <typename T>
void leszamlalo_rendezes(vector<T> &X);

int main() {
    vector<int> X {4, 1, 6, 3, 78, 0, 78, 78};

    leszamlalo_rendezes(X);

    for (const auto &e : X) {
        cout << e << ' ';
    }

    return 0;
}

template <typename T>
void leszamlalo_rendezes_stabil(vector<T> &X) {
    auto max_elem = *(max_element(X.begin(), X.end()));
    auto min_elem = *(min_element(X.begin(), X.end()));
    vector<int> szamlalo(max_elem + 1 - min_elem, 0);
    vector<T> kimenet(X.size());

    for (const auto &e : X) {
        szamlalo[e - min_elem]++;
    }

    for (int i = 1; i < szamlalo.size(); ++i) {
        szamlalo[i] += szamlalo[i - 1];
    }

    for (int i = X.size() - 1; i >= 0; --i) {
        kimenet[szamlalo[X[i] - min_elem] - 1] = X[i];
        szamlalo[X[i] - min_elem]--;
    }

    for (int i = 0; i < X.size(); ++i) {
        X[i] = kimenet[i];
    }
}

template <typename T>
void leszamlalo_rendezes(vector<T> &X) {
    auto max_elem = *(max_element(X.begin(), X.end()));
    auto min_elem = *(min_element(X.begin(), X.end()));
    vector<int> szamlalo(max_elem + 1 - min_elem, 0);
    vector<T> kimenet(X.size());

    for (const auto &e : X) {
        szamlalo[e - min_elem]++;
    }

    int q = 0;
    for (int i = min_elem; i < (max_elem + 1 - min_elem); ++i) {
        for (int j = 1; j <= szamlalo[i - min_elem]; ++j) {
            X[q] = i;
            q++;
        }
    }
}