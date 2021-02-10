#include <iostream>
#include "varakozasi_sor.h"

using namespace std;

int main() {
    auto vs = new Varakozasi_Sor;

    vs->Beszur(1);
    vs->Beszur(2);
    vs->Beszur(3);

    cout << vs->Lemasol()->info << '\n';

    vs->Kiir();

    vs->Kivesz();

    vs->Kiir();

    vs->Beszur(4);

    vs->Kiir();

    return 0;
}