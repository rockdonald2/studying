#include <iostream>

using namespace std;

bool azonos_szamjegyek(int x);

int main() {
    int a;
    cout << "a = ";
    cin >> a;

    int b;
    cout << "b = ";
    cin >> b;

    bool talalt = false;

    for (int i = a; i <= b; ++i) {
        if (azonos_szamjegyek(i)) {
            cout << i << " ";
            talalt = true;
        }
    }

    if (!talalt) {
        cout << "Nem letezik\n";
    }

    return 0;
}

bool azonos_szamjegyek(int x) {
    int szamjegy = x % 10;
    int hanyados = x / 10;

    while (hanyados) {
        if (szamjegy != hanyados % 10) {
            return false;
        }

        hanyados /= 10;
    }

    return true;
}