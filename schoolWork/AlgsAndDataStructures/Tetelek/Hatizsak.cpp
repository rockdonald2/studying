#include <iostream>
#include <vector>

using namespace std;

void Hatizsak(const vector<int> &zsakok, const int &S);
int Binaris_Kereses(const vector<int> &X, int bal, int jobb, int keresett);

int main() {
    int S;
    int n;
    cin >> S >> n;

    vector<int> zsakok(n);

    for (int i = 0; i < n; ++i) {
        cin >> zsakok[i];
    }

    sort(zsakok.begin(), zsakok.end());

    Hatizsak(zsakok, S);

    return 0;
}

void Hatizsak(const vector<int> &zsakok, const int &S) {
    int i = 0;
    while (i < (zsakok.size() - 2) && zsakok[i] < S) {
        int j = i + 1;

        while (j < (zsakok.size() - 1) && (zsakok[i] + zsakok[j] < S)) {
            int k = Binaris_Kereses(zsakok, j + 1, zsakok.size() - 1, S - zsakok[i] - zsakok[j]);

            if (k != -1) {
                cout << zsakok[i] << ' ' << zsakok[j] << ' ' << zsakok[k] << '\n';
            }

            ++j;
        }

        ++i;
    }
}

int Binaris_Kereses(const vector<int> &X, int bal, int jobb, int keresett) {
    if (bal > jobb) {
        return -1;
    } else {
        int kozep = bal + (jobb - bal) / 2;

        if (X[kozep] == keresett) {
            return kozep;
        } else {
            if (X[kozep] < keresett) {
                return Binaris_Kereses(X, kozep + 1, jobb, keresett);
            } else {
                return Binaris_Kereses(X, bal, kozep - 1, keresett);
            }
        }
    }
}