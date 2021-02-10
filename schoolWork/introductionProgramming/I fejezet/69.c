#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int a(int n) {
  int szam = 0;

  for (int i = 0; i <= n; ++i) {
    szam += (2 * i);
  }

  return szam;
}

int b(int n) {
  int szam = 0;

  for (int i = 1; i <= n; ++i) {
    szam += (i * i * i);
  }

  return szam;
}

int c(int n) {
  int szam = 0;

  for (int i = 1; i <= n; ++i) {
    szam += (pow(-1, i + 1) * i);
  }

  return szam;
}

double d(int n) {
  double szam = 0;

  for (int i = 1; i <= n; ++i) {
    int szamlalo = 0;
    int nevezo = 1;

    for (int j = 1; j <= i; ++j) {
      szamlalo += j;
      nevezo *= j;
    }

    szam += ((double)szamlalo / (double)nevezo);
  }

  return szam;
}

int main() {
  int n;
  printf("Add meg a tetszoleges n erteket: ");
  scanf("%d", &n);

  printf("Az a) pont megoldas: %d\n", a(n));
  printf("A b) pont megoldasa: %d\n", b(n));
  printf("A c) pont megoldasa: %d\n", c(n));
  printf("A d) pont megoldasa: %.2lf", d(n));

  return 0;
}
