#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

long unsigned int atalakit2(char* string) {
  int szam = 0;

  for (int i = 0; i < strlen(string); ++i) {
    szam += (((int)string[i] - 48) * pow(2, strlen(string) - 1 - i));
  }

  return szam;
}

long unsigned int atalakit16(char* string) {
  int szam = 0;

  for (int i = strlen(string) - 1; i >= 0; --i) {
    char ch = tolower(string[i]);
    int mult = 0;

    switch(ch) {
      case 'a': mult = 10; break;
      case 'b': mult = 11; break;
      case 'c': mult = 12; break;
      case 'd': mult = 13; break;
      case 'e': mult = 14; break;
      case 'f': mult = 15; break;
      default: mult = (int)ch - 48; break;
    }

    szam += (mult * pow(16, strlen(string) - 1 - i));
  }

  return szam;
}

int main() {
  printf("Adj meg egy szamot 2-es szamrendszerben: 0b");
  char string[10000];
  scanf("%s", string);

  printf("Decimalis formaban: %d", atalakit2(string));

  return 0;
}
