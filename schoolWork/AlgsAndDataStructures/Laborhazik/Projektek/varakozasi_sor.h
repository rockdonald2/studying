#ifndef PROJEKTEK_VARAKOZASI_SOR_H
#define PROJEKTEK_VARAKOZASI_SOR_H

#include <iostream>
using namespace std;

typedef int ElemTipus;

struct ListaElem {
    ElemTipus info;
    ListaElem* kov = nullptr;
};

struct Varakozasi_Sor {
private:
    ListaElem *fej;
    ListaElem *utolso;
    int jelenHossz = 0;
    int maxHossz = 50;
public:
    Varakozasi_Sor() {
        this->fej = nullptr;
        this->utolso = nullptr;
    }

    bool Ures() const {
        return this->fej == nullptr;
    }

    bool Tele() const {
        return this->jelenHossz == this->maxHossz;
    }

    ListaElem* Lemasol() const {
        return this->fej;
    }

    void Beszur(const ElemTipus &inf) {
        auto *p = new ListaElem;
        p->info = inf;

        if (this->Ures()) {
            this->fej = p;
        } else {
            this->utolso->kov = p;
        }

        this->utolso = p;
        ++jelenHossz;
    }

    ElemTipus Kivesz() {
        auto *r = this->fej;
        this->fej = r->kov;
        auto elem = r->info;

        if (this->Ures()) {
            this->utolso = nullptr;
        }

        delete r;
        --jelenHossz;
        return elem;
    }

    void Kiir() const {
        auto *p = this->fej;

        while (p) {
            cout << p->info << ' ';
            p = p->kov;
        }

        cout << '\n';
    }
};

#endif //PROJEKTEK_VARAKOZASI_SOR_H
