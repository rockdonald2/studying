/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void nev() {
    char nev[120];
    scanf("%[^\n]%*c", &nev);
    printf("%s", nev);
}

void uresit() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main()
{
    int choice;
    do {
        printf("\nMenu\n\n");
        printf("0: Kilepes\n");
        printf("-------------------------------------------------------------------------------------\n");
        printf("1: Irjuk ki a nevunket.\n");
        printf("-------------------------------------------------------------------------------------\n");
        printf("2: Irjuk ki a szamokat 1-tol 99-ig.\n");
        printf("-------------------------------------------------------------------------------------\n");
        printf("3: Irjuk ki az elso 15 paros szamot.\n");
        printf("-------------------------------------------------------------------------------------\n");
        printf("4: Irjunk programot amely osszeadja az elso 25 szamot.\n");
        printf("-------------------------------------------------------------------------------------\n");
        printf("5: Irjunk programot amely egy adott szamrol eldonti, hogy paros vagy paratlan.\n");
        printf("-------------------------------------------------------------------------------------\n");
        printf("6: Irjuk ki, hogy hany darab pozitivszam van az adott tombben.\n");
        printf("-------------------------------------------------------------------------------------\n");
        printf("7: Fuzzunk ossze ket szoveget (stringet).\n");
        printf("-------------------------------------------------------------------------------------\n");
        printf("Melyik feladatot vegezze el? Feladat: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: {
                printf("\nIrjuk ki a nevunket.\n");
                uresit();
                nev();
                break;
            }
        }
    } while (choice != 0);
}*/
/*
#include <stdio.h>
#include <string.h>

void uresit() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void nev() {
    char nev[128];
    gets(nev);
    printf("%s ", nev);
}

void kiir() {
    for (int i = 1; i < 100; i++) {
        printf("%d ", i);
    }
}

void paroskiir() {
    int szamok = 0;
    for (int i = 0; i < 15; i++) {
        printf("%d ", szamok);
        szamok=szamok+2  ;
    }
}

void osszead() {
    int osszeg=0;
    for (int i = 1; i <= 25; i++) {
        osszeg = osszeg + i;
    }
    printf("%d \n", osszeg);
}

void parosparatlan() {
    int szam;
    scanf("%d", &szam);
    if (szam % 2 == 0) {
        printf("%d paros szam \n", szam);
    }
    else
    {
        printf("%d paratlan szam\n ", szam);
    }
}

void tomb() {
    int tombelem, pozitivszam=0;
    printf("Hany elemu a tomb? "); scanf_s("%d", &tombelem);
    int a[100];
    for (int i = 0; i <= tombelem-1; i++) {
        scanf_s("%d", &a[i]);
        if (a[i] > 0) pozitivszam++;
    }
    printf("Osszesen %d pozitivszam \n", pozitivszam);
}

void stringek() {
    char string1[256], string2[128];
    gets(string1);
    gets(string2);
    strcat_s(string1, string2);
    printf("%s", string1);
}

int main()
{
    int choice;
    do
    {
        system("cls");
        printf("Menu\n\n");
        printf("\n");
        printf("0: Kilepes\n");
        printf("-------------------------------------------------------------------------------------\n");
        printf("1: Irjuk ki a nevunket.\n");
        printf("-------------------------------------------------------------------------------------\n");
        printf("2: Irjuk ki a szamokat 1-tol 99-ig.\n");
        printf("-------------------------------------------------------------------------------------\n");
        printf("3: Irjuk ki az elso 15 paros szamot.\n");
        printf("-------------------------------------------------------------------------------------\n");
        printf("4: Irjunk programot amely osszeadja az elso 25 szamot.\n");
        printf("-------------------------------------------------------------------------------------\n");
        printf("5: Irjunk programot amely egy adott szamrol eldonti, hogy paros vagy paratlan.\n");
        printf("-------------------------------------------------------------------------------------\n");
        printf("6: Irjuk ki, hogy hany darab pozitivszam van az adott tombben.\n");
        printf("-------------------------------------------------------------------------------------\n");
        printf("7: Fuzzunk ossze ket szoveget (stringet).\n");
        printf("-------------------------------------------------------------------------------------\n");
        printf("Melyik feladatot vegezze el? Feladat: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nIrjuk ki a nevunket.\n");
            uresit();
            nev();
            system("pause");
            break;

        case 2:
            printf("Irjuk ki a szamokat 1-tol 99-ig.\n");
            kiir();
            printf("\n");
            system("pause");
            break;

        case 3:
            printf("Irjuk ki az elso 15 paros szamot.");
            paroskiir();
            printf("\n");
            system("pause");
            break;

        case 4:
            printf("Irjunk programot amely osszeadja az elso 25 szamot.");
            osszead();
            system("pause");
            break;

        case 5:
            printf("Irjunk programot amely egy adott szamrol eldonti, hogy paros vagy paratlan.");
            parosparatlan();
            system("pause");
            break;

        case 6:
            printf("Irjuk ki, hogy hany darab pozitivszam van az adott tombben.");
            tomb();
            system("pause");
            break;

        case 7:
            printf("Fuzzunk ossze ket szoveget (stringet).");
            stringek();
            system("pause");
            break;
        }
    } while (choice != 0);
}*/
/*
#include <stdio.h>
#include <stdlib.h>

void osztas() {
	int szam;
	scanf_s("%d", &szam);
	if (szam % 12 == 0)	printf("%d oszthato 12-vel", szam);
	else printf("%d nem oszthato 12-vel", szam);
}

void osztas2() {
	int szam1, szam2, hanyados,maradek ;
	scanf_s("%d %d", &szam1, &szam2);
	if (szam1 < szam2) {
		hanyados = szam2 / szam1;
		maradek = szam2 % szam1;
	}
	else
	{
		hanyados = szam1 / szam2;
		maradek = szam1 % szam2;
	}
	printf("Hanyados: %d \nMaradek: %d ", hanyados, maradek);
}

void szokoev() {
	int ev;
	scanf_s("%d", &ev);
	if (ev % 4 == 0) {
		if (ev % 100 == 0) {
			if (ev % 400 == 0) printf("%d szokoev.", ev);
			else printf("%d nem szokoev.", ev);
		}
		else
			printf("%d szokoev.", ev);
	}
	else
		printf("%d nem szokoev.", ev);
}


int main()
{
	osztas();
	//osztas2();
	//szokoev();
}*/

/*#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

typedef struct {
	int elso;
	int masodik;
} szamPar;

int kettoHatvanya(int szam) {
	if (szam < 1) return FALSE;

	if ((szam & (szam - 1)) == 0) return TRUE;
	else return FALSE;
}

int fibonacci(int szam) {
	if (szam < 1) return FALSE;

	int ideiglenes;

	double elsoFeltetel = sqrt((double)(5 * (szam * szam) + 4));
	ideiglenes = elsoFeltetel;

	if (ideiglenes == elsoFeltetel) return TRUE;

	double masodikFeltetel = sqrt((double)(5 * (szam * szam) - 4));
	ideiglenes = masodikFeltetel;

	if (ideiglenes == masodikFeltetel) return TRUE;

	return FALSE;
}

int szamJegyek(long long int szam) {
	if (szam == 0) return 1;

	int szamlalo = 0;
	while (szam != 0) {
		szam /= 10;
		++szamlalo;
	}

	return szamlalo;
}

void feladatok(int n) {
	switch(n) {
		case 1: {
			printf("Add meg a kamatlab nagysagat: ");
			double k;
			scanf("%lf", &k);

			printf("Add meg a lekotesi evek szamat: ");
			int n;
			scanf("%d", &n);

			double osszeg = 50 * (1 + n * (k / 100));

			printf("Ha 50 dollart a bankba teszunk, es a kamatlab %.3lf%%, akkor %d ev mulva %.3lf dollarunk lesz.\n", k, n, osszeg);

			break;
		}
		case 2: {
			printf("Adj meg szamparokat, mindegyik szampar eseten szokozzel valaszd el oket, illetoleg enterrel jelezd a szampar veget:\n");

			szamPar szP;
			szamPar maxAbs = { .elso = 0, .masodik = 0};

			do {
				scanf("%d %d", &(szP.elso), &(szP.masodik));

				if (abs(szP.elso - szP.masodik) > abs(maxAbs.elso - maxAbs.masodik)) {
					maxAbs.elso = szP.elso;
					maxAbs.masodik = szP.masodik;
				}

			} while ((szP.elso - szP.masodik) != 0);

			printf("A szampar, amelyik kozotti abszolut elteres a legnagyobb: %d %d", maxAbs.elso, maxAbs.masodik);

			break;
		}
		case 3: {
			printf("Adj meg egy szamot: ");
			int szam;
			scanf("%d", &szam);

			kettoHatvanya(szam) ? printf("A %d szam 2 hatvanya.\n", szam) : printf("A %d szam nem 2 hatvanya.\n", szam);

			break;
		}
		case 4: {
			printf("Adj meg egy szamot: ");
			int szam;
			scanf("%d", &szam);

			fibonacci(szam) ? printf("A %d szam Fibonacci szam.\n", szam) : printf("A %d szam nem Fibonacci szam.\n", szam);

			break;
		}
		case 5: {
			printf("Adj meg egy szamot: ");
			long long int szam;
			scanf("%lld", &szam);

			printf("A %lld szamjegyeinek szama: %d", szam, szamJegyek(szam));

			break;
		}
		case 6: {
			printf("Add meg hany szammal akarsz dolgozni: ");
        	int n;
        	scanf("%d", &n);

            int szam;
        	int oszthato3 = 0, oszthato5 = 0, oszthato15 = 0;
        	for (int i = 0; i < n; ++i) {
        		printf("Add meg az %d szamot: ", i + 1);
        		scanf("%d", &szam);

        		if (szam % 15 == 0) {
                    ++oszthato15;
                    ++oszthato5;
                    ++oszthato3;
                } else if (szam % 5 == 0) ++oszthato5;
                else if (szam % 3 == 0) ++oszthato3;
        	}

        	printf("Az altalad megadott szamok kozul %d oszthato 3-al, %d oszthato 5-el, es %d oszthato 15-el.", oszthato3, oszthato5, oszthato15);

			break;
		}
		case 7: {
			printf("Adj meg egy tetszoleges hosszusagu szamsort szokozzel elvalasztva a szamokat, es jelezd 0-val a veget: ");

            int szam, parosOsszeg = 0, parosSzamlalo = 0;
            do {
            	scanf("%d", &szam);

            	if (!(szam % 2) && szam != 0) {
            		parosOsszeg += szam;
            		++parosSzamlalo;
            	}
            } while (szam != 0);

            printf("Az altalad megadott szamsor paros szamjainak szamtani kozeparanyosa: %.3lf.\n", (double)parosOsszeg / parosSzamlalo);

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
	//feladatok(4);

	// 5. feladat
	//feladatok(5);

	// 6. feladat
	//feladatok(6);

	// 7. feladat
	feladatok(7);

	return 0;
}*/

/*#include <stdio.h>
#include <stdlib.h>

void feladatok(int n) {
	switch(n) {
		case 1: {
			printf("Adj meg egy masodpercben kifejezett idot: ");
			long int mp;
			scanf("%ld", &mp);

			int orak, perc, masodperc;

			orak = mp / 3600;
			if (orak > 0) mp -= (orak * 3600);
			perc = mp / 60;
			if (perc > 0) mp -= (perc * 60);

			masodperc = mp;

			printf("Az altalad megadott ido %d ora, %d perc, es %d masodperc.\n", orak, perc, masodperc);

			break;
		}
		case 2: {
			printf("Add meg melyik alpontot valasztottad (a-c): ");
			char alpont;
			scanf("%c", &alpont);

			printf("Add meg, hogy a szamsorozat hany tagjat irja ki: ");
			int n;
			scanf("%d", &n);

			switch(alpont) {
				case 'a': {
					int kezdo = 3;
					int novelo = 10;

                    printf("%d ", kezdo);
                    long int elozo = kezdo;
					for (int i = 1; i < n; ++i) {
                        elozo += kezdo * novelo;
						printf("%ld ", elozo);
						novelo *= 10;
					}

					break;
				}
				case 'b': {
					int kezdo = 3;
					int novelo = 5;

					printf("%d ", kezdo);
					for (int i = 1; i < n; ++i) {
						printf("%d ", kezdo + (i * novelo));
					}

					break;
				}
				case 'c': {
				    int kezdo = 1;
				    int novelo = 1;

				    printf("%d ", kezdo);
				    int tag;
				    for (int i = 1; i < n; ++i) {
                        tag = kezdo + (i * novelo);

                        if (!(tag % 2)) tag *= -1;

                        printf("%d ", tag);
				    }

					break;
				}
				case 3: {
				    // bruteforce megoldas,

                    break;
				}
			}
		}
	}
}

int main() {
	// 1. feladat
	//feladatok(1);

	// 2. feladat
	//feladatok(2);

	// 3. feladat
	feladatok(3);

	return 0;
}*/

/*#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define rep(i, a, n) for(int i = a; i < n; ++i)

typedef struct {
    int min;
    int max;
} minMax;

void feladatok(int n) {
    switch(n) {
        case 1: {
            int hossz;
            printf("Add meg a tomb hosszat: ");
            scanf("%d", &hossz);

            int *arr = (int*)malloc(hossz * sizeof(int));
            minMax megoldas = { .min = 0, .max = 0 };

            rep(i, 0, hossz) {
                printf("Add meg tomb[%d] elemet: ", i);
                scanf("%d", &arr[i]);

                if (i == 0) {
                    megoldas.max = arr[i];
                    megoldas.min = arr[i];
                    continue;
                }

                if (arr[i] > megoldas.max) megoldas.max = arr[i];
                else if (arr[i] < megoldas.min) megoldas.min = arr[i];
            }

            break;
        }
    }
}

int main(void) {
    // 1. feladat
    feladatok(1);

    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define rep(i, a, n) for(int i = a; i < n; ++i)

char* egyediSzamok(char szam[], int n) {
    int hossz = 32;
    char* egyedi = (char*)malloc(hossz * sizeof(char));
    char* temp = NULL;

    int FLAG = FALSE;
    int index = 0;
    rep(i, 0, n) {
        rep(j, 0, hossz) {
            if (!egyedi[j]) break;

            if (egyedi[j] == szam[i]) {
                FLAG = TRUE;
                egyedi[j] = '-';
            }

            if (FLAG) break;
        }

        if (!FLAG) {
            egyedi[index++] = szam[i];

            if (index >= hossz) {
                hossz *= 2;
                temp = (char*)realloc(egyedi, hossz * sizeof(char));

                if (!temp) {
                    free(temp);
                    temp = NULL;
                    fprintf(stderr, "Nincs elegendo memoria a boviteshez.\n");
                    exit(-1);
                }

                egyedi = temp;
            }
        }

        FLAG = FALSE;
    }

    egyedi[index] = '\0';

    return egyedi;
}

void feladatok(int n) {
    switch(n) {
        case 1: {
            printf("Add meg a ketdimenzios tomb sorainak es oszlopainak szamat, szokozzel elvalasztva: ");
            int sor, oszlop;
            scanf("%d %d", &sor, &oszlop);

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

            break;
        }
        case 2: {

            break;
        }
        case 3 : {
            // mivel, nincs olyan numerikus adattipus a C-ben, ami kepes 256 szamjegyet megjeleniteni, ezert string-et hasznalhatunk a szam tarolasara.
            printf("Add meg a szamot, ami max. 255 szamjegyet tartalmazhat: ");
            char szam[256];
            scanf("%s", szam);

            char* egyedi = egyediSzamok(szam, n);

            printf("A szamot alkoto kulonbozo szamjegyek: ");
            rep(i, 0, 256) {
                printf("%c ", egyedi[i]);

                if (!egyedi[i]) break;
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
    //feladatok(2);

    // 3.feladat
    feladatok(3);

    return 0;
}




