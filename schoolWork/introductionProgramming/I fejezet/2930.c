#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    printf("Add meg az eredeti osszeget: ");
    int p;
    scanf("%d", &p);

    printf("Add meg a lekotesi idot evekben: ");
    int n;
    scanf("%d", &n);

    printf("Vegul, add meg a kamatlab merteket szazalekban: ");
    double k;
    scanf("%lf", &k);

    char dontes;
    while (dontes != 'e' && dontes != 'k') {
        printf("Egyszeru(e) vagy kamatos kamat(k) szamitast hasznaljunk? ");
        scanf("%*c%c", &dontes);
    }

    if (dontes == 'e') {
        p *= pow((1 + k / 100), n);
    } else if (dontes == 'k') {
        p = p + p * (pow((1 + k / 100), n) - 1);
    }

    printf("\nAz %d ev vegen a lekotott osszeg %d nott.", n, p);

    return 0;
}
