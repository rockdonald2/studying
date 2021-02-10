#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool szokoev(int *evszam) {
    if (*evszam % 400 == 0) return true;
    else if (*evszam % 100 == 0) return false;
    else if (*evszam % 4 == 0) return true;
    else return false;
}

int szokoevek(int elsoevszam, int masodikevszam) {
    int szamlalo = 0;

    while (elsoevszam <= masodikevszam) {
        if (szokoev(&elsoevszam)) szamlalo++;

        elsoevszam++;
    }

    return szamlalo;
}

int main()
{
    printf("Adj meg ket evszamot, amelyek kozott megnezned hany szokoev van/volt: ");
    int elsoevszam, masodikevszam;
    scanf("%d %d", &elsoevszam, &masodikevszam);

    printf("%d es %d kozott %d szokoev volt.", elsoevszam, masodikevszam, szokoevek(elsoevszam, masodikevszam));

    return 0;
}
