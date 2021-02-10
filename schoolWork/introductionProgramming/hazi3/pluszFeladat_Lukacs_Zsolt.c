#include <stdio.h>
#include <stdlib.h>

#define rep(i, a, n) for(int i = a; i < n; ++i)

#define TRUE 1
#define FALSE 0

typedef struct {
	int elso;
	int masodik;
} szamPar;

int megfordit(int a) {
	int temp = 0;

	while (a > 0) {
		temp = temp * 10 + (a % 10);
		a /= 10;
	}

	return temp;
}

void feladatok(int n) {
	switch(n) {
		case 1: {
			long int mp;
			do {
				printf("Adj meg egy masodpercben kifejezett idot: ");
				scanf("%ld", &mp);

				if (mp < 0) {
					printf("Negativ masodperc.\n");
				}
			} while (mp < 0);

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
			char alpont;
			do {
				printf("Add meg melyik alpontot valasztottad (a-c): ");
				scanf("%c%*c", &alpont);
			} while (alpont != 'a' && alpont != 'b' && alpont != 'c');

			printf("Add meg, hogy a szamsorozat hany tagjat irja ki: ");
			int n;
			scanf("%d", &n);

			switch(alpont) {
				case 'a': {
					long int kezdo = 3;
					long int novelo = 10;

                    printf("%ld ", kezdo);
                    long int elozo = kezdo;
					for (int i = 1; i < n; ++i) {
                        elozo += kezdo * novelo;
						printf("%ld ", elozo);
						novelo *= 10;
					}

					break;
				}
				case 'b': {
					long int kezdo = 3;
					long int novelo = 5;

					printf("%ld ", kezdo);
					for (int i = 1; i < n; ++i) {
						printf("%ld ", kezdo + (i * novelo));
					}

					break;
				}
				case 'c': {
					long int kezdo = 1;
					long int novelo = 1;

					printf("%ld ", kezdo);
					long int tag;
					for (int i = 1; i < n; ++i) {
                        tag = kezdo + (i * novelo);

                        if (!(tag % 2)) tag *= -1;

                        printf("%ld ", tag);
					}
				}
			}

			break;
		}
		case 3: {
			szamPar megoldasok[128];
			int megoldasLepteto = 0;

			/*
			Alapvető ötlet az algoritmus során, hogy megpróbál keresni egy másik cellát, amely mindenképp egyrészt sorszámban fentebb helyezkedik el, és oszlopban pedig attól jobbra, hiszen balra csak annál kisebb cellák vannak

			i - sorszam
			j - oszlopszam
			jj - eltolt oszlopszam
			ii - eltolt sorszam
			*/

			int szorzat, szamlalo = 0;
			rep(i, 2, 10) {
				rep(j, 1, 10) {
					szorzat = i * j;

					rep(jj, j + 1, 10) {
						rep(ii, 1, i) {
							if (ii * jj == szorzat) {
								megoldasok[megoldasLepteto].elso = ii * 10 + j;
								megoldasok[megoldasLepteto++].masodik = i * 10 + jj;
								++szamlalo;
							}
						}
					}
				}
			}

			// check, a * d = b * c, ahol az elso = ab, és a második = cd
			int rosszMegoldas = 0;
			rep(i, 0, megoldasLepteto) {
				if (((megoldasok[i].elso / 10) * (megoldasok[i].masodik % 10)) != ((megoldasok[i].elso % 10) * (megoldasok[i].masodik / 10))) {
					++rosszMegoldas;
				}
			}

			rep(i, 0, megoldasLepteto) {
				printf("%d es %d: %d * %d = %d * %d = %d\n",
					megoldasok[i].elso, megoldasok[i].masodik,
					megoldasok[i].elso, megfordit(megoldasok[i].masodik),
					megfordit(megoldasok[i].elso), megoldasok[i].masodik,
					megoldasok[i].elso * megfordit(megoldasok[i].masodik));
			}

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
	feladatok(3);

	return 0;
}
