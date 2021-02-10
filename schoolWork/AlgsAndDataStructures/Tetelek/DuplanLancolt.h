#ifndef TETELEK_DUPLANLANCOLT_H
#define TETELEK_DUPLANLANCOLT_H

#include <iostream>
#include <string>

using namespace std;

typedef string ElemTipus;

struct ListaElem {
    ElemTipus info;
    ListaElem* elozo = nullptr;
    ListaElem* kov = nullptr;
};

struct DuplanLancolt {
    ListaElem* elso;
    ListaElem* utolso;
};

void Inicializal(DuplanLancolt* &d) {
    d->elso = new ListaElem;
    d->utolso = new ListaElem;

    d->elso->kov = d->utolso;
    d->utolso->elozo = d->elso;
}

bool Ures(DuplanLancolt* d) {
    return d->elso->kov == d->utolso;
}

ListaElem* Keres(DuplanLancolt* d, const ElemTipus &keresett) {
    if (!Ures(d)) {
        auto *p = d->elso->kov;

        while (p != d->utolso) {
            if (p->info == keresett) {
                return p;
            } else {
                p = p->kov;
            }
        }
    }

    return nullptr;
}

void BeszurEle(DuplanLancolt* &d, const ElemTipus &ele, const ElemTipus &elem) {
    auto *p = Keres(d, ele);

    auto *q = new ListaElem;
    q->info = elem;

    if (!p) {
        p = d->elso->kov;
    }

    p->elozo->kov = q;
    q->elozo = p->elozo;
    q->kov = p;
    p->elozo = q;
}

void BeszurUtan(DuplanLancolt* &d, const ElemTipus &utan, const ElemTipus &elem) {
    auto *p = Keres(d, utan);

    auto *q = new ListaElem;
    q->info = elem;

    if (!p) {
        p = d->utolso->elozo;
    }

    p->kov->elozo = q;
    q->kov = p->kov;
    q->elozo = p;
    p->kov = q;
}

void BeszurVegere(DuplanLancolt* &d, const ElemTipus &elem) {
    auto *p = new ListaElem;
    p->info = elem;

    d->utolso->elozo->kov = p;
    p->elozo = d->utolso->elozo;
    p->kov = d->utolso;
    d->utolso->elozo = p;
}

void Torol(DuplanLancolt* &d, const ElemTipus &elem) {
    auto *p = Keres(d, elem);

    if (p) {
        p->elozo->kov = p->kov;
        p->kov->elozo = p->elozo;
        delete p;
    }
}

void BejarasElolrol(DuplanLancolt* d) {
    if (!Ures(d)) {
        auto *p = d->elso->kov;

        while (p != d->utolso) {
            cout << p->info << ' ';
            p = p->kov;
        }

        cout << '\n';
    } else {
        cout << "Lista ures\n";
    }
}

void BejarasHatulrol(DuplanLancolt* d) {
    if (!Ures(d)) {
        auto *p = d->utolso->elozo;

        while (p != d->elso) {
            cout << p->info << ' ';
            p = p->elozo;
        }

        cout << '\n';
    } else {
        cout << "Lista ures\n";
    }
}

#endif //TETELEK_DUPLANLANCOLT_H
