#include <iostream>
#include <vector>

using namespace std;

void MaximumKivalasztasosRendezes(vector<int> &a);

int main() {
    vector<int> a {8, 7, 6, 10, 4, 11, 2, 5, 9};

    MaximumKivalasztasosRendezes(a);

    for (const auto &e : a) {
        cout << e << ' ';
    }

    return 0;
}

void MaximumKivalasztasosRendezes(vector<int> &a) {
    for (int i = a.size() - 1; i > 0; --i) {
        int ind_max = i;

        for (int j = 0; j < i; ++j) {
            if (a[ind_max] < a[j]) {
                ind_max = j;
            }
        }

        if (ind_max != i) {
            swap(a[i], a[ind_max]);
        }
    }
}