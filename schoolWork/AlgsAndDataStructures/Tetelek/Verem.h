#ifndef TETELEK_VEREM_H
#define TETELEK_VEREM_H

#include <iostream>
#include <string>

using namespace std;

typedef string ElemTipus;

struct ListaElem {
    ElemTipus info;
    ListaElem* kov = nullptr;
};

struct Verem {
    ListaElem* csucs;
};

void Inicializal(Verem* &v) {
    v->csucs = nullptr;
}

bool Ures(Verem* v) {
    return v->csucs == nullptr;
}

void Beszur(Verem* &v, const ElemTipus &elem) {
    auto *p = new ListaElem;
    p->info = elem;
    p->kov = v->csucs;
    v->csucs = p;
}

void Torol(Verem* &v) {
    if (!Ures(v)) {
        auto *p = v->csucs;
        v->csucs = v->csucs->kov;
        delete p;
    }
}

ListaElem* Lemasol(Verem* v) {
    return v->csucs;
}

void Megszuntet(Verem* &v) {
    ListaElem* p;

    while (!Ures(v)) {
        p = v->csucs;
        v->csucs = v->csucs->kov;
        delete p;
    }
}

void Kiir(Verem* v) {
    if (!Ures(v)) {
        auto *p = v->csucs;

        while (p) {
            cout << p->info << ' ';
            p = p->kov;
        }

        cout << '\n';
    } else {
        cout << "A verem ures\n";
    }
}

#endif //TETELEK_VEREM_H
