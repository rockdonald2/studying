#include <stdio.h>

void szamologep() {
    double a, b;
    printf("Add meg a ket tetszoleges egesz szamot: ");
    scanf("%lf %lf%*c", &a, &b);

    char oper;
    while (oper != '+' && oper != '-' && oper != '*' && oper != '/' && oper != '%') {
        printf("Add meg a kovetkezo muveletek egyiket +, -, *, /, %%: ");
        scanf("%c%*c", &oper);
    }

    // printf("%.2lf %c %.2lf", a, oper, b);

    double eredmeny = 0;
    switch(oper) {
        case '*' : eredmeny = a * b; break;
    }

    printf("%lf %c %lf = %lf", a, oper, b, eredmeny);
}

int main() {
    szamologep();

    return 0;
}
