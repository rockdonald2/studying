#ifndef TETELEK_RENDEZETTLISTA_H
#define TETELEK_RENDEZETTLISTA_H

#include <iostream>

using namespace std;

typedef int ElemTipus;

struct ListaElem {
    ElemTipus info;
    ListaElem *kov = nullptr;
};

struct RendezettLista {
    ListaElem *elso;
    ListaElem *utolso;
};

void Init(RendezettLista &l) {
    l.elso = nullptr;
    l.utolso = nullptr;
}

bool Ures(RendezettLista l) {
    return l.elso == nullptr;
}

ListaElem* Keres(RendezettLista l, const ElemTipus &keresett) {
    if (!Ures(l)) {
        auto *p = l.elso;

        while (p) {
            if (p->info >= keresett) {
                return p;
            } else {
                p = p->kov;
            }
        }

        return nullptr;
    } else {
        return nullptr;
    }
}

void BeszurVegere(RendezettLista &l, const ElemTipus &elem) {
    auto *p = new ListaElem;
    p->info = elem;

    if (Ures(l)) {
        l.elso = p;
    } else {
        l.utolso->kov = p;
    }

    l.utolso = p;
}

void Beszur(RendezettLista &l, const ElemTipus &elem) {
    if (!Ures(l)) {
        auto *p = Keres(l, elem);

        if (p) {
            auto *q = new ListaElem;

            *q = *p;

            p->info = elem;
            p->kov = q;

            if (p == l.utolso) {
                l.utolso = q;
            }
        } else {
            BeszurVegere(l, elem);
        };
    } else {
        BeszurVegere(l, elem);
    }
}

void Torol(RendezettLista &l, const ElemTipus &torlendo) {
    if (!Ures(l)) {
        auto *p = Keres(l, torlendo);

        if (p == l.elso) {
            l.elso = l.elso->kov;

            if (l.elso == nullptr) {
                l.utolso = nullptr;
            }

            delete p;
        } else if (p == l.utolso) {
            auto *q = l.elso;

            while (q->kov->kov) {
                q = q->kov;
            }

            q->kov = nullptr;
            l.utolso = q;
            delete p;
        } else {
            auto *q = p->kov;
            *p = *q;
            delete q;
        }
    }
}

void Kiir(RendezettLista l) {
    if (!Ures(l)) {
        auto *p = l.elso;

        while (p) {
            cout << p->info << ' ';
            p = p->kov;
        }

        cout << '\n';
    } else {
        cout << "Lista ures\n";
    }
}

void Megszuntet(RendezettLista &l) {
    if (!Ures(l)) {
        ListaElem* p;

        while (l.elso) {
            p = l.elso;
            l.elso = l.elso->kov;
            delete p;
        }

        l.utolso = nullptr;
    }
}

#endif //TETELEK_RENDEZETTLISTA_H
