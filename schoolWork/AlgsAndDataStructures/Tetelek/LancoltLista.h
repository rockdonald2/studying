#ifndef TETELEK_LANCOLTLISTA_H
#define TETELEK_LANCOLTLISTA_H

#include <iostream>
#include <string>

using namespace std;

typedef int ElemTipus;

struct ListaElem {
    ElemTipus info;
    ListaElem* kov = nullptr;
};

struct Lista {
    ListaElem *elso;
    ListaElem *utolso;
};

void Init(Lista &l) {
    l.elso = nullptr;
    l.utolso = nullptr;
}

bool Ures(Lista l) {
    return l.elso == nullptr;
}

ListaElem* Keres(Lista l, const ElemTipus &keresett) {
    auto *p = l.elso;

    while (p) {
        if (p->info == keresett) {
            return p;
        } else {
            p = p->kov;
        }
    }

    return nullptr;
}

void BeszurVegere(Lista &l, const ElemTipus &elem) {
    auto *p = new ListaElem;
    p->info = elem;

    if (Ures(l)) {
        l.elso = p;
    } else {
        l.utolso->kov = p;
    }

    l.utolso = p;
}

void BeszurEle(Lista &l, const ElemTipus &ele, const ElemTipus &elem) {
    if (!Ures(l)) {
        auto *p = Keres(l, ele);

        if (p) {
            auto *q = new ListaElem;
            *q = *p;

            if (p == l.utolso) {
                l.utolso = q;
            }

            p->info = elem;
            p->kov = q;
        } else {
            BeszurVegere(l, elem);
        }
    } else {
        BeszurVegere(l, elem);
    }
}

void Torol(Lista &l, const ElemTipus &torlendo) {
    if (!Ures(l)) {
        auto *p = Keres(l, torlendo);

        auto *q = p->kov;

        *p = *q;

        if (q == l.utolso) {
            l.utolso = p;
        }

        delete q;
    }
}

void Megszuntet(Lista &l) {
    if (!Ures(l)) {
        ListaElem *p;

        while (l.elso) {
            p = l.elso;
            l.elso = l.elso->kov;
            delete p;
        }
    }
}

void Kiir(Lista l) {
    if (!Ures(l)) {
        auto *p = l.elso;

        while (p) {
            cout << p->info << ' ';
            p = p->kov;
        }

        cout << '\n';
    } else {
        cout << "A lista ures\n";
    }
}

void Rendez(Lista &l) {
    auto* jel = l.elso;
    ListaElem* rendezettFej = nullptr;

    while (jel) {
        auto* dummy = jel->kov;

        if (!rendezettFej || rendezettFej->info >= jel->info) {
            jel->kov = rendezettFej;
            rendezettFej = jel;
        } else {
            auto* p = rendezettFej;

            while (p->kov && p->kov->info < jel->info) {
                p = p->kov;
            }

            jel->kov = p->kov;
            p->kov = jel;
        }

        jel = dummy;
    }

    l.elso = rendezettFej;
}

#endif //TETELEK_LANCOLTLISTA_H
