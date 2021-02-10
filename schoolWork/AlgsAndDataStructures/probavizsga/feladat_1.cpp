/*
 * Hallgató neve: Lukács Zsolt
 * Csoport: GI 1. csoport
 * Azonosító: 3931
 * */

#include <iostream>
#include <vector>

using namespace std;

void torol(vector<int> &a, const int &kuszob);

int main() {
    size_t n;
    cin >> n;

    vector<int> a(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    torol(a, 7);

    for (const auto &e : a) {
        cout << e << ' ';
    }

    return 0;
}

void torol(vector<int> &a, const int &kuszob) {
    size_t hatar = 0;

    // megőrzi a bemeneti sorrendet, mivel mindig sorban fogja előlről haladva
    // az elemeket felülírni
    // haladunk a tömb elejétől, amennyiben kapunk egy olyan értéket
    // amely megfelel a tulajdonságnak, bemásoljuk az aktuális határ indexnek megfelelő helyre
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] % 7) {
            a[hatar++] = a[i];
        }
    }

    a.erase(a.begin() + hatar, a.end());
}