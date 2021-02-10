#include <iostream>
#include <fstream>
#include <cmath>

using ull = unsigned long long;

void koltoztesd(const int &n, std::ofstream &ki);

int main() {
    std::ifstream be_all("../be_3.txt");

    int n = 0;
    if (be_all.is_open()) {
        be_all >> n;
    } else {
        std::cout << "Nem sikerult a bemeneti allomany beolvasasa.\n";
    }

    be_all.close();

    std::ofstream ki_all("../ki_3.txt");

    if (!ki_all.is_open()) {
        std::cout << "Nem sikerult a kimeneti allomany beolvasasa.\n";
    }

    koltoztesd(n, ki_all);

    ki_all.close();

    return 0;
}

void koltoztesd(const int &n, std::ofstream &ki) {
    int szamjegyek_szama = 0;
    int seged = n;

    while (seged) {
        szamjegyek_szama++;
        seged /= 10;
    }

    int id = (n / pow(10, szamjegyek_szama - 1)) + (n % (int)floor(pow(10, szamjegyek_szama - 1))) * 10;
    while (id != n) {
        ki << id << '\n';
        id = (id / pow(10, szamjegyek_szama - 1)) + (id % (int)floor(pow(10, szamjegyek_szama - 1))) * 10;
    }
    ki << n;
}