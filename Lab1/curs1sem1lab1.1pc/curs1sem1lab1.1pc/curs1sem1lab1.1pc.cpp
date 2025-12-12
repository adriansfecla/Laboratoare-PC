#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main()
{
    int a, b, c, an;
    // 1;2;3;4;5
    printf("Dati valori pentru trei numere:");
    scanf("%d %d %d", &a, &b, &c);
    //maximul dintre 2 numere
    if (a > b) printf("\nPrimul numar este mai mare ca al doilea\n");
    else printf("\nAl doilea numar este mai mare ca primul\n");
    //maximul dintre 3 numere
    if (a > b && a > c) printf("\nPrimul numar este mai mare ca celelalte doua \n");
    else if (b > a && b > c) printf("\nAl doilea numar este mai mare ca celelalte doua\n");
    else if (c > b && c > a) printf("\nAl treilea numar este mai mare ca celelalte doua\n");
    //semnul numarului
    if (a > 0) printf("\nPrimul numar este pozitiv\n");
    else if (a < 0) printf("\nPrimul numar este negativ\n");
    else if (a == 0) printf("\nPrimul numar este nul\n");
    //divizibil cu 5 si 11 sau nu
    if (a % 5 == 0 && a % 11 == 0) printf("\nPrimul numar este divizibil si cu 5 si cu 11\n");
    else printf("\nPrimul numar nu este divizibil si cu 5 si cu 11\n");
    //par sau impar
    if (a % 2 == 0) printf("\nPrimul numar este par\n");
    else printf("\nPrimul numar este impar\n");


    // 6. an bisect sau nu
    printf("\nIntroduceti un an:");
    scanf("%d", &an);
    if (an % 4 == 0) printf("\nAnul este bisect\n");
    else printf("\nAnul nu este bisect\n");

    // 7.caracter alfabet sau nu
    char caracter;
    printf("\nTastati un caracter:");
    scanf(" %c", &caracter);
    if (int(caracter) >= 65 && int(caracter) <= 90 || int(caracter) >= 97 && int(caracter) <= 122) printf("\n Caracterul este o litera din alfabet");
    else printf("\nCaracterul nu este o litera din alfabet\n");

    // 9. alfabet, cifra sau caracter special
    if ((caracter >= 'A' && caracter <= 'Z') || (caracter >= 'a' && caracter <= 'z'))
        printf("\nCaracterul este litera\n");
    else if (caracter >= '0' && caracter <= '9')
        printf("\nCaracterul este cifra\n");
    else
        printf("\nCaracterul este caracter special\n");

    // 8. vocala sau consoana
    char litera;
    printf("\nTatstati o litera:\n");
    scanf(" %c", &litera);
        if (litera == 'a' || litera == 'e' || litera == 'i' || litera == 'o' || litera == 'u' || litera == 'A' || litera == 'E' || litera == 'I' || litera == 'O' || litera == 'U')
            printf("\nLitera este vocala\n");
        else
            printf("\nLitera este consoana\n");

    // 10. majuscule sau minuscule
        if (int(litera) >= 65 && (litera) <= 90)
        printf("\nLitera este majuscula\n");
    else
        printf("\nLitera este minuscula\n");

    // 11. numar saptamanii -> ziua
    int zi;
    printf("\nIntroduceti numarul zilei (1-7):");
    scanf("%d", &zi);
    switch (zi) {
    case 1: printf("Luni\n"); break;
    case 2: printf("Marti\n"); break;
    case 3: printf("Miercuri\n"); break;
    case 4: printf("Joi\n"); break;
    case 5: printf("Vineri\n"); break;
    case 6: printf("Sambata\n"); break;
    case 7: printf("Duminica\n"); break;
    }

    // 12. numar lunii -> zilele din luna
    int luna;
    printf("\nIntroduceti numarul lunii (1-12):");
    scanf("%d", &luna);
    switch (luna) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        printf("\nLuna are 31 de zile\n"); break;
    case 4: case 6: case 9: case 11:
        printf("\nLuna are 30 de zile\n"); break;
    case 2:
        if (an % 4 == 0)
            printf("\nLuna are 29 de zile(an bisect)\n");
        else
            printf("\nLune are 28 de zile\n");
        break;
    }

    // 14. unghiurile unui triunghi
    int unghi1, unghi2, unghi3;
    printf("\n Introduceti cele trei unghiuri ale triunghiului:");
    scanf("%d %d %d", &unghi1, &unghi2, &unghi3);
    if (unghi1 + unghi2 + unghi3 == 180 && unghi1 > 0 && unghi2 > 0 && unghi3 > 0)
        printf("\nTriunghi valid\n");
    else
        printf("\nTriunghi invalid\n");

    // 15. laturile unui triunghi
    int l1, l2, l3;
    printf("\n Introduceti cele trei laturi ale triunghiului: ");
    scanf("%d %d %d", &l1, &l2, &l3);
    if (l1 + l2 > l3 && l1 + l3 > l2 && l2 + l3 > l1)
        printf("\nTriunghi valid\n");
    else
        printf("\nTriunghi invalid\n");

    // 16. tipul triunghiului
    if (l1 == l2 && l2 == l3)
        printf("Triunghi echilateral\n");
    else if (l1 == l2 && l1 != l3 || l1 == l3 && l1 != l2 || l2 == l3 && l2 != l1)
        printf("Triunghi isoscel\n");
    else
        printf("Triunghi scalen\n");

    // 17. ecuatia patratica
    double A, B, C, delta, x1, x2;
    printf("\n Ecuatia este de forma Ax^2 + Bx + C = 0\n");
    printf("\n Introduceti coeficientii A, B si C: ");
    scanf("%lf %lf %lf", &A, &B, &C);

    if (A == 0) {
        if (B == 0) printf("\nNu este ecuatie valida.\n");
        else printf("\nEcuatie liniara, solutia este: x = %lf\n", -C / B);
    }
    else {
        delta = B * B - 4 * A * C;
        if (delta > 0) {
            x1 = (-B + sqrt(delta)) / (2 * A);
            x2 = (-B - sqrt(delta)) / (2 * A);
            printf("\nRadacini reale distincte: x1 = %lf , x2 = %lf\n", x1, x2);
        }
        else if (delta == 0) {
            x1 = -B / (2 * A);
            printf("\nRadacina dubla: x = %lf\n", x1);
        }
        else if(delta<0)
            printf("\nEcuatia nu are solutii\n");
    }

    return 0;
}