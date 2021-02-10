#include <iostream>
#include <vector>

using namespace std;

const int n = 6;
vector<int> X {2, 4, 1, 6, 5, 10};

int Feloszt(const int &bal, const int &jobb);
void Rendez(const int &bal, const int &jobb);

int main() {
    Rendez(0, n - 1);

    for (const auto &e : X) {
        cout << e << ' ';
    }

    return 0;
}

int Feloszt(const int &bal, const int &jobb) {
    int strazsa = X[bal];
    int i = bal;
    int j = jobb;

    while (i < j) {
        while (X[i] < strazsa) {
            ++i;
        }

        while (X[j] > strazsa) {
            --j;
        }

        if (i < j) {
            swap(X[i], X[j]);
        }
    }

    return j;
}

void Rendez(const int &bal, const int &jobb) {
    if (bal < jobb) {
        int m = Feloszt(bal, jobb);
        Rendez(bal, m - 1);
        Rendez(m + 1, jobb);
    }
}