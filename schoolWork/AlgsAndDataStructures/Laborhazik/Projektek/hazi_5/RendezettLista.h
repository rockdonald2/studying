#ifndef PROJEKTEK_RENDEZETTLISTA_H
#define PROJEKTEK_RENDEZETTLISTA_H

#include <iostream>

struct ListaElem {
    // információs mezők
    std::string nev;
    int psz;
    // kapcsolati mező
    ListaElem* kov = nullptr;
};

struct RendezettLista {
    // első és utolsó elemek, az utolsó a lista végéhez való hozzáfűzéshez kell
    ListaElem* fej;
    ListaElem* utolso;

    RendezettLista() {
        this->fej = nullptr;
        this->utolso = nullptr;
    }

    bool Ures() const {
        // akkor üres, ha a fej NULL, nincs egy elem sem a rendezett listában
        return this->fej == nullptr;
    }

    ListaElem* Keres(const std::string &v, const int &psz) const {
        // megkeresi az adott pontszámú ugró helyét a listában,
        // annak az elemnek a mutatóját téríti, amely elé bekell szúrni az új elemet,
        // az első olyan elemet, amelynek pontszáma kisebb, mint a beszurandó

        ListaElem *p = this->fej;

        while (p) {
            if (p->nev == v || p->psz <= psz) {
                return p;
            } else {
                p = p->kov;
            }
        }

        return nullptr;
    }

    void Koze(ListaElem *p, const std::string &v, const int &psz) {
        // beszúrja egy adott elem elé az új elemet,
        // ha az utolsó volt a megkeresett elem, az utolsó előtti lesz az új elem, aktualizálja az utolsó mutatót

        if (p) {
            auto *q = new ListaElem;

            *q = *p;

            p->nev = v;
            p->psz = psz;
            p->kov = q;

            if (this->utolso == p) {
                this->utolso = q;
            }
        } else {
            this->Vegere(v, psz);
        }
    }

    void Vegere(const std::string &v, const int &psz) {
        // beszúrja a végére,
        // ha üres volt a lista mind az elsőt, mind az utolsó mutatókat aktualizálja

        auto *p = new ListaElem;
        p->nev = v;
        p->psz = psz;

        if (this->Ures()) {
            this->fej = p;
        } else {
            this->utolso->kov = p;
        }

        this->utolso = p;
    }

    void Torles(const std::string &v, const int &psz) {
        auto *r = this->Keres(v, psz);

        if (r) {
            if (r == this->fej) {
                // amennyiben az elsőt kell töröljük,
                // kezelve azt az esetet, amikor az első egyben utolsó elem is

                if (this->fej == this->utolso) {
                    this->utolso = nullptr;
                }

                this->fej = this->fej->kov;

                delete r;
            } else if (r->kov) {
                // amennyiben valamelyik közbeesőt

                auto *q = r->kov;
                *r = *q;

                if (q == this->utolso) {
                    this->utolso = r;
                }

                delete q;
            } else {
                // amennyiben az utolsót

                auto *q = this->fej;

                while (q->kov->kov) {
                    q = q->kov;
                }

                q->kov = nullptr;
                this->utolso = q;

                delete r;
            }
        }
    }

    void Kiir() const {
        // kiírja a teljes listát

        auto *p = this->fej;
        int i = 1;

        while (p) {
            std::cout << i << ": " << p->nev << " pontszama " << p->psz << '\n';
            ++i;
            p = p->kov;
        }

        std::cout << '\n';
    }

    void Kiir3() const {
        // kiírja az első hármat

        auto *p = this->fej;
        int i = 1;

        while (i <= 3 && p) {
            std::cout << i << ": " << p->nev << " pontszama " << p->psz << '\n';
            ++i;
            p = p->kov;
        }

        std::cout << '\n';
    }
};

#endif //PROJEKTEK_RENDEZETTLISTA_H
