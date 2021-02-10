#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*char a='a';
    int n=25;
    while (n!=0) {
        a++;
        n--;
    }

    printf ("%c", a);*/

    /*int a;
    int db=0;
    scanf ("%d", a);
     while (a!=0) {
        db++;
        scanf ("%d", a);
    }
    printf ("%d", db);*/

    /*4. feladat
    int i, a=1;
    for (i=1;i<101;i++){
        if (a%3!=0) {
            if (a%5!=0) {
                printf ("%d ", a);
            }
        }
        a++;
    } */

    /*5.feladat
    int a, b, c, i;
    a=1;
    b=1;
    printf ("%d %d ", a, b);
    for (i=0;i<13;i++) {
        c=a+b;
        printf ("%d ", c);
        a=b;
        b=c;
    } */
    //6.feladat
    int a, b, c, d, e, f;
    c=0;
    f=0;
    scanf ("%d %d", &a, &d);
    b=a;
    e=d;
    while (a!=0) {
        c=c*10+a%10;
        a=a/10;
    }
    while (d!=0) {
        f=f*10+d%10;
        d=d/10;
    }
    if (b==c) printf ("A szam palindrom \n");
    else printf ("A szam nem palindrom \n");
    /* 7. feladat
    int n, a, db3=0, db5=0, db15=0;
    scanf ("%i ", &n);
    while (n>0) {
        scanf ("%i ", a);
        if (a%3==0) {
            db3++;
            if (a%5==0) {
                db5++;
                db15++;
            }
        }
        else if (a%5==0) {
            db5++;
        }
        n--;
    } */
}
