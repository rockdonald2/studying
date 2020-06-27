#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool megegyezik(int szam) {
    if (szam < 0) return false;

    int temp = szam;
    int tukorkep = 0;

    const int iterator = 10;
    int maradek = 0;
    while (temp > 0) {
        maradek = temp % 10;
        temp /= 10;
        tukorkep *= iterator;
        tukorkep += maradek;
    }

    return (tukorkep == szam);
}

int main() {
    printf("Adj megy egy tetszoleges egesz szamot: ");
    int szam;
    scanf("%d", &szam);

    if (megegyezik(szam)) {
        printf("A szam megegyezik a tukorkepevel.\n");
    } else {
        printf("A szam nem egyezik meg a tukorkepevel.\n");
    }

    return 0;
}
