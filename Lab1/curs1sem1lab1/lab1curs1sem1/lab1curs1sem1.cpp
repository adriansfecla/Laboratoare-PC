#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char c;
    int a;
    short s;
    long int l;
    unsigned int u;
    float f;
    double d;

    printf("valoarea pentru c:");
    scanf("%c", &c);
    printf("valoarea pentru a:");
    scanf("%d", &a);
    printf("valoarea pentru s:");
    scanf("%hd", &s);
    printf("valoarea pentru l:");
    scanf("%ld", &l);
    printf("valoarea pentru u:");
    scanf("%u", &u);
    printf("valoarea pentru f:");
    scanf("%f", &f);
    printf("valoarea pentru d:");
    scanf("%lf", &d);
    printf("\n");


    printf("a + u = %d\n", a + u);
    printf("a - s = %d\n", a - s);
    printf("a * 3 = %d\n", a * 3);
    printf("a / 3 = %d\n", a / 3);
    printf("a %% 3 = %d\n", a % 3);
    a++;
    printf("a++ = %d\n", a);
    a--;
    printf("a-- = %d\n", a);
    printf("sqrt(16) = %f\n", sqrt(16));
    printf("log(10) = %f\n", log(10));
    printf("pow(2, 8) = %f\n", pow(2, 8));
    printf("abs(s) = %d\n", abs(s));
    printf("sin(d) = %f\n", sin(d));
    printf("log(d) = %f\n", log(d));
    printf("a > 5 = %d\n", a > 0);
    printf("a < 5 = %d\n", a < 0);
    printf("a == 10 = %d\n", a == 10);
    printf("a != 10 = %d\n", a != 10);
    printf("(a > 5 && u < 30) = %d\n", (a > 5 && u < 30));
    printf("(a < 5 || s < 0) = %d\n", (a < 5 || s < 0));
    printf("char c = %c\n", c);
    printf("float f = %f\n", f);
    printf("double d = %lf\n", d);
    printf("long int l = %ld\n", l);
    printf("unsigned int u = %u\n", u);
    printf("short s = %hd\n", s);

    return 0;
}
