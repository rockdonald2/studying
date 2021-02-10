#include <iostream>
#include <string>
#include "DuplanLancolt.h"

using namespace std;

int main() {
    auto *dl = new DuplanLancolt;

    Inicializal(dl);

    cout << Ures(dl) << '\n';

    BeszurVegere(dl, "a");
    BeszurEle(dl, "a", "b");
    BeszurUtan(dl, "a", "c");

    BejarasElolrol(dl);
    BejarasHatulrol(dl);

    Torol(dl, "a");

    BejarasElolrol(dl);
    BejarasHatulrol(dl);

    Torol(dl, "b");
    Torol(dl, "c");
    Torol(dl, "d");

    BejarasElolrol(dl);
    BejarasHatulrol(dl);

    return 0;
}
