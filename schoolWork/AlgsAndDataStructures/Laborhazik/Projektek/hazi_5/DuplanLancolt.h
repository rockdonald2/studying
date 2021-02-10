#ifndef PROJEKTEK_DUPLANLANCOLT_H
#define PROJEKTEK_DUPLANLANCOLT_H

#include <string>
#include <iostream>

typedef std::string ElemTipus;

struct ListaElem {
    // információs mező
    ElemTipus info;
    // két kapcsolati információs mező
    ListaElem *kov = nullptr;
    ListaElem *elozo = nullptr;
};

struct DuplanLancolt {
    // strázsás ábrázolás
    ListaElem *elso = new ListaElem; // strázsa
    ListaElem *utolso = new ListaElem; // strázsa

    DuplanLancolt() {
        this->elso->kov = this->utolso;
        this->utolso->elozo = this->elso;
    }

    bool Ures() const {
        // akkor üres, ha nincs egy valódi elem sem a listában
        return this->elso->kov == this->utolso;
    }

    ListaElem* Keres(const ElemTipus &szo) {
        // megkeresi azt az elemet, amely információs mezője a keresettel egyezik meg

        auto *p = this->elso->kov;
        bool nincs = true;

        while (p != this->utolso && nincs) {
            if (p->info == szo) {
                nincs = false;
            } else {
                p = p->kov;
            }
        }

        return p;
    }

    void Be_Ele(const ElemTipus &szo, const ElemTipus &uj) {
        // beszúr egy adott szó elé, ha nem található a szó, a lista elejére

        auto *p = new ListaElem;
        p->info = uj;

        auto *q = this->Keres(szo);

        if (!q) {
            q = this->elso->kov;
        }

        p->elozo = q->elozo;
        p->kov = q;
        q->elozo->kov = p;
        q->elozo = p;
    }

    void Be_Utan(const ElemTipus &szo, const ElemTipus &uj) {
        // beszúr egy adott szó után, ha nem található meg a keresett, akkor a végére

        auto *p = new ListaElem;
        p->info = uj;

        auto *q = this->Keres(szo);

        if (!q) {
            q = this->utolso->elozo;
        }

        q->kov->elozo = p;
        p->kov = q->kov;
        q->kov = p;
        p->elozo = q;
    }

    void Be_Vegere(const ElemTipus &uj) {
        // beszúr a lista végére

        auto *p = new ListaElem;
        p->info = uj;

        this->utolso->elozo->kov = p;
        p->elozo = this->utolso->elozo;
        p->kov = this->utolso;
        this->utolso->elozo = p;
    }

    void Torol(const ElemTipus &szo) {
        // töröl egy adott szót

        auto *p = this->Keres(szo);

        if (p) {
            p->elozo->kov = p->kov;
            p->kov->elozo = p->elozo;
            delete p;
        }
    }

    void Kiir_Elolrol() const {
        // Kiírja a listát előlről hátrafelé

        auto *p = this->elso->kov;

        while (p != this->utolso) {
            std::cout << p->info<< ' ';
            p = p->kov;
        }

        std::cout << '\n';
    }

    void Kiir_Hatulrol() const {
        // Kiírja a listát hátulról előrefelé

        auto *p = this->utolso->elozo;

        while (p != this->elso) {
            std::cout << p->info<< ' ';
            p = p->elozo;
        }

        std::cout << '\n';
    }
};

#endif //PROJEKTEK_DUPLANLANCOLT_H
