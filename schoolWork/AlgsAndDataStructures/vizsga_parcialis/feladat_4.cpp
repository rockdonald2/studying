#include <iostream>
#include <fstream>
#include <string>

using ull = unsigned long long;

void atalakit_binaris(const int &n, std::string &str);
void binaris_szamok_ketto_kozott(const int &a, const int &b, const int &k, std::ofstream& ki);
int megszamol(const std::string &str);

int main() {
    std::ifstream be_all("../be_4.txt");

    int a = 0;
    int b = 0;
    int k = 0;
    if (be_all.is_open()) {
        be_all >> a >> b >> k;
    } else {
        std::cout << "Nem sikerult a bemeneti allomany beolvasasa.\n";
    }

    be_all.close();

    std::ofstream ki_all("../ki_4.txt");

    if (!ki_all.is_open()) {
        std::cout << "Nem sikerult a kimeneti allomany beolvasasa.\n";
    }

    binaris_szamok_ketto_kozott(a, b, k, ki_all);

    ki_all.close();

    return 0;
}

void atalakit_binaris(const int &n, std::string &str) {
    if (n == 1) {
        str += "1";
    } else {
        str += std::to_string(n % 2);
        atalakit_binaris(n / 2, str);
    }
}

int megszamol(const std::string &str) {
    int k = 0;

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == '1') {
            ++k;
        }
    }

    return k;
}

void binaris_szamok_ketto_kozott(const int &a, const int &b, const int &k, std::ofstream& ki) {
    std::string id;
    for (int i = a; i <= b; ++i) {
        id = "";
        atalakit_binaris(i, id);
        if (megszamol(id) == k) {
            ki << i << '\n';
        }
    }
}