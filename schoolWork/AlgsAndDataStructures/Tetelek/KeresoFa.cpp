#include <iostream>
#include <vector>
#include "KeresoFa.h"

using namespace std;

int main() {
    auto *gy = new Fa;

    Inicializal(gy);

    cout << Ures(gy) << '\n';

    vector<int> tmp {4, 6, 3, 8, 1, 5, 2, 7};

    for (const auto &e : tmp) {
        Beszur(gy, e);
    }

    Inorder(gy);

    cout << Minim(gy) << '\n';
    cout << Maxim(gy) << '\n';

    Megszuntet(gy);

    return 0;
}