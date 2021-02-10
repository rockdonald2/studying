#ifndef TETELEK_VARAKOZASISOR_H
#define TETELEK_VARAKOZASISOR_H

#include <iostream>
#include <string>

using namespace std;

typedef string ElemTipus;

struct ListaElem {
    ElemTipus info;
    ListaElem* kov = nullptr;
};

struct VarakozasiSor {
    ListaElem *strazsa;
    ListaElem *fej;
};

void Inicializal(VarakozasiSor* &s) {
    s->strazsa = new ListaElem;
    s->fej = s->strazsa;
}

bool Ures(VarakozasiSor* s) {
    return s->fej == s->strazsa;
}

void Beszur(VarakozasiSor* &s, const ElemTipus &elem) {
    auto *p = new ListaElem;

    s->strazsa->info = elem;
    s->strazsa->kov = p;

    s->strazsa = p;
}

void Torol(VarakozasiSor* &s) {
    if (!Ures(s)) {
        auto *p = s->fej;
        s->fej = s->fej->kov;
        delete p;
    }
}

void Megszuntet(VarakozasiSor* &s) {
    if (!Ures(s)) {
        ListaElem* p;

        while (!Ures(s)) {
            p = s->fej;
            s->fej = s->fej->kov;
            delete p;
        }
    }
}

void Kiir(VarakozasiSor* s) {
    if (!Ures(s)) {
        auto *p = s->fej;

        while (p != s->strazsa) {
            cout << p->info << ' ';
            p = p->kov;
        }

        cout << '\n';
    } else {
        cout << "A varakozasi sor ures\n";
    }
}

#endif //TETELEK_VARAKOZASISOR_H
