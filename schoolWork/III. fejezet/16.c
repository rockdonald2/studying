#include <stdio.h>
#include <stdlib.h>

typedef struct Lista {
    int* l;
    size_t hossz;
} Lista;

Lista felbont(int szam) {
    int* felbontott = (int*)malloc(32 * sizeof(int));

    int maradek;
    size_t iterator = 0;
    while (szam > 0) {
        maradek = szam % 10;
        szam /= 10;

        felbontott[iterator++] = maradek;
    }

    Lista ll = { .l = felbontott, .hossz = iterator };

    return ll;
}

Lista rendez(Lista *ll) {
    int kulcs, j;
    for (int i = 1; i < ll->hossz; ++i) {
        kulcs = ll->l[i];
        j = i - 1;

        while (j >= 0 && ll->l[j] > kulcs) {
            ll->l[j + 1] = ll->l[j];
            --j;
        }

        ll->l[j + 1] = kulcs;
    }

    return *ll;
}

int keresElso(Lista *ll, int keresett) {
    int bal = 0, jobb = ll->hossz - 1, kozepso;

    while (bal < jobb) {
        kozepso = bal + (jobb - bal) / 2;

        if (ll->l[kozepso] >= keresett) jobb = kozepso;
        else bal = kozepso + 1;
    }

    return ll->l[bal] == keresett ? bal : -1;
}

int keresUtolso(Lista *ll, int keresett) {
    int bal = 0, jobb = ll->hossz - 1, kozepso;

    while (bal < jobb) {
        kozepso = bal + (jobb - bal) / 2 + 1;

        if (ll->l[kozepso] < keresett) bal = kozepso + 1;
        else if (ll->l[kozepso] > keresett) jobb = kozepso - 1;
        else bal = kozepso;
    }

    return ll->l[bal] == keresett ? bal : -1;
}

int* keres(Lista *ll, int keresett) {
    int *megoldas = (int*)malloc(2 * sizeof(int));
    megoldas[0] = -1;
    megoldas[1] = -1;

    if (ll->hossz == 0) {
        return megoldas;
    }

    int elsoIndex, utolsoIndex;

    elsoIndex = keresElso(ll, keresett);

    if (elsoIndex == -1) {
        return megoldas;
    }

    utolsoIndex = keresUtolso(ll, keresett);

    megoldas[0] = elsoIndex;
    megoldas[1] = utolsoIndex;

    return megoldas;
}

int keresSzamjegy(int szam, int keresettSZJ) {
    Lista vegso = felbont(szam);
    vegso = rendez(&vegso);

    int *indexek = keres(&vegso, keresettSZJ);

    return indexek[1] - indexek[0] + 1;
}

int main(void) {
    int szam;
    printf("Adj megy egy egesz szamot: ");
    scanf("%d", &szam);
    int keresettSZJ;
    printf("Add meg a keresett szamjegyet: ");
    scanf("%d", &keresettSZJ);

    printf("\nA %d szamjegy %d alkalommal fordul elo a %d-ben.\n", keresettSZJ, keresSzamjegy(szam, keresettSZJ), szam);

    return 0;
}
