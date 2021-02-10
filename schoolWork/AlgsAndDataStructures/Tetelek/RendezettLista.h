#ifndef TETELEK_RENDEZETTLISTA_H
#define TETELEK_RENDEZETTLISTA_H

#include <iostream>
#include <string>

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

void Inicializal(RendezettLista *&r) {
    r->elso = nullptr;
    r->utolso = nullptr;
}

bool Ures(RendezettLista *r) {
    return r->elso == nullptr;
}

ListaElem *Keres(RendezettLista *r, const ElemTipus &elem) {
    if (!Ures(r)) {
        auto *p = r->elso;
        bool nincs = true;

        while (p && nincs) {
            if (p->info >= elem) {
                nincs = false;
            } else {
                p = p->kov;
            }
        }

        return nincs ? nullptr : p;
    } else {
        return nullptr;
    }
}

void BeszurVegere(RendezettLista *&r, const ElemTipus &elem) {
    auto *p = new ListaElem;
    p->info = elem;

    if (Ures(r)) {
        r->elso = p;
    } else {
        r->utolso->kov = p;
    }

    r->utolso = p;
}

void BeszurEle(RendezettLista *&r, const ElemTipus &elem) {
    auto *p = Keres(r, elem);

    if (p) {
        auto *q = new ListaElem;
        *q = *p;
        p->info = elem;
        p->kov = q;

        if (r->utolso == p) {
            r->utolso = q;
        }
    } else {
        BeszurVegere(r, elem);
    }
}

void Torol(RendezettLista *&r, const ElemTipus &elem) {
    if (!Ures(r)) {
        auto *p = Keres(r, elem);

        if (p) {
            if (p == r->elso) {
                r->elso = r->elso->kov;
                if (!r->elso) {
                    r->utolso = nullptr;
                }
                delete p;
            } else if (p->kov) {
                auto *q = p->kov;
                *p = *q;

                if (q == r->utolso) {
                    r->utolso = p;
                }

                delete q;
            } else {
                auto *q = r->elso;

                while (q->kov->kov) {
                    q = q->kov;
                }

                q->kov = nullptr;
                r->utolso = q;
                delete p;
            }
        }
    }
}

void TorolUtan(RendezettLista *&r, const ElemTipus &elem) {
    auto *p = Keres(r, elem);

    if (p != r->utolso && p) {
        auto *q = p->kov;
        p->kov = q->kov;
        delete q;
    }
}

void TorolElott(RendezettLista *&r, const ElemTipus &elem) {
    auto *p = r->elso;

    if (p != r->elso) {
        while (p && p->kov->info != elem) {
            p = p->kov;
        }

        if (p) {
            auto *q = p->kov;
            p->kov = q->kov;
            delete q;
        }
    }
}

void Kiir(RendezettLista *r) {
    if (!Ures(r)) {
        auto *p = r->elso;

        while (p) {
            cout << p->info << ' ';
            p = p->kov;
        }

        cout << '\n';
    } else {
        cout << "A lista ures\n";
    }
}

void TorolDuplikatum(RendezettLista *&r) {
    if (!r->elso->kov) {
        return;
    }

    auto *p{r->elso};

    while (p != r->utolso) {
        auto *n{p->kov};

        if (p->info == p->kov->info) {
            if (p == r->elso) {
                r->elso = r->elso->kov;
                n = r->elso->kov;
                delete p;
            } else {
                auto *q{p->kov};
                *p = *q;

                if (q == r->utolso) {
                    r->utolso = p;
                    n = r->utolso;
                } else {
                    n = p;
                }

                delete q;
            }
        }

        p = n;
    }
}

#endif //TETELEK_RENDEZETTLISTA_H
