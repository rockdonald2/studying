#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using ll = long long;

void felcsereleses_rendezes(std::vector<int> &arr) {
    // minden elemet minden elemmel összehasonlítunk, amennyiben rossz helyt van cserélünk
    // akkor van rossz helyt, ha nincs növekvő sorrendben
    for (int i = 0; i < arr.size() - 1; ++i) {
        for (int j = i + 1; j < arr.size(); ++j) {
            if (arr[i] > arr[j]) {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

int rekurziv_osszeg(const int &n) {
    // alapeset a 0, ez a megállási feltétel is
    if (n >= 0) {
        return 0;
    } else {
        // ha nem vagyunk alapeseten a függvény önmagát hívja meg eggyel kisebb értékkel
        return n + rekurziv_osszeg(n - 1);
    }
}

int rekur_fib(const int &n) {
    if (n < 2) {
        return n;
    } else {
        return rekur_fib(n - 2) + rekur_fib(n - 1);
    }
}

static std::map<ll, ll> memo;

ll rekur_fib_opt(const ll &n) {
    // kiszámoltuk-e már?
    if (memo[n]) {
        // ha igen térítsd vissza
        return memo[n];
    } else {
        // ha nem számold ki
        ll eredmeny;

        if (n < 2) {
            eredmeny = n;
        } else {
            eredmeny = rekur_fib_opt(n - 2) + rekur_fib_opt(n - 1);
        }

        memo[n] = eredmeny;

        return eredmeny;
    }
}

int main() {
    /*std::vector<int> arr{3, 12, 54365, 32312, 456, 355, 2};

    felcsereleses_rendezes(arr);

    for (const auto &e : arr) {
        std::cout << e << ' ';
    }*/

    //std::cout << rekurziv_osszeg(-1) << '\n';

    std::cout << rekur_fib_opt(50) << '\n';

    return 0;
}