#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Maximum_Kupacol(vector<int> &A, const int &kupac_meret, const int &i);
void Maximum_Kupac_Epit(vector<int> &A, int &kupac_meret);
void Kupac_Rendezes(vector<int> &A, int &kupac_meret);

int main() {
    vector<int> tomb{0, 8, 5, 7, 9, 2, 1, 13, 7, 33, 11, 4};
    int kupac_meret;

    //Kupac_Rendezes(tomb, kupac_meret);
    Maximum_Kupac_Epit(tomb, kupac_meret);

    for (const auto &e : tomb) {
        cout << e << ' ';
    }

    return 0;
}

void Maximum_Kupacol(vector<int> &A, const int &kupac_meret, const int &i) {
    int bal = 2*i;
    int jobb = 2*i + 1;

    int max;

    if (bal <= kupac_meret && A[bal] > A[i]) {
        max = bal;
    } else {
        max = i;
    }

    if (jobb <= kupac_meret && A[jobb] > A[max]) {
        max = jobb;
    }

    if (max != i) {
        swap(A[i], A[max]);
        Maximum_Kupacol(A, kupac_meret, max);
    }
}

void Maximum_Kupac_Epit(vector<int> &A, int &kupac_meret) {
    kupac_meret = A.size() - 1;
    for (int i = kupac_meret / 2; i >= 1; --i) {
        Maximum_Kupacol(A, kupac_meret, i);
    }
}

void Kupac_Rendezes(vector<int> &A, int &kupac_meret) {
    Maximum_Kupac_Epit(A, kupac_meret);

    for (int i = kupac_meret; i >= 2; --i) {
        swap(A[1], A[i]);
        kupac_meret--;
        Maximum_Kupacol(A, kupac_meret, 1);
    }
}