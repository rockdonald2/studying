#ifndef PROJEKTEK_LISTA_H
#define PROJEKTEK_LISTA_H

#include <iostream>
#include "ListaElem.h"

struct Lista {
    ListaElem *fej;
    ListaElem *utolso;
    bool statikus = false;
    int hossz = 0;
    int max_hossz = 15;

    Lista(const bool &statikus = false, const int &m_h = 15) {
        // inicializáláskor a lista üres, és nincs korlátozva annak mérete
        // ha statikus, megadja annak méretét is, különben 15
        this->fej = nullptr;
        this->utolso = nullptr;
        this->statikus = statikus;
        this->max_hossz = m_h;
    }

    bool Ures() const {
        // akkor üres, ha a fej NULL, nincs egyetlen elem sem a listában
        return this->fej == nullptr;
    }

    bool Tele() const {
        return this->hossz == this->max_hossz && this->statikus;
    }

    ListaElem *LemasolElso() const {
        // téríti az első elemet
        return this->fej;
    }

    ListaElem *Keres(const ElemTipus &elem) const {
        // visszatéríti azt a listaelemet, amely a bemeneti paraméterrel megegyező információs mezővel bír

        auto *p = this->fej;

        while (p && p->info != elem) {
            p = p->kov;
        }

        return p;
    }

    void BeszurHatul(const ElemTipus &uj) {
        // beszúr a lista végére egy új elemet,
        // ha statikus ellenőrzi azt, hogy tele van-e

        if (!this->Tele()) {
            auto *p = new ListaElem;

            p->info = uj;

            if (this->Ures()) {
                this->fej = p;
            } else {
                this->utolso->kov = p;
            }

            this->utolso = p;

            if (this->statikus) {
                this->hossz++;
            }
        } else {
            std::cout << "A lista tele van\n";
        }
    }

    void BeszurElol(const ElemTipus &uj) {
        // beszúr a lista elejére egy új elemet,
        // ha statikus ellenőrzi azt, hogy tele van-e

        if (!this->Tele()) {
            auto *p = new ListaElem;

            p->info = uj;
            p->kov = this->fej;

            this->fej = p;

            if (this->statikus) {
                this->hossz++;
            }
        } else {
            std::cout << "A lista tele van\n";
        }
    }

    void BeszurUtan(const ElemTipus &utan, const ElemTipus &uj) {
        // beszúr egy adott szó után,
        // ha statikus ellenőrzi azt, hogy tele van-e

        if (!this->Tele()) {
            auto *p = this->Keres(utan);

            if (p) {
                auto *n = new ListaElem;
                n->info = uj;
                n->kov = p->kov;

                if (p == this->utolso) {
                    this->utolso = n;
                }

                p->kov = n;

                if (this->statikus) {
                    this->hossz++;
                }
            } else {
                this->BeszurHatul(uj);
            }
        } else {
            std::cout << "A lista tele van\n";
        }
    }

    void BeszurJelenlevo(const ElemTipus &jv) {
        // ha az adott jelenlevő már benne van a listában kiveszi azt, ellenkező esetben beszúrja a végére

        auto *p = this->Keres(jv);

        if (!p) {
            this->BeszurHatul(jv);
        } else {
            this->Torol(jv);
        }
    }

    void Torol(const ElemTipus &elem) {
        auto *r = this->Keres(elem);

        if (r) {
            if (r == this->fej) {
                // ha a törlendő elem az első,
                // akkor ha egyetlen elemből állt a lista, az utolsó mutatót is aktualizálja,
                // ellenkező esetben csak frissíti a fej mutatót

                if (this->fej == this->utolso) {
                    this->utolso = nullptr;
                }

                this->fej = this->fej->kov;

                delete r;
            } else if (r->kov) {
                // ha valamelyik közbeeső elem a törlendő, nem az utolsó, nem az első

                auto *q = r->kov;
                *r = *q;

                if (q == this->utolso) {
                    this->utolso = r;
                }

                delete q;
            } else {
                // az utolsó elem a törlendő elem

                auto *q = this->fej;

                while (q->kov->kov) {
                    q = q->kov;
                }

                q->kov = nullptr;
                this->utolso = q;

                delete r;
            }

            if (this->statikus) {
                this->hossz--;
            }
        }
    }

    void Kiir() const {
        // kiírjuk a listát

        if (!this->Ures()) {
            auto *p = this->fej;

            while (p) {
                std::cout << p->info << ' ';
                p = p->kov;
            }

            std::cout << '\n';
        } else {
            std::cout << "A lista ures\n";
        }
    }
};

#endif //PROJEKTEK_LISTA_H
