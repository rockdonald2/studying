#include <iostream>
#include <string>
#include "DuplanLancolt.h"

using namespace std;

int main() {
    DuplanLancoltLista l;
    Init(l);
    KiirElolrol(l);
    BeszurElejere(l, "o");
    BeszurEle(l, "o", "h");
    BeszurUtana(l, "o", "d");
    KiirElolrol(l);
    BeszurVegere(l, "u");
    KiirElolrol(l);
    Torol(l, "u");
    KiirElolrol(l);
    Megszuntet(l);

    return 0;
}