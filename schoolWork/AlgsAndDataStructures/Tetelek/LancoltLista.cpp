#include <iostream>
#include <string>
#include "LancoltLista.h"

using namespace std;

int main() {
    Lista l;
    Init(l);
    BeszurVegere(l, 4);
    BeszurVegere(l, 2);
    BeszurVegere(l, 1);
    BeszurVegere(l, 3);
    Kiir(l);
    Rendez(l);
    Kiir(l);

    return 0;
}
