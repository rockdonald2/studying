#include <iostream>
#include <string>

using namespace std;

bool Palindrom(const string &s, const int &b, const int &j);

int main() {
    string str = "abba";

    if (Palindrom(str, 0, str.length() - 1)) {
        cout << "Palindrom\n";
    } else {
        cout << "Nem palindrom\n";
    }

    return 0;
}

bool Palindrom(const string &s, const int &b, const int &j) {
    if (b >= j) {
        return true;
    } else {
        if (s[b] != s[j]) {
            return false;
        }

        return Palindrom(s, b + 1, j - 1);
    }
}