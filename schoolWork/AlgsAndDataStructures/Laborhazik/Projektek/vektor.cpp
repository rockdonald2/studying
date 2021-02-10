#include <iostream>

using namespace std;

struct Vector {
    unsigned int hossz;
    int *tomb;

    void init(const int h, const int *t) {
        hossz = h;
        tomb = new int[hossz];

        for (int i = 0; i < h; ++i) {
            tomb[i] = t[i];
        }
    }

    void kiir() const {
        for (int i = 0; i < hossz; ++i) {
            cout << tomb[i] << ' ';
        }

        cout << '\n';
    }

    void torol() const {
        delete[] tomb;
    }
};

int main() {
    Vector v;
    int tomb[6] = {1, 2, 3, 4, 5, 6};

    v.init(6, tomb);
    v.kiir();
    v.torol();

    return 0;
}