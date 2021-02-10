#ifndef TETELEK_KORKOROSLISTA_H
#define TETELEK_KORKOROSLISTA_H

#include <iostream>
#include <string>

using namespace std;

typedef string ElemTipus;

struct ListaElem {
    ElemTipus info;
    ListaElem* kov = nullptr;
};

struct KorkorosLista {
    ListaElem* strazsa;
    ListaElem* utolso;

    KorkorosLista() {
        this->strazsa = new ListaElem;
        this->utolso = this->strazsa;
    }

    bool Ures() const {
        return this->utolso == this->strazsa;
    }

    void Kiir() const {
        if (this->Ures()) return;

        std::cout << "Meg jatszanak:\n";

        auto *p = this->strazsa->kov;
        int i = 1;

        while (p != this->utolso) {
            cout << i << ". " << p->info << '\n';
            p = p->kov;
            ++i;
        }

        cout << i << ". " << p->info << '\n';
    }

    void Beolvas() {
        int n;
        cout << "n = ";
        cin >> n;
        cin.get();

        for (int i = 1; i <= n; ++i) {
            auto *p = new ListaElem;

            cout << i << ". neve: ";
            cin >> p->info;

            this->utolso->kov = p;
            this->utolso = p;
        }

        this->utolso->kov = this->strazsa->kov;
    }

    void Szamol(const int &k) {
        if (this->Ures()) return;

        auto *p = this->strazsa->kov;

        while (p != p->kov) {
            for (int i = 1; i < k; ++i) {
                p = p->kov;
            }

            cout << "Kilep: " << p->info << '\n';

            if (p->kov == this->strazsa->kov) {
                this->strazsa->kov = this->strazsa->kov->kov;
            }

            if (p->kov == this->utolso) {
                this->utolso = p;
            }

            auto *q = p->kov;
            *p = *q;
            delete q;

            this->Kiir();
        }

        cout << '\n' << "A nyertes: " << p->info << '\n';
    }
};

#endif //TETELEK_KORKOROSLISTA_H
