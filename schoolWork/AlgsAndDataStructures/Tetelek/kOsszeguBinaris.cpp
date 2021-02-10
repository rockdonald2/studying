#include <iostream>

using namespace std;

void kOsszeguBinaris(const int &a, const int &b, const int &k);

int main() {
    int a;
    int b;
    int k;

    cin >> a >> b >> k;

    kOsszeguBinaris(a, b, k);

    return 0;
}

void kOsszeguBinaris(const int &a, const int &b, const int &k) {
    for (int i = a; i <= b; ++i) {
        int osszeg = 0;
        int id = i;

        while (id > 0) {
            osszeg += id % 2;
            id /= 2;
        }

        if (osszeg == k) {
            cout << i << '\n';
        }
    }
}