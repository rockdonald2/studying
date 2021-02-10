#include <iostream>
#include "duplanLancolt.h"

using namespace std;

int main() {
    auto *dl = new DuplanLancoltLista;

    dl->BeszurHatulra("a");
    dl->BeszurHatulra("b");
    dl->BeszurHatulra("c");

    dl->BejarElolrol();

    dl->BeszurUtan("a", "g");

    dl->BejarElolrol();

    dl->Torol("g");

    dl->BejarElolrol();

    return 0;
}

