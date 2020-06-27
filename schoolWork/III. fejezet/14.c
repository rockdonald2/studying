#include <stdio.h>
#include <stdlib.h>

typedef struct Pont {
    int p_x;
    int p_y;
} Pont;

int pozicio(const Pont *p) {
    if (p->p_x > 0) {
        if (p->p_y > 0) return 1;
        else return 4;
    } else {
        if (p->p_y > 0) return 2;
        else return 3;
    }

    return -1;
}

int main(void) {
    Pont p1 = { .p_x = 2, .p_y = -4};
    printf("A pont a kovetkezo negyedben van: %d", pozicio(&p1));

    return 0;
}
