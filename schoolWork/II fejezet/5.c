#include <stdio.h>
#include <stdlib.h>

int main() {
  size_t hossz = 16;
  int *arr = (int*)malloc(hossz * sizeof(int));

  if (arr == NULL) {
    fprintf(stderr, "Nincs elegendo memoria a tomb letrohazahoz.\n");
    return -1;
  }

  size_t sz = 0;
  int *temp; // reallochoz

  printf("Adj meg egy szokozokkel elvalasztott, tetszoleges hosszusagu egesz szamszort, majd a folytatashoz nyomj enter, majd CTRL+D-t.\n");
  while (scanf("%d", arr + sz) == 1) {
    ++sz;
    if (sz == hossz) {
      temp = arr;
      hossz *= 2;
      arr = (int*)realloc(arr, hossz * sizeof(int));

      if (arr == NULL) {
        fprintf(stderr, "Nincs elengedo memoria a boviteshez.\n");
        arr = temp;
        break;
      }
    }
  }

  printf("A vegso megoldas tombje: ");
  int *f = (int*)malloc((sz + 1) * sizeof(int));
  for (size_t it = 0; it < sz; ++it) {
    f[it] = (arr[it] * arr[it]);
    printf("%d ", f[it]);
  }

  return 0;
}
