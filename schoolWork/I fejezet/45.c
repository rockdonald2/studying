#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main() {
  char ch;
  int szamlalo = 0;
  printf("Adj meg egy karaktersorozatot, es *-al jelezd a veget: ");

  while (true) {
    scanf("%c", &ch);

    ch = tolower(ch);

    if (ch == '*') break;

    if (ch == 'a' || ch == 'e' || ch == 'u' || ch == 'i' || ch == 'o') {
      ++szamlalo;
    }
  }

  printf("Az altalad megadott karaktersorozatban %d maganhangzo volt.", szamlalo);

  return 0;
}
