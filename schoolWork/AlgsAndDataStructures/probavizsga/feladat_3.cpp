/*
 * Hallgató neve: Lukács Zsolt
 * Csoport: GI 1. csoport
 * Azonosító: 3931
 * */

#include <iostream>
#include <vector>

using namespace std;

void beszuro_rendezes(vector<int> &a);

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    beszuro_rendezes(a);

    for (const auto &e : a) {
        cout << e << ' ';
    }

    return 0;
}

void beszuro_rendezes(vector<int> &a) {
    // kimentjük az aktuális elemet,
    // majd minden ennél nagyobb elemet, eggyel előrébb másolunk,
    // majd az utolsó másolás helyénél bemásoljuk a kivett elemet
    for (int i = 1; i < a.size(); ++i) {
        int seged = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > seged) {
            a[j + 1] = a[j];
            --j;
        }

        a[j + 1] = seged;
    }
}