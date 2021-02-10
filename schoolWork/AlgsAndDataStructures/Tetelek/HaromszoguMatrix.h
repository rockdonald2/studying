#ifndef TETELEK_HAROMSZOGUMATRIX_H
#define TETELEK_HAROMSZOGUMATRIX_H

#include <iostream>
#include <vector>

using namespace std;

typedef int ElemTipus;

struct HaromszoguMatrix {
    vector<int> _elemek;
    int _n = 0;

    explicit HaromszoguMatrix(const vector<vector<int>> &bemenet) {
        // létrehoz egy háromszögű matrixot, egy 2x2-es bemeneti tömbből

        for (const auto &sorok : bemenet) {
            this->_n++;
            for (const auto &elem : sorok) {
                if (elem != 0) {
                    this->_elemek.push_back(elem);
                }
            }
        }
    }

    ElemTipus& operator()(const size_t i, const size_t j) {
        return this->_elemek[(i * (i - 1)) / 2 + j - 1];
    }

    friend ostream& operator<<(ostream &out, const HaromszoguMatrix &m) {
        // kiírja a háromszögű matrixot a megfelelő indentálással
        int k = 0;
        for (int i = 1; i <= m._n; ++i) {
            for (int j = 0; j < i; ++j) {
                out << m._elemek[k++] << ' ';
            }

            out << '\n';
        }

        return out;
    }
};

#endif //TETELEK_HAROMSZOGUMATRIX_H
