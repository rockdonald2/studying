#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  printf("Add meg a tomb hosszat [1, 30]: ");
  scanf("%d", &n);
  int *arr = (int*)malloc(n * sizeof(int));

  if (arr == NULL) {
    fprintf(stderr, "Nincs elegendo memoria a tomb letrehozasahoz.\n");
    return -1;
  }

  if (n == 1) {
    printf("A megadott hossz nem alkothat szamtani sorozatot.\n");
    return -2;
  }

  for (int i = 0; i < n; ++i) {
    printf("Add meg (%d) elem erteket: ", i + 1);
    scanf("%d", &arr[i]);
  }

  if (n == 2) {
    printf("A megadott tomb szamtani sorozatot alkot.\n");
    return 0;
  }

  int d = (arr[1] - arr[0]);
  for (int j = 2; j < n; ++j) {
    if ((arr[j] - arr[j - 1]) != d) {
      printf("A megadott tomb nem alkot szamtani sorozatot.\n");
      return 0;
    }
  }

  printf("A megadott tomb szamtani sorozatot alkot.\n");
  return 0;
}
