#include <iostream>
#include "verem.h"

using namespace std;

bool Zarojelek(const string& z);

int main() {
    string z;
    cin >> z;

    Zarojelek(z) ? cout << "valid\n" : cout << "nem valid\n";

    return 0;
}

bool Zarojelek(const string& z) {
    auto *v = new Verem;

    for (const auto &e : z) {
        if (e == '(') {
            v->Beilleszt(e);
        } else if (e == ')') {
            if (!v->Ures() && v->Lemasol()->info == '(') {
                v->Torol();
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    return v->Ures();
}