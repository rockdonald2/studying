/*
 * Hallgató neve: Lukács Zsolt
 * Csoport: GI 1. csoport
 * Azonosító: 3931
 * */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * 0 1 1 2 3 5 8 13
 * 8 + 5 = 13, 8 + 3 = 11, 8 + 2 = 10;
 * 5 + 3 = 8; 5 + 3 + 2 = 10;
 * 3 + 2 = 5; 3 + 2 + 1 = 6; 3 + 2 + 1 + 1 = 7;
 * */

/*
 * 1 + 1 + 2 + 3 + 5 = 12
 * 1 + 2 + 3 + 5 = 11
 * 2 + 3 + 5 = 10
 * */

void keres_osszeg(const int &n);

int main() {
    int n;
    do {
        cin >> n;
    } while (n < 0);

    keres_osszeg(n);

    return 0;
}

void keres_osszeg(const int &n) {
    vector<int> fib_szamok {1, 1};
    string eredmeny;

    // legeneráljuk a fibonacci számokat, addig amíg kisebbek, mint a szám amit vizsgálunk
    for (int i = 2; i <= n; ++i) {
        int x = fib_szamok[i - 1] + fib_szamok[i - 2];

        if (x >= n) {
            break;
        }

        fib_szamok.push_back(x);
    }

    int seged = n;
    for (int i = fib_szamok.size() - 1; i > 0; --i) {
        if (fib_szamok[i] <= seged) {
            eredmeny += to_string(fib_szamok[i]);
            eredmeny += " ";
            seged -= fib_szamok[i];
        }
    }

    cout << eredmeny << '\n';
}