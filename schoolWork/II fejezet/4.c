#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Megoldas {
  int pozitiv;
  int negativ;
} Megoldas;

int main() {
  int value, valsRead;
  Megoldas m = { .pozitiv = 0, .negativ = 0 };
  char beolvasott[100], *ertek;
  char delim[] = " \t\r\n";

  // beolvassuk az ertekeket, stringkent, az stdinbol, ha CTRL+D nyomva EOF jelez, akkor errort irunk ki
  if (fgets(beolvasott, 100, stdin) == NULL) {
    fprintf(stderr, "Nem volt beolvasott ertek.\n");
    return -1;
  }

  // megkeressuk, hogy tartalmaz-e newline-t a string, ha nem error, a newlinenal jelezzuk a string veget
  if (beolvasott[strcspn(beolvasott, "\r\n")] == 0) {
    fprintf(stderr, "Tul hosszu volt a beolvasott ertek.\n");
    return -2;
  }

  // felosztjuk a stringet a delimiter szerint tokenekre.
  ertek = strtok(beolvasott, delim);
  valsRead = sscanf(ertek, "%d", &value);

  while (valsRead > 0) {
    if (value > 0) m.pozitiv += value;
    else m.negativ += value;

    printf("Beolvasott ertek: %d\n", value);
    // a NULL scan azt jelenti, hogy az erteket tekintjuk alapnak
    // alapjan ugy dolgozik, hogy megkeresi az elso karaktert, amelyet nem tartalmaz a delim, es az lesz az elso token, ha elerjuk a string veget, akkor vegig null pointert fog teriteni
    ertek = strtok(NULL, delim);
    valsRead = (ertek == NULL) ? 0 : sscanf(ertek, "%d", &value);
  }

  printf("A pozitiv szamok osszege %d, es a negativ szamok osszege %d.\n", m.pozitiv, m.negativ);

  return 0;
}
