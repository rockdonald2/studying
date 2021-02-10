#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool kettoHatvanya(int x) {
    return ((x - 1) & x) == 0;
}

int main() {
    printf("Adj meg egy tetszoleges szamot: ");
    int n;
    scanf("%d", &n);

    if (kettoHatvanya(n)) {
        printf("Az altalad megadott szam %d, a 2 hatvanya.", n);
    } else {
        printf("Az altalad megadott szam %d, nem 2 hatvanya.", n);
    }

    return 0;
}
