#ifndef TETELEK_BINARISFA_H
#define TETELEK_BINARISFA_H

#include <iostream>
#include <vector>

using namespace std;
typedef int ElemTipus;

struct Fa {
    ElemTipus info;
    Fa* bal = nullptr;
    Fa* jobb = nullptr;
};

struct BinarisFa {
    Fa* gyoker = nullptr;

    Fa* Letrehoz(const int &n, const vector<int> &data) {
        if (n > 0) {
            int nb = n / 2;
            int nj = n - nb - 1;

            auto *gy = new Fa;
            gy->info = data[data.size() - n];
            gy->bal = Letrehoz(nb, data);
            gy->jobb = Letrehoz(nj, data);

            if (n == data.size()) {
                this->gyoker = gy;
            }

            return gy;
        }

        return nullptr;
    }

    void pre(Fa* gy, const int &szint) {
        if (gy) {
            for (int i = 1; i <= szint; ++i) {
                cout << "   ";
            }
            cout << gy->info << '\n';

            this->pre(gy->bal, szint + 1);
            this->pre(gy->jobb, szint + 1);
        }
    }

    void Preorder() {
        this->pre(this->gyoker, 0);
    }

    void post(Fa* gy, const int &szint) {
        if (gy) {
            this->post(gy->bal, szint + 1);
            this->post(gy->jobb, szint + 1);

            for (int i = 1; i <= szint; ++i) {
                cout << "   ";
            }
            cout << gy->info << '\n';
        }
    }

    void Postorder() {
        this->post(this->gyoker, 0);
    }

    void in(Fa* gy, const int &szint) {
        if (gy) {
            this->in(gy->bal, szint + 1);

            for (int i = 1; i <= szint; ++i) {
                cout << "   ";
            }
            cout << gy->info << '\n';

            this->in(gy->jobb, szint + 1);
        }
    }

    void Inorder() {
        this->in(this->gyoker, 0);
    }

    bool Ures() {
        return this->gyoker == nullptr;
    }

    void szintek(Fa* gy, int &m) {
        if (gy) {
            ++m;
            this->szintek(gy->bal, m);
        }
    }

    int Magassag() {
        int m = 0;

        this->szintek(this->gyoker, m);

        return m;
    }
};

#endif //TETELEK_BINARISFA_H
