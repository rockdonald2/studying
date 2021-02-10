#include <iostream>

using namespace std;

// ef - első fele
// mf - második fele
bool Palindrom(int ef, int mf);

int main() {
    if (Palindrom(12321, 0)) {
        cout << "Palindrom\n";
    } else {
        cout << "Nem palindrom\n";
    }

    return 0;
}

bool Palindrom(int ef, int mf) {
    // amennyiben az első fele kisebb, mint a második, nem lehet palindrom
    if (mf > ef) {
        return false;
    } else {
        // levágjuk az első felének utolsó számjegyét és hozzáadjuk a másodikhoz
        mf = mf * 10 + ef % 10;

        // ha a kettő megegyezik, akkor már palindromhoz értünk
        if (ef == mf) {
            return true;
        } else {
            // ha a kettő nem egyezik meg, levágjuk az első felének utolsó számjegyét
            // ez már hozzá van adva a másodikhoz
            ef = ef / 10;

            // ha a kettő megegyezik, akkor palindrom
            if (ef == mf) {
                return true;
            } else {
                // ha nem, lehívjuk újra
                return Palindrom(ef, mf);
            }
        }
    }
}