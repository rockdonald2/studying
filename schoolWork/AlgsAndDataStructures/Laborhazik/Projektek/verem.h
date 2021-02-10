#ifndef PROJEKTEK_VEREM_H
#define PROJEKTEK_VEREM_H

#include <string>

using namespace std;

typedef char ElemTipus;

struct VeremTipus {
    ElemTipus info;
    VeremTipus* kov = nullptr;
};

struct Verem {
    VeremTipus* fej;

    Verem() {
        this->fej = nullptr;
    }

    void Init() {
        this->fej = nullptr;
    }

    bool Ures() const {
        return this->fej == nullptr;
    }

    void Beilleszt(const ElemTipus& inf) {
        auto *p = new VeremTipus;

        p->info = inf;
        p->kov = this->fej;

        this->fej = p;
    }

    void Torol() {
        if (!this->Ures()) {
            VeremTipus* p = this->fej;

            this->fej = this->fej->kov;

            delete p;
        } else {
            cout << "A verem ures\n";
        }
    }

    void Felszabadit() {
        if (!this->Ures()) {
            VeremTipus *p;

            while (this->fej) {
                p = this->fej;
                this->fej = this->fej->kov;
                delete p;
            }
        } else {
            cout << "A verem ures\n";
        }
    }

    VeremTipus* Lemasol() const {
        return !this->Ures() ? this->fej : nullptr;
    }

    void Kiir() const {
        if (!this->Ures()) {
            VeremTipus* p = this->fej;

            while (p) {
                cout << p->info << ' ';
                p = p->kov;
            }
        } else {
            cout << "A verem ures\n";
        }
    }
};

#endif //PROJEKTEK_VEREM_H
