#include <iostream>

using namespace std;

struct Betusor {
    int n = 0;
    char str[80];

    void beolvasas() {
        cout << "n = ";
        cin >> n;

        for (int i = 0; i < n; ++i) {
            scanf("%c", &str[i]);
        }
    };

    void kiir() const {
        for (int i = 0; i < n; ++i) {
            cout << str[i];
        }
        cout << '\n';
    }

    bool ures() const {
        return n == 0;
    }

    bool tele() const {
        return n == 80;
    }

    void elso_szo() {
        if (!this->ures()) {
            int s = 0;
            while (str[s] != ' ' && s < n) {
                ++s;
            }

            for (int i = 0; i < s; ++i) {
                cout << str[i];
            }
            cout << '\n';

            int j = 0;
            s += 1;
            while (s < n) {
                str[j] = str[s];
                ++s;
                ++j;
            }

            n = j;
        } else {
            cout << "Ures a betusor\n";
        }
    }

    void utolso_szo() {
        if (!this->ures()) {
            int s = n - 1;
            while (str[s] != ' ' && s >= 0) {
                --s;
            }

            for (int i = s + 1; i < n; ++i) {
                cout << str[i];
            }
            cout << '\n';

            if (s == -1) {
                n = 0;
            } else {
                n = s;
            }
        } else {
            cout << "Ures a betusor\n";
        }
    }
};

int main() {
    Betusor bs;
    bs.beolvasas();
    bs.kiir();
    bs.elso_szo();
    bs.kiir();
    bs.utolso_szo();
    bs.kiir();

    return 0;
}