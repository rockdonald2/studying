#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
  double x;
  double ossz = 0;
  int n = 0;
  printf("Adj meg egy szamsorozatot szokozokkel elvalasztva, es 0-val jelezd a veget: ");

  while (true) {
    scanf("%lf", &x);

    if (x == 0.0) break;

    if ((int)x % 2 == 0) {
      ossz += x;
      ++n;
    }
  }

  printf("A megadott paros szamok osszege %.3lf, es szamtani kozeparanyosa %.3lf.", ossz, ossz / n);

  return 0;
}
