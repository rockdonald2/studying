#include <iostream>

using namespace std;

int lnko(const int &a, const int &b);

int main() {
    cout << lnko(13, 36);

    return 0;
}

int lnko(const int &a, const int &b) {
    int maradek = a % b;

    if (maradek == 0) {
        return b;
    } else {
        return lnko(b, maradek);
    }
}