#include <stdio.h>

int abszolutertek(int szam) {
  return (szam > 0) ? szam : -szam;
}

int main() {
  printf("Gepelj be valamilyen egesz szamot, akar negativ is lehet: ");
  int x;
  scanf("%d", &x);
  printf("Az altalad begepelt szam abszoluterteke: %d", abszolutertek(x));

  return 0;
}
