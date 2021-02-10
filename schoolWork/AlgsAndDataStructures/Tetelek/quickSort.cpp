#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

void QuickSort(vector<int> &x, const int &bal, const int &jobb);
int Feloszt(vector<int> &x, const int &bal, const int &jobb);
int Veletlen_Feloszt(vector<int> &x, const int &bal, const int& jobb);

int main() {
    vector<int> a {15, 20, 40, 60, 50, 85, 90};

    QuickSort(a, 0, a.size() - 1);

    for (const auto &e : a) {
        cout << e << ' ';
    }

    return 0;
}

void QuickSort(vector<int> &x, const int &bal, const int &jobb) {
    if (bal < jobb) {
        int m = Feloszt(x, bal, jobb);
        QuickSort(x, bal, m - 1);
        QuickSort(x, m + 1, jobb);
    }
}

int Feloszt(vector<int> &x, const int &bal, const int &jobb) {
    int strazsa = x[bal];
    int i = bal;
    int j = jobb;

    while (i < j) {
        while (x[i] < strazsa) {
            ++i;
        }

        while (x[j] > strazsa) {
            --j;
        }

        if (i < j) {
            swap(x[i], x[j]);
        }
    }

    return j;
}

int Veletlen_Feloszt(vector<int> &x, const int &bal, const int& jobb) {
    srand(time(nullptr));
    int i = bal + rand() % (jobb - bal);

    swap(x[bal], x[i]);

    return Feloszt(x, bal, jobb);
}