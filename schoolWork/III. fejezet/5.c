#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* megfordit(const char* str) {
  char *temp = (char*)malloc(strlen(str) * sizeof(char));
  strcpy(temp, str);

  for (size_t i = 0, j = strlen(temp) - 1; i < strlen(temp) / 2; ++i, --j) {
    char t = temp[i];
    temp[i] = temp[j];
    temp[j] = t;
  }

  return temp;
}

int main() {
  char str[1024];
  printf("Adj meg egy stringet: ");
  scanf("%[^\n]%*c", &str);

  printf("Az altalad megadott %s forditva: %s", str, megfordit(str));

  return 0;
}
