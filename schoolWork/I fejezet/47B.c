#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* atalakit2(long unsigned int szam) {
  size_t hossz = 32;
  char* string = (char*)malloc(hossz * sizeof(char));
  char maradek;

  if (string == NULL) {
    fprintf(stderr, "Nincs elegendo hely a memoriaban a string letrehozasahoz.\n");
    return "-1";
  }

  size_t iterator = 0;
  char* temp;

  while (szam > 0) {
    int r = szam % 2;
    szam /= 2;
    maradek = r + '0';
    ++iterator;

    if (iterator == hossz) {
      temp = string;
      hossz *= 2;

      string = (char*)realloc(string, hossz * sizeof(char));

      if (string == NULL) {
        fprintf(stderr, "Nincs elegendo hely a memoriaba a boviteshez.\n");
        string = temp;
        break;
      }
    }

    strncat(string, &maradek, 1);
  }

  for (int i = 0, j = strlen(string) - 1; i < strlen(string) / 2; ++i, --j) {
    char temp = string[i];
    string[i] = string[j];
    string[j] = temp;
  }

  return string;
}

char* atalakit16(long unsigned int szam) {
  size_t hossz = 32;
  char* string = (char*)malloc(hossz * sizeof(char));
  char maradek;

  if (string == NULL) {
    fprintf(stderr, "Nincs elegendo hely a memoriaban a string letrehozasahoz.\n");
    return "-1";
  }

  size_t iterator = 0;
  char* temp;

  while (szam > 0) {
    int r = szam % 16;
    szam /= 16;
    ++iterator;

    switch(r) {
      case 10: maradek = 'A'; break;
      case 11: maradek = 'B'; break;
      case 12: maradek = 'C'; break;
      case 13: maradek = 'D'; break;
      case 14: maradek = 'E'; break;
      case 15: maradek = 'F'; break;
      default: maradek = r + '0'; break;
    }

    if (iterator == hossz) {
      temp = string;
      hossz *= 2;

      string = (char*)realloc(string, hossz * sizeof(char));

      if (string == NULL) {
        fprintf(stderr, "Nincs elegendo hely a memoriaba a boviteshez.\n");
        string = temp;
        break;
      }
    }

    strncat(string, &maradek, 1);
  }

  for (int i = 0, j = strlen(string) - 1; i < strlen(string) / 2; ++i, --j) {
    char temp = string[i];
    string[i] = string[j];
    string[j] = temp;
  }

  return string;
}

int main() {
  printf("Adj megy egy termeszetes szamot, amelyet 16-os szamrendszerbe alakitanal: ");
  long unsigned int szam;
  scanf("%lu", &szam);

  printf("A szam (%lu) 16-os szamrendszerben: 0x%s", szam, atalakit16(szam));

  return 0;
}
