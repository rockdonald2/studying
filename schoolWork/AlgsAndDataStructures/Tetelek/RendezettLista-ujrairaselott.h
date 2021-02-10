#ifndef TETELEK_RENDEZETTLISTA_H
#define TETELEK_RENDEZETTLISTA_H

#include <iostream>

using namespace std;

typedef char ElemTipus;

struct ListaTipus {
    ElemTipus info;
    ListaTipus *kov = nullptr;
};

struct RendezettLista {
    ListaTipus *elso;
    ListaTipus *utolso;

    RendezettLista() {
        this->elso = nullptr;
        this->utolso = nullptr;
    }

    bool Ures() const {
        return this->elso == nullptr;
    }

    void BeszurasVegere(const ElemTipus &inf) {
        auto *p = new ListaTipus;

        p->info = inf;

        if (this->Ures()) {
            this->elso = p;
        } else {
            this->utolso->kov = p;
        }

        this->utolso = p;
    }

    ListaTipus *Keres(const ElemTipus &keresett) const {
        auto *p = this->elso;
        bool nincs = true;

        while (p && nincs) {
            if (p->info >= keresett) {
                nincs = false;
            } else {
                p = p->kov;
            }
        }

        return p;
    }

    void BeszurEle(const ElemTipus &inf) {
        auto *p = this->Keres(inf);

        if (p) {
            auto *q = new ListaTipus;

            *q = *p;

            p->info = inf;
            p->kov = q;

            if (p == this->utolso) {
                this->utolso = q;
            }
        } else {
            cout << "Nem talalhato a listaban ilyen elem\n";
        }
    }

    void Torol(const ElemTipus &torlendo) {
        auto *p = this->Keres(torlendo);

        if (p) {
            if (p->kov) {
                auto *q = p->kov;
                *p = *q;
                delete q;
            } else {
                auto *q = this->elso;

                while (q->kov->kov) {
                    q = q->kov;
                }

                p = q->kov;
                q->kov = nullptr;
                this->utolso = q;
                delete p;
            }
        } else {
            cout << "Nem talalhato a listaban ilyen elem\n";
        }
    }

    void TorolUtan(const ElemTipus &torlendoElotti) {
        auto *p = this->Keres(torlendoElotti);

        if (p != this->utolso) {
            auto *q = p->kov;
            p->kov = p->kov->kov;
            delete q;
        } else {
            cout << "Nincs torlendo utani elem\n";
        }
    }

    void TorolElott(const ElemTipus &torlendoUtani) {
        auto *p = this->Keres(torlendoUtani);

        if (p != this->elso) {
            auto *q = this->elso;
            bool nincs = true;

            while (q != this->utolso && nincs) {
                if (q->kov->kov == p) {
                    nincs = false;
                } else {
                    q = q->kov;
                }
            }

            if (!nincs) {
                auto *z = q->kov;
                q->kov = q->kov->kov;
                delete z;
            }
        } else {
            cout << "Nincs torlendo elotti elem\n";
        }
    }

    void Kiir() const {
        if (!this->Ures()) {
            auto *p = this->elso;

            while (p) {
                cout << p->info << ' ';
                p = p->kov;
            }

            cout << '\n';
        } else {
            cout << "A rendezett lista ures\n";
        }
    }
};

#endif //TETELEK_RENDEZETTLISTA_H
