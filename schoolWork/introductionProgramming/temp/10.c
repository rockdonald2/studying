#include <stdio.h>

void relacio(double a, double b) {
  char r = '=';

  if (a > b) r = '>';
  else if (a == b) r = '=';
  else r = '<';

  char buff[32];
  snprintf(buff, 32, "%.1lf %c %.1lf", a, r, b);
  printf("%s", buff);
}

int main() {
  printf("Gepelj be ket szamot, amelyek kozott a relaciot szeretned megvizsgaltatni: ");
  double a, b;
  scanf("%lf %lf", &a, &b);
  relacio(a, b);

  return 0;
}
