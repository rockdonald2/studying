#include <iostream>

using namespace std;

int faktorialis(const int &n);

int main() {
    cout << faktorialis(5);

    return 0;
}

int faktorialis(const int &n) {
    if (n > 1) {
        return n * faktorialis(n - 1);
    } else {
        return 1;
    }
}