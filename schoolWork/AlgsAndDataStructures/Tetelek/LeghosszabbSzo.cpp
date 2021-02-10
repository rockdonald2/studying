#include <iostream>
#include <string>

using namespace std;

int lengthOfLongestWord(string s) {
    int currLength{ 0 };
    int maxLength{ 0 };

    for (const auto &e : s) {
        if (e != ' ') {
            currLength++;
        } else {
            if (currLength > maxLength) {
                maxLength = currLength;
            }

            currLength = 0;
        }
    }

    if (currLength > maxLength) {
        maxLength = currLength;
    }

    return maxLength;
}

int main() {
    string str{"This is one long sentence to count"};

    cout << lengthOfLongestWord(str) << '\n';

    return 0;
}