#ifndef TETELEK_DUPLANLANCOLT_H
#define TETELEK_DUPLANLANCOLT_H

#include <iostream>
#include <string>

using namespace std;

typedef string ElemTipus;

struct ListaElem {
    ElemTipus info;
    ListaElem *elozo = nullptr;
    ListaElem *kov = nullptr;
};

struct DuplanLancoltLista {
    ListaElem *elso;
    ListaElem *utolso;
};

void Init(DuplanLancoltLista &l) {
    l.elso = new ListaElem;
    l.utolso = new ListaElem;

    l.elso->kov = l.utolso;
    l.utolso->elozo = l.elso;
}

bool Ures(DuplanLancoltLista l) {
    return l.elso->kov == l.utolso;
}

ListaElem* Keres(DuplanLancoltLista l, const ElemTipus &keresett) {
    if (!Ures(l)) {
        auto *p = l.elso;

        while (p) {
            if (p->info == keresett) {
                return p;
            } else {
                p = p->kov;
            }
        }
    }

    return nullptr;
}

void BeszurElejere(DuplanLancoltLista &l, const ElemTipus &elem) {
    auto *p = new ListaElem;
    p->info = elem;

    l.elso->kov->elozo = p;
    p->kov = l.elso->kov;
    p->elozo = l.elso;
    l.elso->kov = p;
}

void BeszurVegere(DuplanLancoltLista &l, const ElemTipus &elem) {
    auto *p = new ListaElem;
    p->info = elem;

    l.utolso->elozo->kov = p;
    p->elozo = l.utolso->elozo;
    p->kov = l.utolso;
    l.utolso->elozo = p;
}

void BeszurEle(DuplanLancoltLista &l, const ElemTipus &ele, const ElemTipus &elem) {
    if (!Ures(l)) {
        auto *p = new ListaElem;
        p->info = elem;

        auto *q = Keres(l, ele);

        if (q) {
            q->elozo->kov = p;
            p->elozo = q->elozo;
            p->kov = q;
            q->elozo = p;
        } else {
            BeszurElejere(l, elem);
        }
    } else {
        BeszurElejere(l, elem);
    }
}

void BeszurUtana(DuplanLancoltLista &l, const ElemTipus &utan, const ElemTipus &elem) {
    if (!Ures(l)) {
        auto *p = new ListaElem;
        p->info = elem;

        auto *q = Keres(l, utan);

        if (q) {
            q->kov->elozo = p;
            p->kov = q->kov;
            p->elozo = q;
            q->kov = p;
        } else {
            BeszurVegere(l, elem);
        }
    } else {
        BeszurVegere(l, elem);
    }
}

void Torol(DuplanLancoltLista &l, const ElemTipus &torlendo) {
    if (!Ures(l)) {
        auto *r = Keres(l, torlendo);

        if (r) {
            r->elozo->kov = r->kov;
            r->kov->elozo = r->elozo;
            delete r;
        }
    }
}

void KiirElolrol(DuplanLancoltLista l) {
    if (!Ures(l)) {
        auto *p = l.elso->kov;

        while (p != l.utolso) {
            cout << p->info << ' ';
            p = p->kov;
        }

        cout << '\n';
    } else {
        cout << "Lista ures\n";
    }
}

void KiirHatulrol(DuplanLancoltLista l) {
    if (!Ures(l)) {
        auto *p = l.utolso->elozo;

        while (p != l.elso) {
            cout << p->info << ' ';
            p = p->elozo;
        }

        cout << '\n';
    } else {
        cout << "Lista ures\n";
    }
}

void Megszuntet(DuplanLancoltLista &l) {
    if (!Ures(l)) {
        ListaElem *p;

        while (!Ures(l)) {
            p = l.elso->kov;
            l.elso->kov = l.elso->kov->kov;
            delete p;
        }
    }
}

#endif //TETELEK_DUPLANLANCOLT_H
