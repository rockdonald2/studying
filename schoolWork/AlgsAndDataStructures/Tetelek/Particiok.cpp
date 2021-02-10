#include <iostream>
#include <vector>

using namespace std;

void particiok(const int &i, const int &n);
void kiir(const int &i);

const int g = 4;
static vector<int> p(g, 0);

int main() {
    particiok(1, g);

    return 0;
}

void particiok(const int &i, const int &n) {
    for (int j = 1; j <= n; ++j) {
        p[i] = j;

        if (j < n) {
            particiok(i + 1, n - j);
        } else {
            kiir(i);
        }
    }
}


void kiir(const int &i) {
    cout << "{ " << p[1];

    for (int j = 2; j <= i; ++j) {
        cout << ", " << p[j];
    }

    cout << " }\n";
}