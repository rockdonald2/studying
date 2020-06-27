#include <stdio.h>
#include <math.h>

int utolsoszamjegy(int x) {
  if (x == 0) return 1;
  else if (x == 1) return 2;
  else if (x % 4 == 0) return 6;
  else if (x % 2 == 0 && x % 4 != 0) return 4;
  else if (x % 4 == 1) return 2;
  else if (x % 4 == 3) return 8;
  else return -1;
}

int main() {
  printf("Adj meg egy tetszoleges x erteket (csakis termeszetes szam lehet): ");
  int x;
  scanf("%d", &x);
  printf("Az adott x ertek 2^x-re emelt hatvanyanak utolso szamjegye: %d", utolsoszamjegy(x));

  return 0;
}
