#include <stdio.h>
#include <stdlib.h>

void csere(int *a, int *b) {
  int temp = *a;
  a = b;
  b = a;
}

int lnko(int a, int b) {
  int r;

  while (r != 0) {
    if (a < b) csere(&a, &b);

    r = a % b;
    a = b;
    b = r;
  }

  return a;
}

int lkkt(int a, int b) {
  return (a * b) / lnko(a, b);
}

int main() {
  int a, b;
  printf("Adj meg ket tetszoleges termeszetes szamot: ");
  scanf("%d %d", &a, &b);

  printf("lkkt[%d, %d] = %d", a, b, lkkt(a, b));

  return 0;
}
