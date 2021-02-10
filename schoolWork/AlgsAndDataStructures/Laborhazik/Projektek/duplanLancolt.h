#ifndef PROJEKTEK_DUPLANLANCOLT_H
#define PROJEKTEK_DUPLANLANCOLT_H

#include <string>

using namespace std;

typedef string ElemTipus;

struct ListaElem {
    ElemTipus info;
    ListaElem* elozo = nullptr;
    ListaElem* kov = nullptr;
};

struct DuplanLancoltLista {
    ListaElem *elso; // strázsa
    ListaElem *utolso; // strázsa

    DuplanLancoltLista() {
        auto *p = new ListaElem;
        auto *q = new ListaElem;

        elso = p;
        utolso = q;

        elso->kov = utolso;
        utolso->elozo = elso;
    }

    bool Ures() const {
        return this->elso->kov == this->utolso;
    }

    void BeszurHatulra(const ElemTipus& inf) {
        auto *p = new ListaElem;

        this->utolso->info = inf;

        this->utolso->kov = p;
        p->elozo = this->utolso;

        this->utolso = p;
    }

    void BeszurElore(const ElemTipus& inf) {
        auto *p = new ListaElem;

        this->elso->info = inf;

        this->elso->elozo = p;
        p->kov = this->elso;

        this->elso = p;
    }

    void BeszurEle(const ElemTipus& keresett, const ElemTipus& inf) {
        auto *p = this->Keres(keresett);

        if (p) {
            auto *q = new ListaElem;

            q->info = inf;

            p->elozo->kov = q;
            q->elozo = p->elozo;
            q->kov = p;
            p->elozo = q;
        } else {
            this->BeszurElore(inf);
        }
    }

    void BeszurUtan(const ElemTipus& keresett, const ElemTipus &inf) {
        auto *p = this->Keres(keresett);

        if (p) {
            auto *q = new ListaElem;

            q->info = inf;

            p->kov->elozo = q;
            q->kov = p->kov;
            q->elozo = p;
            p->kov = q;
        } else {
            this->BeszurHatulra(inf);
        }
    }

    void BejarElolrol() const {
        auto *p = this->elso->kov;

        while (p != this->utolso) {
            cout << p->info << ' ';
            p = p->kov;
        }

        cout << '\n';
    }

    void BejarHatulrol() const {
        auto *p = this->utolso->elozo;

        while (p != this->elso) {
            cout << p->info << ' ';
            p = p->elozo;
        }

        cout << '\n';
    }

    ListaElem* Keres(const ElemTipus &inf) {
        auto *p = this->elso->kov;

        while (p != this->utolso) {
            if (p->info == inf) {
                return p;
            } else {
                p = p->kov;
            }
        }

        return nullptr;
    }

    void Torol(const ElemTipus &inf) {
        auto *p = this->Keres(inf);

        if (p) {
            p->elozo->kov = p->kov;
            p->kov->elozo = p->elozo;
            delete p;
        } else {
            cout << "Elem nem talalhato\n";
        }
    }
};

#endif //PROJEKTEK_DUPLANLANCOLT_H
