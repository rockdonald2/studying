#ifndef PROJEKTEK_VEREM_H
#define PROJEKTEK_VEREM_H

#include <iostream>
#include "ListaElem.h"

struct Verem {
    ListaElem* fej;

    Verem() {
        this->fej = nullptr;
    }

    bool Ures() const {
        // akkor üres, ha nincs egy elem sem a veremben, tehát a verem feje NULL
        return this->fej == nullptr;
    }

    void Beszuras(const ElemTipus &uj) {
        // beszúrunk egy új elemet a verembe, ez lesz az első, ami kikerül majd kivevéskor

        auto *p = new ListaElem;
        p->info = uj;

        p->kov = this->fej;
        this->fej = p;
    }

    void Torol() {
        // ha nem üres a verem, kivesszük és töröljük az első elemet

        if (!this->Ures()) {
            auto *p = this->fej;

            this->fej = this->fej->kov;

            delete p;
        }
    }

    ListaElem* Lemasol() const {
        // visszatéríti a verem csúcsát
        return this->fej;
    }

    void Kiir() const {
        // kiírja a vermet

        auto *p = this->fej;

        while (p) {
            std::cout << p->info << ' ';
            p = p->kov;
        }

        std::cout << '\n';
    }
};

#endif //PROJEKTEK_VEREM_H
