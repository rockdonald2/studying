#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// egy szam akkor es csakis akkor fibonacci, ha teljesul a kovetkezo
// 5*n^2 + 4 vagy 5*n^2 - 4 teljes negyzet

bool teljesNegyzet(int n) {
    if (n == 0) return true;

    int bal = 1, jobb = n - 1, kozep;

    while (bal <= jobb) {
        kozep = bal + (jobb - bal) / 2;

        if (kozep <= n / kozep && (kozep + 1) > n / (kozep + 1)) break;
        else if (kozep < n / kozep) bal = kozep + 1;
        else jobb = kozep - 1;
    }

    return (kozep * kozep) == n;
}

bool fibonacci(int n) {
    return teljesNegyzet(5 * n * n + 4) || teljesNegyzet(5 * n * n - 4);
}

int main() {
    printf("Adj meg egy tetszoleges termeszetes szamot: ");
    int n;
    scanf("%d", &n);

    if (fibonacci(n)) {
        printf("Az altalad megadott szam (%d) fibonacci szam.", n);
    } else {
        printf("Az altalad megadott szam (%d) nem fibonacci szam.", n);
    }

    return 0;
}