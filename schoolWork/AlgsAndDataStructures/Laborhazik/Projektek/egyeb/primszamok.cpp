#include <iostream>
#include <cmath>
#include <vector>

bool prim(int n);
bool prim_opt(int n);
std::vector<bool> general_erato(int n);

int main() {
    int n;
    std::cout << "n = ";
    std::cin >> n;

    const auto erato = general_erato(n);

    if (n > 1 && erato[n]) {
        std::cout << n << " primszam\n";
    } else {
        std::cout << n << " nem primszam\n";
    }

    return 0;
}

bool prim(int n) {
    bool prim_e = true;

    if (n == 1) {
        prim_e = false;
    } else if (!(n % 2)) {
        prim_e = n == 2;
    } else {
        // hagyományos megoldás, gyengén optimalizálva
        /*int i = 3;
        const double gyok = pow(n, 0.5);

        while (prim_e && i <= gyok) {
            if (!(n % i)) {
                prim_e = false;
            }

            i += 2;
        }*/

        // tételt alkalmazva, kissé optimalizálva
        if (n > 5) {
            if ((n - 1) % 6 != 0 && (n + 1) % 6 != 0) {
                prim_e = false;
            } else {
                int i = 3;
                const double gyok = pow(n, 0.5);

                while (prim_e && i <= gyok) {
                    if (!(n % i)) {
                        prim_e = false;
                    }

                    i += 2;
                }
            }
        }
    }

    return prim_e;
}

bool prim_opt(int n) {
    if (n <= 3) {
        return n > 1;
    } else if (!(n % 2) || !(n % 3)) {
        return false;
    }

    int i = 5;
    const double gyok = pow(n, 0.5);
    while (i <= gyok) {
        if (!(n % i) || !(n % (i + 2))) {
            return false;
        }

        i += 6;
    }

    return true;
}

std::vector<bool> general_erato(int n) {
    std::vector<bool> erato(n + 2, true);
    const int gyok = floor(pow(n, 0.5));

    for (int i = 2; i <= gyok; i++) {
        if (erato[i]) {
            const int negyzet = floor(pow(i, 2));

            for (int j = negyzet; j <= n; j += i) {
                erato[j] = false;
            }
        }
    }

    return erato;
}