#include <stdio.h>
#include <stdbool.h>

bool oszthato12(const int szam) {
	if (szam % 12 == 0) return true;
	else return false;
}

int main() {
	printf("Irj be egy egesz szamot: ");
	int szam;
	scanf("%d", &szam);
	printf("A kovetkezo szamot gepelted be: %d\n", szam);
	
	if (oszthato12(szam)) {
		printf("A begepelt szam (%d) oszthato 12-vel.", szam);
	} else {
		printf("A begepelt szam (%d) nem oszthato 12-vel.", szam);
	}
	
	return 0;
}
