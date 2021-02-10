#include <iostream>

using namespace std;

int Gyors_Hatvany(const int &a, const int &k);

int main() {
    cout << Gyors_Hatvany(3, 4);

    return 0;
}

int Gyors_Hatvany(const int &a, const int &k) {
    if (k == 1) {
        return a;
    } else {
        int x = Gyors_Hatvany(a, k / 2);

        if (k % 2) {
            return x * x * a;
        } else {
            return x * x;
        }
    }
}

/*

a = 2
k = 5   x = 4; mivel k % 2 == 1 => return 4 * 4 * 2

a = 2
k = 2   x = 2; mivel k % 2 == 0 => return 2 * 2

a = 2
k = 1   return 2

*/

/*

a = 2
k = 10  x = 4 * 4 * 2; mivel k % 2 == 0 => return 4 * 4 * 2 * 4 * 4 * 2 = 2^2 * 2^2 * 2^2 * 2^2 * 2^2 = 2^10

a = 2
k = 5   x = 4; mivel k % 2 == 1 => return 4 * 4 * 2

a = 2
k = 2   x = 2; mivel k % 2 == 0 => return 2 * 2

a = 2
k = 1   return 2

*/