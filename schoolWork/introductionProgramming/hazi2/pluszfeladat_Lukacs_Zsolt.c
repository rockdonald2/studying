#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/* 

Compile terminálból:
    gcc feladat.c -o feladat.out -lm

*/

void uresit() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

bool primszam(const int *n) {
    if (*n <= 1) return false;

    for (int i = 2; i < (int)sqrt(*n); ++i) {
        if ((*n % i) == 0) return false;
    }

    return true;
}

int abszolut(int szam) {
    if (szam > 0) return szam;
    else return -szam;
}

void feladatok(int n) {
    switch(n) {
        case 1: {
            printf("Irj be egy karaktert: ");
            fflush(stdout);
            char karakter;
            scanf("%c", &karakter);
            uresit();

            if (karakter >= 'a' && karakter <= 'z') printf("Az altalad megadott %c karakter kisbetu.\n", karakter);
            else if (karakter >= 'A' && karakter <= 'Z') printf("Az altalad megadott %c karakter nagybetu.\n", karakter);
            else if (karakter >= '0' && karakter <= '9') printf("Az altalad megadott %c karakter szam.\n", karakter);
            else printf("Az altalad megadott %c karakter egyeb karakter.\n", karakter);

            break;
        }
        case 2: {
            printf("Adj meg egy szamot: ");
            fflush(stdout);
            int szam;
            scanf("%d", &szam);

            primszam(&szam) ? printf("Az altalad megadott %d primszam.\n", szam) : printf("Az altalad megadott %d nem primszam.\n", szam);

            break;
        }
        case 3: {
            printf("Adj megy egy szamot: ");
            fflush(stdout);
            int szam;
            scanf("%d", &szam);

            printf("Az altalad megadott %d szam abszolut erteke %d.\n", szam, abszolut(szam));

            break;
        }
    }
}

int main() {
    // 1. feladat
    feladatok(1);
    printf("\n");

    // 2. feladat
    feladatok(2);
    printf("\n");

    // 3. feladat
    feladatok(3);

    return 0;
}
