#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>

#define FALSE 0
#define TRUE 1

typedef struct {
    int sorszam;
    int pontszam;
} versenyzo;

typedef struct {
    char* nev;
    double fizetes;
} dolgozo;

typedef struct {
    dolgozo adatok;
    char* szak;
} szakmunkas;

typedef struct {
    dolgozo adatok;
    char* egyetem;
    int zaroev;
} mernok;

typedef struct {
    dolgozo adatok;
    int lekonyveltEvek;
    int gyerekekSzama;
} konyvelo;

char* lekerNev() {
    printf("Add meg az adott alkalmazott nevet: ");
    char* str = (char*)malloc(96 * sizeof(char));
    scanf("%[^\n]%*c", str);

    return str;
}

double lekerFizetes() {
    double fiz;
    do {
        printf("Add meg az adott alkalmazott fizeteset: ");
        scanf("%lf%*c", &fiz);

        if (fiz < 0) printf("Nem kaphat valaki negativ fizetest.\n");
    } while (fiz < 0);

    return fiz;
}

int lekerEvek() {
    int evek;
    do {
        printf("Add meg az adott alkalmazott lekonyvelt eveinek szamat: ");
        scanf("%d%*c", &evek);

        if (evek < 0) printf("Nem dolgozhatott valaki negativ eveket.\n");
    } while (evek < 0);

    return evek;
}

int lekerGyerekek() {
    int gyerekek;
    do {
        printf("Add meg az adott alkalmazott gyerekeinek szamat: ");
        scanf("%d%*c", &gyerekek);

        if (gyerekek < 0) printf("Nem lehet valakinek negativ szamu gyereke.\n");
    } while (gyerekek < 0);

    return gyerekek;
}

int lekerZaroEv() {
    int zaroev;
    do {
        printf("Add meg az adott alkalmazott tanulmanyainak zaro evet: ");
        scanf("%d%*c", &zaroev);

        if (zaroev < 1940 || zaroev > 2020) printf("Nem valoszeru zaroev.\n");
    } while (zaroev < 1940 || zaroev > 2020);

    return zaroev;
}

char* lekerEgyetem() {
    printf("Add meg az adott alkalmazott altal elvegzett egyetem nevet: ");
    char* egyetem = (char*)malloc(128 * sizeof(char));
    scanf("%[^\n]%*c", egyetem);

    return egyetem;
}

char* lekerSzak() {
    printf("Add meg az adott alkalmazott szakiranyat: ");
    char* szak = (char*)malloc(96 * sizeof(char));
    scanf("%[^\n]%*c", szak);

    return szak;
}

void verseny() {
    int vSzam;
    printf("Add meg a versenyzok szamat: ");
    scanf("%d", &vSzam);

    versenyzo* versenyzok = (versenyzo*)malloc(vSzam * sizeof(versenyzo));

    for (int init = 0; init < vSzam; ++init) {
        versenyzok[init].sorszam = init + 1;
        versenyzok[init].pontszam = 0;
    }

    for (int kor = 0; kor < vSzam; ++kor) {
        versenyzok[kor].pontszam = rand() % 55 + 1;
        printf("Az %d. versenyzo kovetkezik.\nAz %d. versenyzo pontszama %d.\n", versenyzok[kor].sorszam, versenyzok[kor].sorszam, versenyzok[kor].pontszam);

        for (int s = 0; s < vSzam - 1; ++s) {
            int legnagyobb = s;

            for (int c = s + 1; c < vSzam; ++c) {
                if (versenyzok[c].pontszam > versenyzok[legnagyobb].pontszam) {
                    legnagyobb = c;
                }
            }

            versenyzo idg = versenyzok[s];
            versenyzok[s] = versenyzok[legnagyobb];
            versenyzok[legnagyobb] = idg;
        }

        printf("\nAz elso harom helyezett: \n");
        for (int h = 0; h < 3; ++h) {
            if (versenyzok[h].pontszam != 0) {
                printf("%d. helyezett a %d. sorszamu versenyzo, akinek a pontszama %d.\n", h + 1, versenyzok[h].sorszam, versenyzok[h].pontszam);
            } else {
                printf("%d. helyezett a %d. sorszamu versenyzo, aki meg nem indult.\n", h + 1, versenyzok[h].sorszam);
            }
        }
        printf("\n");
    }

    free(versenyzok);
}

void feladatok(int n) {
    switch(n) {
        case 1: {
            FILE* in;

            if ((in = fopen("szoveg.txt", "r")) == NULL) {
                fprintf(stderr, "A szoveg.txt allomany megnyitasa sikertelen.\n");
                exit(-1);
            }

            int flag = 0, szamlalo = 0;
            for (char c, utolso = '0'; (c = fgetc(in)) != EOF; utolso = c) {
                if ((utolso == '0' || utolso == '\n' || utolso == ' ') && isalnum(c)) {
                    while (isalnum(c) && c >= 'a' && c <= 'z') {
                        if ((c = fgetc(in)) == EOF) {
                            flag = TRUE;
                            break;
                        }
                    }
                    utolso = c;

                    if (flag) break;

                    if (!isalnum(utolso)) ++szamlalo;
                }
            }

            fclose(in);
            printf("A szoveg.txt allomany %d csak kisbetubol allo szot tartalmazott.\n", szamlalo);
            break;
        }
        case 2: {
            konyvelo konyveloLista[100];
            int indexKonyvelo = 0;
            szakmunkas szakmunkasLista[100];
            int indexSzakmunkas = 0;
            mernok mernokLista[100];
            int indexMernok = 0;

            char flair;
            for (int c = 0; c < 300; ++c) {
                do {
                    printf("\nAdd meg azon szerep egy kezdobetujet, amilyen szerepet betolto alkalmazottat irsz a rendszerbe, vagy q-t a kilepeshez. \n");
                    printf("A valaszthato kezdobetuk: (k)onyvelo, (s)zakmunkas, es (m)ernok: ");
                    scanf("%c%*c", &flair);
                } while (flair != 'k' && flair != 's' && flair != 'm' && flair != 'q');

                if (flair == 'q') break;

                switch(flair) {
                    case 'k': {
                        konyveloLista[indexKonyvelo].adatok.nev = lekerNev();
                        
                        konyveloLista[indexKonyvelo].adatok.fizetes = lekerFizetes();

                        konyveloLista[indexKonyvelo].lekonyveltEvek = lekerEvek();

                        konyveloLista[indexKonyvelo++].gyerekekSzama = lekerGyerekek();

                        break;
                    }
                    case 'm': {
                        mernokLista[indexMernok].adatok.nev = lekerNev();
                        
                        mernokLista[indexMernok].adatok.fizetes = lekerFizetes();

                        mernokLista[indexMernok].egyetem = lekerEgyetem();

                        mernokLista[indexMernok++].zaroev = lekerZaroEv();
                        
                        break;
                    } 
                    case 's': {
                        szakmunkasLista[indexSzakmunkas].adatok.nev = lekerNev();
                        
                        szakmunkasLista[indexSzakmunkas].adatok.fizetes = lekerFizetes();

                        szakmunkasLista[indexSzakmunkas++].szak = lekerSzak();

                        break;
                    }
                }
            }

            printf("\nA jegyzek szakmunkasai\nNev - Fizetes - Szak\n");
            for (int i = 0; i < indexSzakmunkas; ++i) {
                printf("%s - %.1lf - %s\n", szakmunkasLista[i].adatok.nev, szakmunkasLista[i].adatok.fizetes, szakmunkasLista[i].szak);
            }

            printf("\nA jegyzek mernokei\nNev - Fizetes - Egyetem - Zaroev\n");
            for (int i = 0; i < indexMernok; ++i) {
                printf("%s - %.1lf - %s - %d\n", mernokLista[i].adatok.nev, mernokLista[i].adatok.fizetes, mernokLista[i].egyetem, mernokLista[i].zaroev);
            }

            printf("\nA jegyzek konyveloi\nNev - Fizetes - Lekonyvelt evek - Gyerekek szama\n");
            for (int i = 0; i < indexKonyvelo; ++i) {
                printf("%s - %.1lf - %d - %d\n", konyveloLista[i].adatok.nev, konyveloLista[i].adatok.fizetes, konyveloLista[i].lekonyveltEvek, konyveloLista[i].gyerekekSzama);
            }

            break;
        }
        case 3: {
            verseny();

            break;
        }
    }
}

int main() {
    time_t t;
    srand((unsigned) time(&t));

    // 1. feladat
    //feladatok(1);

    // 2. feladat
    feladatok(2);

    // 3. feladat
    //feladatok(3);

    return 0;
}
