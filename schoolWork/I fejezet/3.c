#include <stdio.h>
#include <stdbool.h>

bool szokoev(int evszam) {
	// alapvetoen harom feltetelnek kell teljesulnie, ahhoz, hogy egy adott evszam szokoev legyen: 400 tobbszorose, de 100-nak nem, ugyanakkor 4-nek is tobbszorose.
	
	if (evszam % 400 == 0) return true;
	
	if (evszam % 100 == 0) return false;
	
	if (evszam % 4 == 0) return true;
	
	return false;
}

int main() {
	printf("Gepelj be egy evszamot: ");
	int evszam;
	scanf("%d", &evszam);
	printf("A kovetkezo evszamot gepelted be: %d\n", evszam);
	
	if (szokoev(evszam)) {
		printf("Az altalad begepelt evszam (%d) szokoevnek tekintheto.", evszam);
	} else {
		printf("Az altalad begepelt evszam (%d) nem szokoev.", evszam);
	}
	
	return 0;
}
