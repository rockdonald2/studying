#include <stdio.h>

const char* hetnapja(int x) {
  switch (x) {
      case 1: return "hetfo";
      case 2: return "kedd";
      case 3: return "szerda";
      case 4: return "csutortok";
      case 5: return "pentek";
      case 6: return "szombat";
      case 7: return "vasarnap";
      default: return "(A megadott szam nem a [1, 7] intervallumban van)";
    }
}

int main() {
  int szam;
  do {
    printf("Add meg hanyadik napja van a hetnek: ");
    scanf("%d", &szam);
  } while(szam <= 0 || szam >= 8);

  printf("Ma %s van.", hetnapja(szam));

  return 0;
}
