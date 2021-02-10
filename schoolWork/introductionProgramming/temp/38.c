#include <stdio.h>
#include <stdlib.h>

void algor(int *arr, int n) {
    int poz = 0, nul = 0, neg = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) neg++;
        else if (arr[i] == 0) nul++;
        else poz++;
    }

    printf("A beadott tombben %d pozitiv, %d nulla, es %d negativ.", poz, nul, neg);
}

int main() {
    int n;
    printf("Add meg hany szamot szeretnel beolvasni: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Add meg az %d erteket: ", i + 1);
        scanf("%d", &arr[i]);
    }

    algor(arr, n);

    return 0;
}