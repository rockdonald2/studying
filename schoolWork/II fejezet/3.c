#include <stdio.h>
#include <stdlib.h>

typedef struct Megoldas {
  double paros;
  int parosDb;
  double paratlan;
  int paratlanDb;
} Megoldas;

int main() {
  size_t hossz = 16;
  double *arr = (double*)malloc(hossz * sizeof(double));

  if (arr == NULL) {
    printf("Nincs elegendo memoria a tomb letrohazashoz.\n");
    return 1;
  }

  size_t sz = 0;
  double *temp; // ha realloc szukseges

  printf("Adj meg egy szokozokkel elvalasztott, tetszoleges hosszusagu egesz szamszort, majd a folytatashoz nyomj enter, majd CTRL+D-t.\n");
  while(scanf("%lf", arr + sz) == 1) {
    ++sz;
    if (sz == hossz) {
      temp = arr;
      hossz *= 2;
      arr = (double*)realloc(arr, hossz * sizeof(double));

      if (arr == NULL) {
        printf("Nincs elegendo memoria a tomb bovitesehez.\n");
        arr = temp;
        break;
      }
    }
  }

  if (sz == 0) {
    printf("Nem olvastunk be egyetlen szamot sem.\n");
    return 1;
  }

  Megoldas m = { .paros = 0, .parosDb = 0, .paratlan = 0, .paratlanDb = 0 };
  for (size_t i = 0; i < sz; ++i) {
    if ((int)arr[i] % 2 == 0) {
      m.paros += arr[i];
      ++(m.parosDb);
    } else {
      m.paratlan += arr[i];
      ++(m.paratlanDb);
    }
  }

  printf("A tomb paros elemeinek atlaga %.2lf, es paratlan elemeinek atlaga %.2lf.\n", m.paros / (double)m.parosDb, m.paratlan / (double)m.paratlanDb);

  free(arr);
  arr = NULL;

  return 0;
}
