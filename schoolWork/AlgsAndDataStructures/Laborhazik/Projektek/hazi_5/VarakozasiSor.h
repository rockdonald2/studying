#ifndef PROJEKTEK_VARAKOZASISOR_H
#define PROJEKTEK_VARAKOZASISOR_H

#include <iostream>
#include "ListaElem.h"

struct VarakozasiSor {
    // strázsás ábrázolás
    // fiktív utolsó elem
    ListaElem *strazsa = new ListaElem;
    ListaElem *fej = strazsa;

    VarakozasiSor() {}

    bool Ures() const {
        // akkor üres, ha nincs valódi elem a sorban
        return this->fej == this->strazsa;
    }

    ListaElem* Lemasol() const {
        // visszatéríti az első elemet
        return this->fej;
    }

    void Beszur(const ElemTipus &uj) {
        // beszúrja az új elemet a sorba, amely az utolsó elem lesz

        auto *p = new ListaElem;

        this->strazsa->info = uj;
        this->strazsa->kov = p;

        this->strazsa = p;
    }

    void Kivesz() {
        // kiveszi a sor első elemét, ha az nem üres

        if (!this->Ures()) {
            auto *r = this->fej;

            this->fej = this->fej->kov;

            delete r;
        }
    }

    void Kiir() const {
        // kiírja a sort

        if (!this->Ures()) {
            auto *p = this->fej;

            while (p != this->strazsa) {
                std::cout << p->info << ' ';
                p = p->kov;
            }

            std::cout << '\n';
        } else {
            std::cout << "A sor ures\n";
        }
    }
};

#endif //PROJEKTEK_VARAKOZASISOR_H
