#include <iostream>

using namespace std;

int hatvany(const int &x, const int &n);

int main() {
    cout << hatvany(2, 4) << endl;

    return 0;
}

int hatvany(const int &x, const int &n) {
    if (n == 0) {
        return 1;
    } else {
        return x * hatvany(x, n - 1);
    }
}