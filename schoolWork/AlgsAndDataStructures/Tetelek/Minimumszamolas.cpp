#include <iostream>
#include <vector>

using namespace std;

int Minimum(const vector<int> &x, const int &bal, const int &jobb);

int main() {
    cout << Minimum(vector<int>{5, 2, 1, 3, 4}, 0, 4);

    return 0;
}

int Minimum(const vector<int> &x, const int &bal, const int &jobb) {
    if ((jobb - bal) == 0) {
        return x[bal];
    } else if ((jobb - bal) == 1) {
        return x[bal] < x[jobb] ? x[bal] : x[jobb];
    } else {
        int min1 = Minimum(x, bal, (bal + jobb) / 2);
        int min2 = Minimum(x, (bal + jobb) / 2 + 1, jobb);
        return min1 < min2 ? min1 : min2;
    }
}