#include <iostream>
#include <vector>

using namespace std;

void radix_rendezes(vector<int> &a);
void leszamlalo_rendezes(vector<int> &a, const int &exp);

int main() {
    vector<int> a{7, 11, 2, 5};

    radix_rendezes(a);

    for (const auto &e : a) {
        cout << e << ' ';
    }

    return 0;
}

void radix_rendezes(vector<int> &a) {
    int max = *(max_element(a.begin(), a.end()));

    for (int i = 1; (max / i) > 0; i *= 10) {
        leszamlalo_rendezes(a, i);
    }
}

void leszamlalo_rendezes(vector<int> &a, const int &exp) {
    vector<int> szamlalo(10, 0);
    vector<int> kimenet(a.size());

    for (const auto &e : a) {
        szamlalo[(e / exp) % 10]++;
    }

    for (int i = 1; i < szamlalo.size(); ++i) {
        szamlalo[i] += szamlalo[i - 1];
    }

    for (int j = a.size() - 1; j >= 0; --j) {
        kimenet[szamlalo[(a[j] / exp) % 10] - 1] = a[j];
        szamlalo[(a[j] / exp) % 10]--;
    }

    for (int i = 0; i < a.size(); ++i) {
        a[i] = kimenet[i];
    }
}