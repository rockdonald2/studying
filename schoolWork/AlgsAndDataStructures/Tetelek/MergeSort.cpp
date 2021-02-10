#include <iostream>
#include <vector>

using namespace std;

void Osszefesul(vector<int> &x, const int &bal, const int &kozep, const int &jobb);
void Rendezes(vector<int> &x, const int &bal, const int &jobb);

int main() {
    vector<int> a {15, 20, 40, 60, 50, 85, 90};

    Rendezes(a, 0, a.size() - 1);

    for (const auto &e : a) {
        cout << e << ' ';
    }

    return 0;
}

void Osszefesul(vector<int> &x, const int &bal, const int &kozep, const int &jobb) {
    vector<int> a;
    for (int i = bal; i <= kozep; ++i) {
        a.push_back(x[i]);
    }

    vector<int> b;
    for (int j = kozep + 1; j <= jobb; ++j) {
        b.push_back(x[j]);
    }

    int m1 = a[a.size() - 1];
    int m2 = b[b.size() - 1];
    a.push_back(m2 + 1);
    b.push_back(m1 + 1);

    int i = 0;
    int j = 0;
    for (int k = bal; k <= jobb; ++k) {
        if (a[i] < b[j]) {
            x[k] = a[i];
            ++i;
        } else {
            x[k] = b[j];
            ++j;
        }
    }
}

void Rendezes(vector<int> &x, const int &bal, const int &jobb) {
    if (bal < jobb) {
        int kozep = bal + (jobb - bal) / 2;
        Rendezes(x, bal, kozep);
        Rendezes(x, kozep + 1, jobb);
        Osszefesul(x, bal, kozep, jobb);
    }
}