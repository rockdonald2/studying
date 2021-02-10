#include <iostream>
#include <string>
#include "VarakozasiSor.h"

int main() {
    auto *v = new VarakozasiSor;

    Inicializal(v);

    cout << Ures(v) << '\n';

    Beszur(v, "a");
    Beszur(v, "b");
    Beszur(v, "c");

    Kiir(v);

    Torol(v);

    Kiir(v);

    Megszuntet(v);

    Kiir(v);

    return 0;
}