#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define rep(i,a,n) for(int i=a;i<n;++i)
#define rep2x(i,a,n) for(int i=a;i<n;i+=2)

bool paros(const int *n);
void uresit();
char* lekerMondat();
void feladatok(int n);

int main() {
	time_t t;
	srand((unsigned) time(&t));

	// 1. feladat
	feladatok(1);
	printf("\n\n");

	// 2. feladat
	feladatok(2);
	printf("\n\n");

	// 3. feladat
	feladatok(3);
	printf("\n\n");

	// 4. feladat
	feladatok(4);
	printf("\n\n");

	// 5. feladat
	feladatok(5);
	printf("\n\n");

	// 6. feladat
	feladatok(6);
	printf("\n\n");

	// 7. feladat
	feladatok(7);

	return 0;
}

bool paros(const int *n) {
	return !(*n % 2);
}

void uresit() {
	char c;
	while((c = getchar()) != '\n' && c != EOF);
}

char* lekerMondat() {
	size_t hossz = 128;
	char* mondat = (char*)malloc(hossz * sizeof(char));
	char* tmp = NULL;
	int index = 0;
	int ch = EOF;

	printf("Adj meg egy mondatot: ");
	fflush(stdout);

	while (ch) {
		ch = getchar();

		if (ch == '\n' || ch == EOF) break;

		if (hossz <= index) {
			hossz *= 2;
			tmp = (char*)realloc(mondat, hossz * sizeof(char));

			if (!tmp) {
				free(mondat);
				mondat = NULL;
				fprintf(stderr, "Nincs elegendo memoria a boviteshez.");
				return "-1";
			}

			mondat = tmp;
		}

		mondat[index++] = ch;
	}

	mondat[index] = '\0';

	return mondat;
}

void feladatok(int n) {
	switch(n) {
		case 1: {
			char nev[] = "Lukacs Zsolt";
			printf("Az en nevem %s.", nev);

			break;
		}
		case 2: {
			rep(i, 1, 100) printf("%d ", i);

			break;
		}
		case 3: {
			rep2x(i, 2, 31) printf("%d ", i);

			break;
		}
		case 4: {
			int osszeg = 0;
			rep(i, 1, 26) osszeg += i;
			printf("Az elso 25 szam osszege %d.", osszeg);

			break;
		}
		case 5: {
			int szam;
			printf("Adj megy egy szamot, melynek parossagat vizsgalni szeretned: ");
			fflush(stdout);
			scanf("%d", &szam);

			paros(&szam) ? printf("%d paros.", szam) : printf("%d paratlan.", szam); 

			break;
		}
		case 6: {
			const size_t c_hossz = 128;
			int *arr = (int*)malloc(c_hossz * sizeof(int));

			int pozSzamlalo = 0;
			int negSzamlalo = 0;
			rep(i, 0, c_hossz) {
				if (rand() % 2) {
					arr[i] = -(rand() % 256);
					++negSzamlalo;
				} else {
					arr[i] = (rand() % 256);
					++pozSzamlalo;
				}
			}

			printf("A tomb a kovetkezo ertekeket tartalmazza:\n");
			rep(i, 0, c_hossz) {
				printf("%d ", arr[i]);

				if (i % 10 == 0 && i > 0) printf("\n");
			}
			printf("\nAmelyek kozul %d pozitiv es %d negativ.", pozSzamlalo, negSzamlalo);

			break;
		}
		case 7: {
			uresit();
			char* elsoFele = lekerMondat();
			char* masodikFele = lekerMondat();
			char* tmp;

			if (strcmp(elsoFele, "-1") == 0 || strcmp(masodikFele, "-1") == 0) break;

			if (strlen(elsoFele) - strlen(masodikFele) <= strlen(masodikFele)) {
				tmp = (char*)realloc(elsoFele, (strlen(elsoFele) + strlen(masodikFele)) * sizeof(char));

				if (!tmp) {
					free(elsoFele);
					free(masodikFele);
					elsoFele = NULL;
					masodikFele = NULL;

					fprintf(stderr, "Nincs elengedo memoria az osszefuzeshez.");
					break;
				}

				elsoFele = tmp;
			}

			printf("A ket mondat osszefuzve: %s", strcat(elsoFele, masodikFele));

			break;
		}
	}
}