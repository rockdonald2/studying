#include <iostream>
#include <vector>
#include <string>

void Talak(std::vector<std::string> &sorozat, const int &n, const int &i, const int &bfal, const int &jfal, const
int &alj);

int main() {
    int n = 3;
    std::cin >> n;

    std::vector<std::string> s(2 * n + 1, " ");
    s[1] = "\\";
    s[2 * n] = "/";

    Talak(s, n, 2, 1, 0, 0);

    return 0;
}

void Talak(std::vector<std::string> &sorozat, const int &n, const int &i, const int &bfal, const int &jfal, const
int &alj) {
    if (i == (2 * n)) {
        for (const auto &e : sorozat) {
            std::cout << e;
        }

        std::cout << '\n';
    } else {
        if (bfal < n) {
            sorozat[i] = "\\";
            Talak(sorozat, n, i + 1, bfal + 1, jfal, alj);
        }

        if (jfal < bfal) {
            sorozat[i] = "/";
            Talak(sorozat, n, i + 1, bfal, jfal + 1, alj);
        }
    }
}