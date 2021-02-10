#include <iostream>
#include <fstream>

using ull = unsigned long long;

bool palindrom(const int &n);
void megfordit(const int &n, int &e);

int main() {
    std::ifstream be_all("../be_2.txt");

    int n = 0;
    if (be_all.is_open()) {
        be_all >> n;
    } else {
        std::cout << "Nem sikerult a bemeneti allomany beolvasasa.\n";
    }

    be_all.close();

    std::ofstream ki_all("../ki_2.txt");

    if (ki_all.is_open()) {
        ki_all << (palindrom(n) ? "palindrom" : "nem palindrom");
    } else {
        std::cout << "Nem sikerult a kimeneti allomany beolvasasa.\n";
    }

    ki_all.close();

    return 0;
}

bool palindrom(const int &n) {
    int eredmeny = 0;

    megfordit(n, eredmeny);

    return eredmeny == n;
}


void megfordit(const int &n, int &e) {
    if (n == 0) return;

    int x = n % 10;

    e = e * 10 + x;
    megfordit(n / 10, e);
}
