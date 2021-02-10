#include <iostream>
#include <vector>

using namespace std;

void Maximum_Kupacol(vector<int> &X, const int &kupac_meret, const int &i);
void Maximum_Kupac_Epit(vector<int> &X, int &kupac_meret);
int Kivesz_Maximum(vector<int> &X, int &kupac_meret);
int Maximum(vector<int> &s, const int &kupac_meret);
void Kulcsot_Novel(vector<int> &X, const int &kupac_meret, int i, const int &kulcs);
void Beszur(vector<int> &X, int &kupac_meret, const int &kulcs);

int main() {
    vector<int> tmp {0, 4, 6, 3, 8, 1, 5, 2, 7};
    int kupac_meret;

    Maximum_Kupac_Epit(tmp, kupac_meret);

    cout << Maximum(tmp, kupac_meret) << '\n';

    cout << Kivesz_Maximum(tmp, kupac_meret) << '\n';

    Kulcsot_Novel(tmp, kupac_meret, 5, 10);

    Beszur(tmp, kupac_meret, 15);
    Beszur(tmp, kupac_meret, 1);

    for (int i = 1; i <= kupac_meret; ++i) {
        cout << tmp[i] << ' ';
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

void Beszur(vector<int> &X, int &kupac_meret, const int &kulcs) {
    ++kupac_meret;
    X.push_back(INT8_MIN);
    Kulcsot_Novel(X, kupac_meret, kupac_meret, kulcs);
}

void Kulcsot_Novel(vector<int> &X, const int &kupac_meret, int i, const int &kulcs) {
    if (i <= kupac_meret && kulcs >= X[i]) {
        X[i] = kulcs;

        while (i > 1 && X[i / 2] < X[i]) {
            swap(X[i], X[i / 2]);
            i /= 2;
        }
    }
}

int Maximum(vector<int> &s, const int &kupac_meret) {
    if (kupac_meret > 0) {
        return s[1];
    } else {
        return -1;
    }
}

int Kivesz_Maximum(vector<int> &X, int &kupac_meret) {
    if (kupac_meret > 0) {
        int elem = X[1];
        swap(X[1], X[kupac_meret]);
        --kupac_meret;
        Maximum_Kupacol(X, kupac_meret, 1);
        return elem;
    } else {
        return -1;
    }
}