#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void General(const vector<int> &a, const int &n, const int &S);
int Binaris_Kereses(const vector<int> &x, const int &bal, const int &jobb, const int &keresett);

int main() {
    vector<int> a{0, 0, 5, 6, 11};
    sort(a.begin(), a.end());
    General(a, a.size(), 11);

    return 0;
}

void General(const vector<int> &a, const int &n, const int &S) {
    int i = 0;
    while (i < (n - 2) && a[i] < S) {
        int j = i + 1;

        while (j < (n - 1) && (a[i] + a[j] < S)) {
            int k = Binaris_Kereses(a, j + 1, n - 1, S - a[i] - a[j]);

            if (k != -1) {
                cout << a[i] << " + " << a[j] << " + " << a[k] << " = " << S << '\n';
            }

            ++j;
        }

        ++i;
    }
}

int Binaris_Kereses(const vector<int> &x, const int &bal, const int &jobb, const int &keresett) {
    if (bal > jobb) {
        return -1;
    } else {
        int kozep = (jobb + bal) / 2;

        if (keresett < x[kozep]) {
            return Binaris_Kereses(x, bal, kozep - 1, keresett);
        } else if (keresett > x[kozep]) {
            return Binaris_Kereses(x, kozep + 1, jobb, keresett);
        } else {
            return kozep;
        }
    }
}