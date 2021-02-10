#include <stdio.h>
#include <stdlib.h>

unsigned long long fakt(int n) {
  if (n <= 1) return 1;
  else return n * fakt(n - 1);
}

int main() {
  int n;
  printf("Adj meg egy termeszetes szamot: ");
  scanf("%d", &n);
  printf("%d! = %llu", n, fakt(n));

  return 0;
}
