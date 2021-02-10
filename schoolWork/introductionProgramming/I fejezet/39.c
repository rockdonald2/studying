#include <stdio.h>
#include <stdlib.h>

void algor(int *arr, int n) {
    int minPoz = arr[0], maxNeg = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < 0) {
            if (arr[i] > maxNeg) maxNeg = arr[i];
            else if (maxNeg > 0) maxNeg = arr[i];
        } else if (arr[i] > 0) {
            if (arr[i] < minPoz) minPoz = arr[i];
            else if (minPoz < 0) minPoz = arr[i]; 
        }
    }

    printf("A megadott tombben a pozitivak kozul a legkisebb a %d, es a negativak kozul a legnagyobb %d.", minPoz, maxNeg);
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