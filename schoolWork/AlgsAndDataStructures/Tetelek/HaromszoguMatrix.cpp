#include <iostream>
#include <vector>
#include "HaromszoguMatrix.h"

using namespace std;

int main() {
    vector<vector<int>> tmp {{1, 0, 0, 0},
                     {2, 3, 0, 0},
                     {4, 5, 6, 0},
                     {7, 8, 9, 10}};

    auto m = HaromszoguMatrix(tmp);

    cout << m;

    return 0;
}