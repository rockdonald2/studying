#include <iostream>
#include <vector>

using ll = long long;

std::vector<ll> max_helye(const std::vector<ll> &X);

int main() {
    std::vector<ll> X {5, 5, 1, 2, 3, 4, 5};

    auto Y = max_helye(X);

    for (const auto &e : Y) {
        std::cout << e << ' ';
    }

    return 0;
}

std::vector<ll> max_helye(const std::vector<ll> &X) {
    std::vector<ll> Y {0};
    ll max = X[0];

    for (int i = 1; i < X.size(); ++i) {
        if (max < X[i]) {
            max = X[i];
            Y.clear();
            Y.push_back(i);
        } else {
            if (max == X[i]) {
                Y.push_back(i);
            }
        }
    }

    return Y;
}