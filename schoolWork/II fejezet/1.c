#include <stdio.h>
#include <stdlib.h>

typedef struct Pair {
    int index;
    double val;
} Pair;

int main() {
  size_t hossz = 16;
  double *arr = (double*)malloc(hossz * sizeof(double));

  if (arr == NULL) {
    printf("Nincs elegendo memoria a tomb letrehozasahoz.\n");
    return 1;
  }

  size_t i = 0;
  double *temp; // arra az esetre hozzuk letre, ha realloc lenne szukseges, mert atlepjek a hossz meretet

  printf("Adj meg egy szokozokkel elvalasztott, tetszoleges hosszusagu egesz szamszort, és a folytatashoz nyomj enter, majd CTRL+D-t.\n");
  while (scanf("%lf", arr + i) == 1) {
    ++i;
    if (i == hossz) { // a tomb megtelt, realloc szukseges
      temp = arr;
      hossz *= 2;
      arr = (double*)realloc(arr, hossz * sizeof(double));

      if (arr == NULL) {
        printf("Nincs elegendo memoria az ujraosztashoz.\n");
        arr = temp;
        break;
      }
    }
  }

  if (i == 0) {
    printf("Nem olvastunk be egy szamot sem.\n");
    return 1;
  }

  Pair min = { .index = 0, .val = arr[0] };
  Pair max = { .index = 0, .val = arr[0] };
  // linearis kereses, O(n) komplexitassal
  for (size_t j = 1; j < i; ++j) {
    if (arr[j] < min.val) {
        min.index = j;
        min.val = arr[j];
    }
    else if (arr[j] > max.val) {
        max.index = j;
        max.val = arr[j];
    }
  }

  printf("Az elemek kozul a legkisebb a %.2lf (index: %d) es a legnagyobb a %.2lf (index: %d).", min.val, min.index, max.val, max.index);

  free(arr);
  arr = NULL;

  return 0;
}
