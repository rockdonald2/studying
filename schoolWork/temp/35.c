#include <stdio.h>
#include <stdlib.h>

int szamjegyek(int n) {
    int szj = 0;

    while (n != 0) {
        szj++;
        n /= 10;
    }

    return szj;
}

int main() {
    printf("Adj meg egy tetszoleges szamot: ");
    int n;
    scanf("%d", &n);
    printf("%d szamjegyeinek szama: %d", n, szamjegyek(n));

    return 0;
}
