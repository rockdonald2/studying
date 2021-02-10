#include <iostream>

using namespace std;

void fordit();

int main() {
    fordit();

    return 0;
}

void fordit() {
    char betu;
    scanf("%c", &betu);

    if (betu != ' ') {
        fordit();
    } else {
        cout << "Forditott szo:";
    }

    cout << betu;
}