#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define rep(i, a, n) for(int i = a; i < n; ++i)

typedef struct {
    int min, minIndex;
    int max, maxIndex;
} minMax;

typedef struct {
    int paros, parosElemek;
    int paratlan, paratlanElemek;
} atlag;

void feladatok(int n) {
    switch(n) {
        case 1: {
            int hossz;

            do {
                printf("Add meg a tomb hosszat: ");
                scanf("%d", &hossz);

                if (hossz < 0) {
                    printf("Negativ hossz.\n");
                }
            } while(hossz < 0);

            int *arr = (int*)malloc(hossz * sizeof(int));
            minMax megoldas = { .min = 0, .minIndex = 0, .max = 0, .maxIndex = 0 };

            rep(i, 0, hossz) {
                printf("Add meg tomb[%d] elemet: ", i);
                scanf("%d", &arr[i]);

                if (i == 0) {
                    megoldas.max = arr[i];
                    megoldas.min = arr[i];
                    continue;
                }

                if (arr[i] > megoldas.max) {
                    megoldas.max = arr[i];
                    megoldas.maxIndex = i;
                }
                else if (arr[i] < megoldas.min) {
                    megoldas.min = arr[i];
                    megoldas.minIndex = i;
                }
            }

            printf("A beolvasott szamok minimuma %d [indexe: %d], maximuma %d [indexe: %d].", megoldas.min, megoldas.minIndex, megoldas.max, megoldas.maxIndex);

            free(arr);
            break;
        }
        case 2: {
            int n;

            do {
                printf("Add meg az n erteket: ");
                scanf("%d", &n);

                if (n < 0) {
                    printf("Negativ szam.\n");
                } else if (n > 30) {
                    printf("30-nal nagyobb.\n");
                }
            } while(n < 0 || n > 30);

            int hossz = n;
            int *arr = (int*)malloc(hossz * sizeof(int));

            for (int i = 3, j = 0; i <= hossz * 3 && j < hossz; i += 3, ++j) {
                arr[j] = i;
            }

            printf("A tomb elemei: ");
            rep(i, 0, hossz) {
                printf("%d ", arr[i]);
            }

            free(arr);
            break;
        }
        case 3: {
            int n;

            do {
                printf("Add meg a tomb hosszat: ");
                scanf("%d", &n);

                if (n < 0) {
                    printf("Negativ szam.\n");
                }
            } while(n < 0);

            int *arr = (int*)malloc(n * sizeof(int));
            atlag megoldas = { .paros = 0, .parosElemek = 0, .paratlan = 0, .paratlanElemek = 0 };

            rep(i, 0, n) {
                printf("Add meg a tomb[%d] elemet: ", i);
                scanf("%d", &arr[i]);

                if (!(arr[i] % 2)) {
                    megoldas.paros += arr[i];
                    megoldas.parosElemek += 1;
                } else {
                    megoldas.paratlan += arr[i];
                    megoldas.paratlanElemek += 1;
                }
            }

            if (megoldas.parosElemek != 0 && megoldas.paratlanElemek != 0) {
                printf("A megadott tomb paros elemeinek atlaga %.3lf, paratlan elemeinek atlaga %.3lf.\n", ((double)megoldas.paros / megoldas.parosElemek), ((double)megoldas.paratlan / megoldas.paratlanElemek));
            } else if (megoldas.parosElemek != 0) {
                printf("A megadott tomb paros elemeinek atlaga %.3lf, paratlan elemeket nem adtal meg.\n", ((double)megoldas.paros / megoldas.parosElemek));
            } else if (megoldas.paratlanElemek != 0) {
                printf("A megadott tomb paratlan elemeinek atlaga %.3lf, paros elemet nem adtal meg.\n", ((double)megoldas.paratlan / megoldas.paratlanElemek));
            } else {
                printf("Egyetlen elemet sem adtal meg.\n");
            }

            free(arr);
            break;
        }
        case 4: {
            int n;

            do {
                printf("Add meg az n erteket: ");
                scanf("%d", &n);

                if (n < 1) {
                    printf("Kisebb mint 1.\n");
                } else if (n > 50) {
                    printf("Nagyobb mint 50.\n");
                }
            } while(n < 1 || n > 50);

            int *arr = (int*)malloc(n * sizeof(int));

            printf("Add meg azt a szamot, amivel oszthato kell legyenek az osszegbe foglalt szamok: ");
            int a;
            scanf("%d", &a);

            int osszeg = 0;

            for (int j = 0; j < n; ++j) {
                arr[j] = rand() % 1024;
                if (arr[j] % a == 0) {
                    osszeg += arr[j];
                }
            }

            printf("A tomb elemei: ");
            rep(i, 0, n) {
                printf("%d ", arr[i]);
            }

            printf("\nA tomb elemeinek osszege, amelyek oszthatok %d-el: %d", a, osszeg);

            break;
        }
        case 5: {
            int hossz = 8;
            int *arr = (int*)malloc(hossz * sizeof(int));
            int *temp = NULL;

            printf("Adj meg egy szamsort, szokozzel elvalasztva a szamokat, majd jelezd enter-rel a veget: ");
            int leutott = EOF;
            char end;
            int index = 0;
            int osszeg = 0;
            do {
                scanf("%d%c", &leutott, &end);

                arr[index++] = leutott;
                if (index >= 2 && arr[index - 1] < arr[0]) {
                    osszeg += arr[index - 1];
                }

                if (index >= hossz) {
                    hossz *= 2;
                    temp = (int*)realloc(arr, hossz * sizeof(int));

                    if (!temp) {
                        free(arr);
                        arr = NULL;
                        fprintf(stderr, "Nincs elengedo memoria a boviteshez.\n");
                        break;
                    }

                    arr = temp;
                }
            } while (end != '\n');

            printf("A tomb elemei: ");
            rep(i, 0, index) {
                printf("%d ", arr[i]);
            }

            printf("\nA tomb elso elemenel kisebb szamok osszege: %d", osszeg);

            break;
        }
        case 6: {
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
                    *(arr + i * oszlop + j) = i + j;
                }
            }

            rep(i, 0, sor) {
                rep(j, 0, oszlop) {
                    printf("tomb[%d][%d] = %d ", i, j, *(arr + i * oszlop + j));
                }
                printf("\n");
            }

            break;
        }
        case 7: {
            int arr[4][4];

            rep(i, 0, 4) {
                rep(j, 0, 4) {
                    if (i == j) arr[i][j] = 1;
                    else if (i > j) arr[i][j] = 3;
                    else if (i < j) arr[i][j] = 2;
                }
            }

            rep(i, 0, 4) {
                rep(j, 0, 4) {
                    printf("tomb[%d][%d] = %d ", i, j, arr[i][j]);
                }
                printf("\n");
            }

            break;
        }
    }
}

int main(void) {
    time_t t;
    srand((unsigned) time(&t));

    // 1. feladat
    //feladatok(1);

    // 2. feladat
    //feladatok(2);

    // 3. feladat
    //feladatok(3);

    // 4. feladat
    //feladatok(4);

    // 5. feladat
    //feladatok(5);

    // 6. feladat
    //feladatok(6);

    // 7. feladat
    feladatok(7);

    return 0;
}
