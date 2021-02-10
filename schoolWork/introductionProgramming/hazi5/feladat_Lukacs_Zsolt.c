#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    char* csnev;
    char* knev;
    double atlag;
} tanulo;

typedef struct {
    long megtettUtNaponta[7];
    long megtettUt;
    double fogyasztas;
} jarmu;

int lnko(int a, int b) {
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }

    return a;
}

int lkt(int a, int b) {
    return (a * b) / lnko(a, b);
}

int evNapja(int honap, int nap) {
    if (honap < 1 || honap > 12) return -1;
    else if (nap < 1 || nap > 31) return -1;

    int honapok[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int napok = 0;
    while (honap > 1) napok += honapok[honap-- - 2];

    return napok + nap;
}

int uresSor(const char *buff) {
    char k;

    do {
        k = *(buff++);

        if (k != ' ' && k != '\t' && k != '\n' && k != '\r' && k != '\0') {
            return FALSE;
        }
    } while (k != '\0');

    return TRUE;
}

char* megfordit(char *str, int len) {
    char* forditott = (char*)malloc(len * sizeof(char));

    if (forditott == NULL) return NULL;

    for (int i = 0; i < len; ++i) {
        forditott[i] = str[len - i - 1];
    }

    return forditott;
}

void feladatok(int n) {
    switch(n) {
            case 1: {
                int hossz = 32;
                char* str = (char*)malloc(hossz * sizeof(char));
                char* tmp = NULL;

                int ch = EOF;
                int index = 0;

                printf("Adj meg egy szot, amit megforditanal: ");

                while (ch) {
                    ch = getchar();

                    if (ch == '\n' || ch == EOF) break;

                    if (index >= hossz) {
                        hossz *= 2;
                        tmp = (char*)realloc(str, hossz * sizeof(char));

                        if (!tmp) {
                            free(str);
                            str = NULL;
                            fprintf(stderr, "Nincs elegendo memoria a string bovitesehez.\n");
                            exit(-1);
                        }

                        str = tmp;
                    }

                    str[index++] = ch;
                }

                str[index] = '\0';

                char* megforditott = megfordit(str, strlen(str));

                if (megforditott == NULL) exit(-1);

                printf("A szo megforditva: %s\n", megforditott);

                free(megforditott);
                free(str);
                break;
            }

            case 2: {
                int elso, masodik;
                printf("Adj meg ket szamot, amelyeknek a legkisebb kozos tobbszoroset keresed, szokozzel valaszd el oket: ");
                scanf("%d %d", &elso, &masodik);

                printf("A ket szam legkisebb kozos tobbszorose: %d\n", lkt(elso, masodik));

                break;
            }
            case 3: {
                printf("Add meg a datumot \"honap, nap\" alakban, vesszovel valaszd el a honapot a naptol: ");
                int honap, nap;
                scanf("%d, %d", &honap, &nap);

                printf("A %d, %d az ev %d. napja.\n", honap, nap, evNapja(honap, nap));

                break;
            }
            case 4: {
                FILE* in;
                FILE* out;

                if ((out = fopen("szoveg.out", "w")) == NULL) {
                    fprintf(stderr, "Sikertelen az output allomany letrehozasa.\n");
                    exit(-1);
                }

                if ((in = fopen("szoveg.in", "r")) == NULL) {
                    fprintf(stderr, "Sikertelen az input allomany megnyitasa.\n");
                    exit(-1);
                } else {
                    char buff[255];

                    while ((fgets(buff, 255, in)) != NULL) {
                        if (!uresSor(buff)) {
                            if ((fputs(buff, out)) == EOF) {
                                fprintf(stderr, "Az output allomany kiirasa sikertelen.\n");
                                fclose(in);
                                exit(-1);
                            }
                        }
                    }

                    if (out != NULL) printf("Az output allomany sikeresen kiirva.\n");
                    else {
                        fprintf(stderr, "Az output allomany kiirasa sikertelen.\n");
                        fclose(in);
                        exit(-1);
                    }
                }

                fclose(in);
                fclose(out);
                break;
            }
            case 5: {
                FILE* in;

                if ((in = fopen("szamok.txt", "r")) == NULL) {
                    fprintf(stderr, "A szamok.txt fajl megnyitasa sikertelen.\n");
                    exit(-1);
                } else {
                    long sz, osszeg = 0, szSz = 0;

                    while (TRUE) {
                        if ((fscanf(in, "%ld", &sz)) == EOF) {
                            break;
                        } else {
                            printf("A beolvasott szam %ld.\n", sz);
                            osszeg += sz;
                            ++szSz;
                        }
                    }

                    printf("A szamok.txt egesz szamjainak osszege %ld, %ld szamot tartalmaz, ezek szamtani atlaga pedig %.3lf.\n", osszeg, szSz, (double)osszeg / szSz);
                }

                fclose(in);
                break;
            }
            case 6: {
                tanulo t = { .csnev = "Lukacs", .knev = "Zsolt", .atlag = 10.00 };

                printf("A tanulo csaladneve %s, keresztneve %s, es atlaga %.2lf.\n", t.csnev, t.knev, t.atlag);

                break;
            }
            case 7: {
                int hossz;

                do {
                    printf("Add meg a jarmuvek szamat: ");
                    scanf("%d", &hossz);

                    if (hossz <= 0) {
                        printf("Helytelen jarmuszam.\n");
                    }
                } while (hossz <= 0);

                jarmu *tomb = (jarmu*)malloc(hossz * sizeof(jarmu));
                const int napok = 7;

                double f;
                for (int i = 0; i < hossz; ++i) {
                    printf("Add meg a %d. auto atlagfogyasztasat 100km-en: ", i + 1);
                    scanf("%lf", &f);
                    tomb[i].fogyasztas = f;
                    tomb[i].megtettUt = 0;
                }

                long ut;
                for (int j = 0; j < napok; ++j) {
                    for (int i = 0; i < hossz; ++i) {
                        printf("Add meg a %d. auto %d. nap megtett utjat: ", i + 1, j + 1);
                        scanf("%ld", &ut);
                        tomb[i].megtettUtNaponta[j] = ut;
                    }
                }

                for (int i = 0; i < hossz; ++i) {
                    for (int j = 0; j < napok; ++j) {
                        tomb[i].megtettUt += tomb[i].megtettUtNaponta[j];
                    }
                }

                for (int i = 0; i < hossz; ++i) {
                    printf("%d. auto megtett utja 1 het alatt %ld km es atlagfogyasztasa 100km-en %.1lf l.\n1 het alatt, tehat %.2lf l uzemanyagot fogyasztott.\n\n", i + 1, tomb[i].megtettUt, tomb[i].fogyasztas, ((double)tomb[i].megtettUt / 100) * tomb[i].fogyasztas);
                }

                free(tomb);
                break;
            }
    }
}

int main() { 
    // 1. feladat
    //feladatok(1);

    // 2. feladat
    //feladatok(2);

    // 3. feladat
    //feladatok(3);

    // 4. feladat
    feladatok(4);

    // 5. feladat
    //feladatok(5);

    // 6. feladat
    //feladatok(6);

    // 7. feladat
    //feladatok(7);

    return 0;
}
