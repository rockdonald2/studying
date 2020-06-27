#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int randomSzam(int also, int felso) {
    return (rand() % (felso - also + 1) + also);
}

void szerencsejatek() {
    int szam = randomSzam(101, 200);
    printf("Gondoltam egy szamra, probald meg kitalalni, a szam 101 es 200 kozott lehet, valahol.\n");

    int jatekos;
    int nyeremeny = 0;
    while (true) {
        printf("Add meg az altalad tippelt megoldast: ");
        scanf("%d", &jatekos);

        if (jatekos <= 100 || jatekos > 200) {
            printf("Az altalad megadott szam %d nem az adott intervallumbol szarmazik, amely [101, 200].\n", jatekos);
            continue;
        }

        if (jatekos == szam) {
            printf("Eltalaltad a megoldast! A nyeremenyed 10 lej.\n");
            nyeremeny += 10;
        } else if (abs(jatekos - szam) <= 10) {
            printf("Majdnem! A megoldas az altalad megadott szam %d kozeleben van (+- 10)! A nyeremenyed 1 lej.\n", jatekos);
            nyeremeny += 1;
        } else if (abs(jatekos - szam) <= 20) {
            printf("Majdnem! A megoldas az altalad megadott szam %d kozeleben van (+- 20)! A nyeremenyed 1 lej.\n", jatekos);
            nyeremeny += 1;
        } else {
            printf("Meg a kozeleben sem jarsz a szamoddal %d, probalkozz.\n", jatekos);
            continue;
        }

        printf("A vegso megoldas a %d volt. A jelenlegi nyeremenyed %d.\n", szam, nyeremeny);

        char dontes = ' ';
        while (dontes != 'i' && dontes != 'n') {
            printf("Akarod folytatni a jatekot? Igen(i) / nem(n)? ");
            scanf("%*c%c", &dontes);
        }

        if (dontes == 'i') {
            printf("\nAkkor kezdjuk elorol, gondoltam egy szamra 101 es 200 kozott.\n");
            continue;
        } else if (dontes == 'n') {
            printf("A jatek veget ert. A nyeremenyed %d lej.", nyeremeny);
            break;
        }
    }
}

int main() {
    srand(time(0));
    szerencsejatek();

    return 0;
}