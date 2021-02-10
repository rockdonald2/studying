#include <stdio.h>
#include <stdlib.h>

double parosParatlan(int *arr, int n) {
    int sz = 0;

    for (int i = 0; i < n; i++) {
        if ((arr[i] % 2) == 0) sz++;
    }

    return ((double)sz / (double)n) * 100;
}

int main() {
    printf("Hany szamot akarsz beolvasni: ");
    int n;
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Add meg az %d. erteket: ", i + 1);
        scanf("%d", &arr[i]);
    }

    double szazalek = parosParatlan(arr, n);
    printf("A sor szamainak mintegy %.0lf%%-a paros, es %.0lf%%-a paratlan.", szazalek, 100 - szazalek);

    return 0;
}
