#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool megegyezik(const char* str) {
    if (strlen(str) == 1) return true;

    char temp[strlen(str)];
    strcpy(temp, str);

    for (size_t i = 0, j = strlen(temp) - 1; i < strlen(temp) / 2; ++i, --j) {
      char t = temp[i];
      temp[i] = temp[j];
      temp[j] = t;
    }

    return (strcmp(str, temp) == 0);
}

int main() {
    printf("Adj megy egy karakterlancot: ");
    char string[255];
    scanf("%[^\n]%*c", string);

    if (megegyezik(string)) {
        printf("A karakterlanc megegyezik tukorkepevel.\n");
    } else {
        printf("A karakterlanc nem egyezik meg tukorkepevel.\n");
    }

    return 0;
}
