#include <iostream>
#include "RendezettLista.h"

using namespace std;

int main() {
    auto *rl = new RendezettLista;

    Inicializal(rl);

    BeszurVegere(rl, 1);
    BeszurVegere(rl, 2);
    BeszurVegere(rl, 3);
    BeszurVegere(rl, 4);

    Kiir(rl);

    TorolDuplikatum(rl);

    Kiir(rl);

    return 0;
}
