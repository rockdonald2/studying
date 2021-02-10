#include <iostream>
#include "RendezettLista.h"

using namespace std;

int main() {
    RendezettLista l;
    Init(l);
    Kiir(l);
    Beszur(l, 1);
    Beszur(l, 2);
    Beszur(l, 3);
    Beszur(l, 0);
    Kiir(l);
    Torol(l, 0);
    Torol(l, 3);
    Kiir(l);
    Megszuntet(l);

    return 0;
}