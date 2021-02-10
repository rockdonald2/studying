#include <iostream>

using namespace std;

int Szorzat(const int &bal, const int &jobb);

int main() {
    cout << Szorzat(1, 5);

    return 0;
}

int Szorzat(const int &bal, const int &jobb) {
    switch(jobb - bal) {
        case 0: return bal;
        case 1: return bal * jobb;
        default: {
            int kozep = (bal + jobb) / 2;
            int p1 = Szorzat(bal, kozep);
            int p2 = Szorzat(kozep + 1, jobb);
            return p1 * p2;
        }
    }
}