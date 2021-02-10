#include <iostream>
#include <vector>

using namespace std;

void Maximum_Kupacol(vector<int> &X, const int &kupac_meret, const int &i);
void Maximum_Kupac_Epit(vector<int> &X, int &kupac_meret);
void Kupac_Rendezes(vector<int> &X, int &kupac_meret);

int main() {
    vector<int> tmp {0, 12, 23, 1, 3, 100, 20, 18, 7, 2};
    int kupac_meret;

    Maximum_Kupac_Epit(tmp, kupac_meret);

    for (const auto &e : tmp) {
        cout << e << ' ';
    }

    return 0;
}

void Maximum_Kupacol(vector<int> &X, const int &kupac_meret, const int &i) {
    int bal = 2 * i;
    int jobb = 2 * i + 1;

    int max;

    if (bal <= kupac_meret && X[bal] > X[i]) {
        max = bal;
    } else {
        max = i;
    }

    if (jobb <= kupac_meret && X[max] < X[jobb]) {
        max = jobb;
    }

    if (max != i) {
        swap(X[i], X[max]);
        Maximum_Kupacol(X, kupac_meret, max);
    }
}

void Maximum_Kupac_Epit(vector<int> &X, int &kupac_meret) {
    kupac_meret = X.size() - 1;

    for (int i = kupac_meret / 2; i >= 1; --i) {
        Maximum_Kupacol(X, kupac_meret, i);
    }
}

void Kupac_Rendezes(vector<int> &X, int &kupac_meret) {
    Maximum_Kupac_Epit(X, kupac_meret);

    for (int i = kupac_meret; i >= 2; --i) {
        swap(X[1], X[i]);
        --kupac_meret;
        Maximum_Kupacol(X, kupac_meret, 1);
    }
}