#include <stdio.h>

void szamokBeolvasa(double *a, double *b) {
    printf("Add meg a ket tetszoleges egesz szamot: ");
    scanf("%lf %lf%*c", a, b);
}

void eredmenyKiirasa(double *a, double *b, char *oper, double *eredmeny) {
    printf("%.3lf %c %.3lf = %.3lf", *a, *oper, *b, *eredmeny);
}

void muveletKivalasztasa(char *oper, double *a, double *b) {
    while (*oper != '+' && *oper != '-' && *oper != '*' && *oper != '/' && *oper != '%') {
        printf("Add meg a kovetkezo muveletek egyiket +, -, *, /, %%: ");
        scanf("%c%*c", oper);

        if (*oper == '/' && *b == 0) {
            printf("A nullaval valo osztas ertelmetlen, %.3lf %c %.3lf ertelmetlen.\n", *a, *oper, *b);

            char dontes;
            while (dontes != 's' && dontes != 'm') {
                printf("Uj szamokat(s) akarsz vagy a muveletet(m) szeretned megvaltoztatni? ");
                scanf("%c%*c", &dontes);
            }

            if (dontes == 's') {
                szamokBeolvasa(a, b);
                *oper = ' ';
            } else if (dontes == 'm') {
                *oper = ' ';
            }
        }
    }
}

void szamologep() {
    double a, b;
    szamokBeolvasa(&a, &b);

    char oper;
    muveletKivalasztasa(&oper, &a, &b);

    double eredmeny = 0;
    switch(oper) {
        case '+' : eredmeny = a + b; break;
        case '-' : eredmeny = a - b; break;
        case '*' : eredmeny = a * b; break;
        case '/' : eredmeny = a / b; break;
        case '%' : eredmeny = (int)a % (int)b; break;
        default: eredmeny = -1;
    }

    eredmenyKiirasa(&a, &b, &oper, &eredmeny);
}

int main() {
    szamologep();

    return 0;
}
