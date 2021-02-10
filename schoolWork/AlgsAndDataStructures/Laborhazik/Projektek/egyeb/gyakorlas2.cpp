#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> tagok(const int &n);

int main() {
    const int n = 10;

    auto t = tagok(n);

    for (const auto &e : t) {
        cout << e << ' ';
    }

    return 0;
}

vector<int> tagok(const int &n) {
    vector<int> fib_szamok{ 1, 1 };

    for (int j = 2; j <= n; ++j) {
        int x = fib_szamok[j - 1] + fib_szamok[j - 2];

        if (x > n) {
            break;
        }

        fib_szamok.push_back(x);
    }

    int seged = n;
    vector<int> t;
    for (int i = fib_szamok.size() - 1; i >= 0; --i) {
        if (fib_szamok[i] <= seged) {
            seged -= fib_szamok[i];
            t.push_back(fib_szamok[i]);
        }
    }

    return t;
}