#include <iostream>
#include <string>

using namespace std;

void fordit(const int &n);

int main() {
    fordit(3);

    return 0;
}

void fordit(const int &n) {
    string szo;

    cin >> szo;

    if (n > 1) {
        fordit(n - 1);
    } else {
        cout << "Forditott sorrendben: ";
    }

    cout << szo;
    cout << ' ';
}