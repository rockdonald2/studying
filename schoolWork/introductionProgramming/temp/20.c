#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char* evszak(char* honap) {
    int i = 0;
    while (honap[i]) {
        honap[i] = tolower(honap[i]);

        i++;
    }

    if (strcmp(honap, "december") == 0 || strcmp(honap, "januar") == 0 || strcmp(honap, "februar") == 0) return "tel";
    else if (strcmp(honap, "marcius") == 0 || strcmp(honap, "aprilis") == 0 || strcmp(honap, "majus") == 0) return "tavasz";
    else if (strcmp(honap, "junius") == 0 || strcmp(honap, "julius") == 0 || strcmp(honap, "augusztus") == 0) return "nyar";
    else if (strcmp(honap, "szeptember") == 0 || strcmp(honap, "oktober") == 0 || strcmp(honap, "november") == 0) return "osz";
    else return "(Err: Ervenytelen honap.)";
}

int main() {
    char* honap = (char*)malloc(32 * sizeof(char) + 1);
    printf("Add meg a honapot: ");
    scanf("%[^\n]%*c", honap);
    printf("A honaphoz tartozo evszak: %s", evszak(honap));

    return 0;
}