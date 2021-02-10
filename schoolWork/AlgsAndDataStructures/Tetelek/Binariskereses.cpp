#include <iostream>
#include <vector>

using namespace std;

int Binaris_Kereses(const vector<int> &x, const int &bal, const int &jobb, const int &keresett);

int main() {
    vector<int> a {1, 2, 3, 4, 5, 6};
    cout << Binaris_Kereses(a, 0, a.size() - 1, 6);

    return 0;
}

int Binaris_Kereses(const vector<int> &x, const int &bal, const int &jobb, const int &keresett) {
    if (bal > jobb) {
        return -1;
    } else {
        int kozep = bal + (jobb - bal) / 2;

        if (x[kozep] > keresett) {
            return Binaris_Kereses(x, bal, kozep - 1, keresett);
        } else {
            if (x[kozep] < keresett) {
                return Binaris_Kereses(x, kozep + 1, jobb, keresett);
            } else {
                return kozep;
            }
        }
    }
}