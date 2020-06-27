#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Add meg az n erteket: ");
  int n;
  scanf("%d", &n);

  int arr[n];

  int sz = 3;
  size_t it = 0;
  while(it < n) {
    arr[it++] = sz;
    sz += 3;
  }

  printf("Az elso %d 3-mal oszthato szamok sorozata: ", n);
  for (int i = 0; i < it; ++i) {
    printf("%d ", arr[i]);
  }

  return 0;
}
