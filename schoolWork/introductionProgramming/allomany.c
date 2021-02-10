/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE* in;

    if ((in = fopen("ki.txt", "w")) == NULL) {
        fprintf(stderr, "Allomany megnyitasa sikertelen.\n");
        exit(-1);
    }

    char sor[128];
    scanf("%s", sor);
    while (strcmp(sor, "***")) {
        if (strchr(sor, 'b') != NULL || strchr(sor, 'a') != NULL) {
            fprintf(in, "%s\n", sor);
        }

        scanf("%s", sor);
    }

    fclose(in);
    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define keresMassalhangzo(c) (strchr("bcdfghjklmnpqrstvwxyz", tolower(c)))

int main(void) {
    FILE* in;
    FILE* out;

    if ((in = fopen("be.txt", "r")) == NULL) {
        fprintf(stderr, "Allomany megnyitasa sikertelen.\n");
        exit(-1);
    }

    if ((out = fopen("ki.txt", "w")) == NULL) {
        fprintf(stderr, "Allomany letrehozasa sikertelen.\n");
        fclose(in);
        exit(-1);
    }

    char buff[64];
    char k;
    while ((fscanf(in, "%s", buff)) != EOF) {
        char* s = buff;
        
        k = *(s++);

        while (k != '\0') {
            if (keresMassalhangzo(k)) {
                fprintf(out, "%s\n", buff);
                break;
            }

            k = *(s++);
        }
    }

    fclose(out);
    fclose(in);
    return 0;
}


/*for (int i = 0; i < 64; ++i) {
            if (buff[i] == '\0') break;

            k = buff[i];

            if (keresMassalhangzo(k) != NULL) {
                fprintf(out, "%s\n", buff);
                break;
            }
}*/