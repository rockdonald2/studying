#include <iostream>
#include <vector>

using namespace std;

struct Kupac {
    vector<int> K;
    size_t kupac_meret = 0;
};

void Minimum_Kupacol(vector<int> &A, const size_t &kupac_meret, const int &i);
void Minimum_Kupac_Epit(vector<int> &A, size_t &kupac_meret);
void Rendezes(vector<int> &A, size_t &kupac_meret);

int main() {
    Kupac k;
    k.K = vector<int> {0, 12, 23, 1, 3, 100, 20, 18, 7, 2};

    Minimum_Kupac_Epit(k.K, k.kupac_meret);

    for (const auto &e : k.K) {
        cout << e << ' ';
    }

    /*Rendezes(k.K, k.kupac_meret);

    for (const auto &e : k.K) {
        cout << e << ' ';
    }*/

    return 0;
}

void Minimum_Kupacol(vector<int> &A, const size_t &kupac_meret, const int &i) {
    int bal = 2 * i;
    int jobb = 2 * i + 1;

    int min;
    if (bal <= kupac_meret && A[bal] < A[i]) {
        min = bal;
    } else {
        min = i;
    }

    if (jobb <= kupac_meret && A[jobb] < A[min]) {
        min = jobb;
    }

    if (min != i) {
        swap(A[i], A[min]);
        Minimum_Kupacol(A, kupac_meret, min);
    }
}

void Minimum_Kupac_Epit(vector<int> &A, size_t &kupac_meret) {
    kupac_meret = A.size() - 1;

    for (size_t i = kupac_meret / 2; i >= 1; --i) {
        Minimum_Kupacol(A, kupac_meret, i);
    }
}

void Rendezes(vector<int> &A, size_t &kupac_meret) {
    Minimum_Kupac_Epit(A, kupac_meret);

    for (int i = kupac_meret; i >= 2; --i) {
        swap(A[1], A[i]);
        --kupac_meret;
        Minimum_Kupacol(A, kupac_meret, 1);
    }
}