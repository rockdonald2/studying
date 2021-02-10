#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool pithagorasz(int x, int y, int z) {
  if (x == sqrt(y + z)) return true;
  else if (y == sqrt(x + z)) return true;
  else if (z == sqrt(x + y)) return true;
  else return false;
}

int main() {
  printf("Adj meg egy szamharmast (szokozokkel elvalasztva): ");
  int x, y, z;
  scanf("%d %d %d", &x, &y, &z);

  if (pithagorasz(x, y, z)) {
    printf("Az altalad megadott szamharmas (%d %d %d), pithagoraszi szamharmas.", x, y, z);
  } else {
    printf("Az altalad megadott szamharmas (%d %d %d), nem pithagoraszi szamharmas.", x, y, z);
  }

  return 0;
}
