#include <stdio.h>
#include <stdlib.h>

long unsigned int atalakit2(long unsigned int szam) {
    long unsigned int atalakitott = 0;

    int maradek;
    int iterator = 1;
    while (szam > 0) {
        maradek = szam % 2;
        szam /= 2;

        atalakitott += maradek * iterator;
        iterator *= 10;
    }

    return atalakitott;
}

int main() {
    printf("Adj megy tetszoleges termeszetes szamot: ");
    long unsigned int szam;
    scanf("%lu", &szam);

    printf("Az altalad megadott szam(%lu) 2-es szamrendszerbeli alakja: 0b%lu", szam, atalakit2(szam));

    return 0;
}
