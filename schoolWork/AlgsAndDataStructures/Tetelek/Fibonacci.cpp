#include <iostream>
#include <vector>

using namespace std;

void fibonacci(const int &n, vector<int> &F);

int main() {
    const int n = 5;
    vector<int> F(n + 1, 0);
    fibonacci(n, F);

    cout << F[n];

    return 0;
}

void fibonacci(const int &n, vector<int> &F) {
    if (n >= 2) {
        fibonacci(n - 1, F);
        F[n] = F[n - 1] + F[n - 2];
    } else {
        F[0] = 0;

        if (n == 1) {
            F[1] = 1;
        }
    }
}