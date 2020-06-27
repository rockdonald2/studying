#include <stdio.h>
#include <string.h>

void romaiSzam(int sz) {
  char romai_arr[11][3] = {
    "M", "D", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
  };
  int szam_arr[11] = {
    1000, 500, 100, 90, 50, 40, 10, 9, 5, 4, 1
  };

  for (int i = 0; i < 11 && sz != 0;) {
    if ((sz / szam_arr[i]) != 0) {
      printf("%s", romai_arr[i]);
      sz -= szam_arr[i];
    } else {
      i++;
    }
  }
}

int main() {
  int szam;
  printf("Ird be a szamot, amelyet romai szamma alakitanal: ");
  scanf("%d", &szam);
  romaiSzam(szam);

  return 0;
}
