#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool szokoev(const int *evszam) {
	return (*evszam % 400 == 0) || ((*evszam % 100 != 0) && (*evszam % 4 == 0));
}

bool oszthato12(const int* n) {
	return !(*n % 12);
}

void feladatok(int n) {
	switch(n) {
		case 1: {
			int szam;
			printf("Adj meg egy egesz szamot: ");
			fflush(stdout);
			scanf("%d", &szam);

			oszthato12(&szam) ? printf("%d oszthato 12-vel.", szam) : printf("%d nem oszthato 12-vel", szam);

			break;
		}
		case 2: {
			int szam1, szam2;
			printf("Adj meg ket szamot szokozzel elvalasztva: ");
			fflush(stdout);
			scanf("%d%d", &szam1, &szam2);

			if (szam1 > szam2) {
				printf("%d : %d = %d, r = %d", szam1, szam2, szam1 / szam2, szam1 % szam2);
			} else {
				printf("%d : %d = %d, r = %d", szam2, szam1, szam2 / szam1, szam2 % szam1);
			}

			break;
		}
		case 3: {
			int evszam;
			printf("Adj meg egy evszamot: ");
			fflush(stdout);
			scanf("%d", &evszam);

			szokoev(&evszam) ? printf("%d szokoev.", evszam) : printf("%d nem szokoev.", evszam);

			break;
		}
	}
}

int main() {
	// 1. feladat
	feladatok(1);
	printf("\n\n");

	// 2. feladat
	feladatok(2);
	printf("\n\n");

	// 3. feladat
	feladatok(3);

	return 0;
}