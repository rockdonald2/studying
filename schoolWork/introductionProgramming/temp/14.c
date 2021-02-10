#include <stdio.h>

int polinom(int a, int b) {
  return b / a;
}

int main() {
  int a, b;
  printf("Add meg az ax = b alapu polinom a es b egyutthatoinak termeszetes erteket: ");
  scanf("%d %d", &a, &b);
  printf("Az egyenlet megoldasa x-re tekintettel = %d", polinom(a, b));

  return 0;
}
