#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define rep(i, a, n) for(int i = a; i < n; ++i)

int cmpfunc(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void torolIsmetles(int arr[], int n) {
    rep(i, 0, n - 1) {
        if (arr[i] == arr[i + 1]) {
            int j = i + 1;
            while (arr[i] == arr[j]) arr[j++] = -1;
            arr[i] = -1;
            i = j - 1;
        }
    }
}

char* lekerMondat() {
	size_t hossz = 128;
	char* mondat = (char*)malloc(hossz * sizeof(char));
	char* tmp = NULL;
	int index = 0;
	int ch = EOF;

	printf("Adj meg egy szo sorozatot szokozzel elvalasztva a szavakat: ");

	while (ch) {
		ch = getchar();

		if (ch == '\n' || ch == EOF) break;

		if (hossz <= index) {
			hossz *= 2;
			tmp = (char*)realloc(mondat, hossz * sizeof(char));

			if (!tmp) {
				free(mondat);
				mondat = NULL;
				fprintf(stderr, "Nincs elegendo memoria a boviteshez.\n");
				return "-1";
			}

			mondat = tmp;
		}

		mondat[index++] = ch;
	}

	mondat[index] = '\0';

	return mondat;
}

char* trimwhitespace(char *str) {
    while(isspace((unsigned char)*str)) str++;

    if(*str == 0)
        return str;

    char* end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    *(end + 1) = '\0';

    return str;
}

int szavakSzama(char* string) {
    int i = 0, szavak = 0;

    while (string[i]) {
        if (string[i] == ' ') ++szavak;

        ++i;
    }

    return szavak + 1;
}

void feladatok(int n) {
    switch(n) {
        case 1: {
            int sor, oszlop;

            do {
                printf("Add meg a ketdimenzios tomb sorainak es oszlopainak szamat, szokozzel elvalasztva: ");
                scanf("%d %d", &sor, &oszlop);

                if (sor <= 0) {
                    printf("Negativ sor.\n");
                } else if (oszlop <= 0) {
                    printf("Negativ oszlop.\n");
                }
            } while(sor <= 0 || oszlop <= 0);

            int *arr = (int*)malloc(sor * oszlop * sizeof(int));

            rep(i, 0, sor) {
                rep(j, 0, oszlop) {
                    *(arr + i * oszlop + j) = rand() % 256;
                }
            }

            rep(i, 0, sor) {
                rep(j, 0, oszlop) {
                    printf("tomb[%d][%d] = %d ", i, j, *(arr + i * oszlop + j));
                }
                printf("\n");
            }

            int osszeg = 0;
            rep(i, 0, sor) {
                rep(j, 0, oszlop) {
                    if (!(i % 2) && !(j % 2) && !(*(arr + i * oszlop + j) % 2)) {
                        osszeg += *(arr + i * oszlop + j);
                    }
                }
            }

            printf("Azon paros elemek osszege, amelyek mindket indexe paros = %d", osszeg);

            free(arr);
            break;
        }
        case 2: {
            char* mondat = lekerMondat();
            mondat = trimwhitespace(mondat);

            printf("A megadott mondatban talalhato szavak szama: %d\n", szavakSzama(mondat));

            free(mondat);
            break;
        }
        case 3: {
            // mivel, nincs olyan numerikus adattipus a C-ben, ami kepes 256 szamjegyet megjeleniteni, ezert string-et hasznalhatunk a szam tarolasara.
            printf("Add meg a szamot, ami max. 255 szamjegyet tartalmazhat: ");
            char szam[256];
            scanf("%s%*c", szam);

            int szamArray[256];
            int hossz = 0;
            rep(i, 0, 256) {
                if (!szam[i] || szam[i] == '\n') break;

                szamArray[i] = szam[i] - '0';
                ++hossz;
            }

            qsort(szamArray, hossz, sizeof(int), cmpfunc);

            torolIsmetles(szamArray, hossz);

            printf("Az egyedi szamjegyek sora: ");
            rep(i, 0, hossz) {
                if (szamArray[i] != -1) printf("%d ", szamArray[i]);
            }

            break;
        }
    }
}

int main() {
    time_t t;
    srand((unsigned) time(&t));

    // 1. feladat
    //feladatok(1);

    // 2.feladat
    feladatok(2);

    // 3.feladat
    //feladatok(3);

    return 0;
}
