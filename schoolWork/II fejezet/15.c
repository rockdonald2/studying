#include <stdio.h>
#include <stdlib.h>

int main() {
  size_t n;
  printf("Add meg az n erteket a kovetkezo osszefuggesbol (n x n): ");
  scanf("%lu", &n);

  int arr[n][n];

  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      arr[i][j] = i + j;
    }
  }

  for (size_t i = 0; i < n; ++i) {
    printf("[ ");
    for (size_t j = 0; j < n; ++j) {
      printf("%d ", arr[i][j]);
    }
    printf("]\n");
  }

  return 0;
}
