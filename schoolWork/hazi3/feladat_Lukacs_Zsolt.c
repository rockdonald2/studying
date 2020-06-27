#include <stdio.h>
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
	if (szam < 0) return FALSE;

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
			printf("Add meg a kamatlab nagysagat szazalekban kifejezve: ");
			double k;
			scanf("%lf", &k);

			int n;
			do {
				printf("Add meg a lekotesi evek szamat: ");
				scanf("%d", &n);

				if (n < 0) {
					printf("Negativ evre nem tudod lekotni a penzed.\n");
				}
			} while (n < 0);

			// linearis kamatszamitas, C1 = C0 * (1 + n*k)
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
        		printf("Add meg az %d. szamot: ", i + 1);
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

			if (parosOsszeg == 0) {
				printf("Egyetlen paros szamot sem adtal meg.\n");
				break;
			}

            printf("Az altalad megadott szamsor paros szamjainak szamtani kozeparanyosa: %.3lf.\n", (double)parosOsszeg / parosSzamlalo);

            break;
		}
	}
}

int main() {
	// 1. feladat
	feladatok(1);

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
	//feladatok(7);

	return 0;
}
