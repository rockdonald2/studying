#include <stdio.h>
#include <stdbool.h>

bool oszto(double a, double b) {
  return (int)a % (int)b == 0;
}

int main() {
  double a, b;
  printf("Adj meg ket termeszetes szamot: ");
  scanf("%lf %lf", &a, &b);

  if (oszto(a, b)) {
    printf("Az %.1lf osztoja a %.1lf-nek", b, a);
  } else {
    printf("Az %.1lf nem osztoja a %.1lf -nek", b, a);
  }

  return 0;
}
