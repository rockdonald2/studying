#ifndef TETELEK_KERESOFA_H
#define TETELEK_KERESOFA_H

#include <iostream>

using namespace std;

typedef int ElemTipus;

struct Fa {
    ElemTipus info;
    Fa* bal = nullptr;
    Fa* jobb = nullptr;
};

void Inicializal(Fa* &f) {
    f = nullptr;
}

bool Ures(Fa* f) {
    return f == nullptr;
}

Fa* Keres(Fa* f, const ElemTipus &elem) {
    if (f) {
        if (f->info == elem) {
            return f;
        } else {
            if (f->info < elem) {
                return Keres(f->jobb, elem);
            } else {
                return Keres(f->bal, elem);
            }
        }
    } else {
        return nullptr;
    }
}

void Beszur(Fa* &f, const ElemTipus &elem) {
    if (f) {
        if (f->info < elem) {
            Beszur(f->jobb, elem);
        } else {
            if (f->info > elem) {
                Beszur(f->bal, elem);
            }
        }
    } else {
        f = new Fa;
        f->info = elem;
    }
}

void in(Fa* f) {
    if (f) {
        in(f->bal);
        cout << f->info << ' ';
        in(f->jobb);
    }
}

void Inorder(Fa* f) {
    in(f);
    cout << '\n';
}

int Minim(Fa* f) {
    while (f->bal) {
        f = f->bal;
    }

    return f->info;
}

int Maxim(Fa* f) {
    while (f->jobb) {
        f = f->jobb;
    }

    return f->info;
}

void Megszuntet(Fa* &f) {
    if (!Ures(f)) {
        Megszuntet(f->bal);
        Megszuntet(f->jobb);
        delete f;
    }
}

#endif //TETELEK_KERESOFA_H
