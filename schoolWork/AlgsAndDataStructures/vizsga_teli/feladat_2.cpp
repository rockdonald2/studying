#include <iostream>
#include "feladat_2.h"

int main() {
    auto* h1 = Create();
    auto* h2 = Create();

    AddElement(h1, 1);
    AddElement(h1, 2);
    AddElement(h1, 3);
    AddElement(h1, 4);
    AddElement(h1, 5);

    RemoveElement(h1, 1);

    PrintH(h1);

    Destroy(h1);

    return 0;
}