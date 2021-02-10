#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double a, b;
    printf("Adj meg ket egesz szamot: ");
    scanf("%lf %lf", &a, &b);

    if (abs(a - b) <= 10) {
        printf("Mivel %.4lf es %.4lf kulonbsege nem tobb 10nel, ezert a szorzatuk: %.4lf", a, b, a * b);
    } else {
        a > b ? printf("Mivel %.4lf es %.4lf kulonbsege tobb 10nel, ezert a kisebb es nagyobb szam hanyadosa: %.4lf", a, b, b - a) : printf("Mivel %.4lf es %.4lf kulonbsege tobb 10nel, ezert a kisebb es nagyobb szam hanyadosa: %.4lf", a, b, a - b);
    }

    return 0;
}