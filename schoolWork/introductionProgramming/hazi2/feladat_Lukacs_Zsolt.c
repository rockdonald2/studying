#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*

Compile terminálból:
    gcc feladat.c -o feladat.out -lm

*/

void fib(int n) {
    int a = 0, b = 1, c = 0;

    for (int i = 0; i < n; ++i) {
        c = a + b;
        b = a;
        a = c;
        printf("%d ", a);
    }
}

bool palindrome(int n) {
    if (n == 0) return true;
    else if (n < 0 || (n % 10 == 0 && n != 0)) return false;

    int forditott = 0;

    while (n > forditott) {
        forditott = forditott * 10 + n % 10;
        n /= 10;
    }

    return n == forditott || n == forditott / 10;
}

void feladatok(int n) {
    switch(n) {
        case 1: {
            for (char karakter = 'a'; karakter <= 'z'; ++karakter) printf("%c ", karakter);
            fflush(stdout);

            break;
        }
        case 2: {
            printf("\nAdj meg egy tetszoleges hosszusagu szamsort szokozzel elvalasztva a szamokat, es jelezd 0-val a veget: ");
            fflush(stdout);

            int szam, szamolo = 0;
            do {
                scanf("%d", &szam);
                if (szam) ++szamolo;
            } while (szam != 0);

            printf("Az altalad megadott szamsor %d szamot tartalmazott.\n", szamolo);

            break;
        }
        case 3: {
            printf("Adj meg egy tetszoleges hosszusagu szamsort szokozzel elvalasztva a szamokat, es jelezd 0-val a veget: ");
            fflush(stdout);


            int szam, osszeg = 0;
            do {
                scanf("%d", &szam);
                osszeg += szam;
            } while (szam != 0);

            printf("Az altalad megadott szamsor osszege %d.\n", osszeg);

            break;
        }
        case 4: {
            for (int it = 1; it <= 100; ++it) {
                if (it % 3 != 0 && it % 5 != 0) {
                    printf("%d ", it);
                    fflush(stdout);
                }
            }

            break;
        }
        case 5: {
            printf("\nAdd meg, hogy hany fibonacci szamot akarsz kiirni: ");
            fflush(stdout);
            int n;
            scanf("%d", &n);

            fib(n);
            printf("\n");

            break;
        }
        case 6: {
            int szam;
            for (int i = 0; i < 2; ++i) {
                printf("Adj meg egy szamot: ");
                fflush(stdout);
                scanf("%d%*c", &szam);

                palindrome(szam) ? printf("Az altalad megadott szam %d palindrome.\n", szam) : printf("Az altalad megadott szam %d nem palindrome.\n", szam);
            }

            break;
        }
        case 7: {
            printf("Add meg hany szammal akarsz dolgozni: ");
            fflush(stdout);
        	int n;
        	scanf("%d", &n);

            int szam;
        	int oszthato3 = 0, oszthato5 = 0, oszthato15 = 0;
        	for (int i = 0; i < n; ++i) {
        		printf("Add meg az %d szamot: ", i + 1);
                fflush(stdout);
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
    }
}


int main() {
    // 1. feladat
    feladatok(1);
    printf("\n");

    // 2. feladat
    feladatok(2);
    printf("\n");

    // 3. feladat
    feladatok(3);
    printf("\n");

    // 4. feladat
    feladatok(4);
    printf("\n");

    // 5. feladat
    feladatok(5);
    printf("\n");

    // 6. feladat
    feladatok(6);
    printf("\n");

    // 7. feladat
    feladatok(7);

    return 0;
}
