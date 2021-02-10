#include <stdlib.h>
#include <stdio.h>

size_t strlen(const char* string) {
  size_t i = 0;

  while (*(string + i) != '\0') {
    ++i;
  }

  return i;
}

int main() {
  printf("Adj meg egy stringet: ");
  char str[1024];
  fgets(str, sizeof(str), stdin);

  printf("A %s hossza: %lu.\n", str, strlen(str));

  return 0;
}
