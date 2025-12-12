#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c, an;

    printf("Problemele 1-5: Introduceti trei numere: ");
    scanf("%d %d %d", &a, &b, &c);

    // 1. Maximul dintre 2 numere
    printf("\nProblema 1: Maximul dintre doua numere\n");
    if (a > b) printf("Primul numar este mai mare ca al doilea\n");
    else printf("Al doilea numar este mai mare ca primul\n");

    // 2. Maximul dintre 3 numere
    printf("\nProblema 2: Maximul dintre trei numere\n");
    if (a > b && a > c) printf("Primul numar este cel mai mare\n");
    else if (b > a && b > c) printf("Al doilea numar este cel mai mare\n");
    else printf("Al treilea numar este cel mai mare\n");

    // 3. Semnul numarului
    printf("\nProblema 3: Semnul primului numar\n");
    if (a > 0) printf("Numar pozitiv\n");
    else if (a < 0) printf("Numar negativ\n");
    else printf("Numar nul\n");

    // 4. Divizibil cu 5 si 11
    printf("\nProblema 4: Divizibilitate cu 5 si 11\n");
    if (a % 5 == 0 && a % 11 == 0)
        printf("Este divizibil si cu 5 si cu 11\n");
    else
        printf("Nu este divizibil si cu 5 si cu 11\n");

    // 5. Par sau impar
    printf("\nProblema 5: Par sau impar\n");
    if (a % 2 == 0) printf("Par\n");
    else printf("Impar\n");

    // 6. An bisect
    printf("\nProblema 6: An bisect\nIntroduceti un an: ");
    scanf("%d", &an);
    if (an % 4 == 0) printf("Anul este bisect\n");
    else printf("Anul nu este bisect\n");

    // 7. Caracter alfabet sau nu
    char caracter;
    printf("\nProblema 7: Caracter alfabet sau nu\nTastati un caracter: ");
    scanf(" %c", &caracter);
    if ((caracter >= 'A' && caracter <= 'Z') || (caracter >= 'a' && caracter <= 'z'))
        printf("Este o litera din alfabet\n");
    else
        printf("Nu este o litera din alfabet\n");

    // 9. Caracter: litera, cifra sau special
    printf("\nProblema 9: Litera, cifra sau caracter special\n");
    if ((caracter >= 'A' && caracter <= 'Z') || (caracter >= 'a' && caracter <= 'z'))
        printf("Litera\n");
    else if (caracter >= '0' && caracter <= '9')
        printf("Cifra\n");
    else
        printf("Caracter special\n");

    // 8. Vocala sau consoana
    char litera;
    printf("\nProblema 8: Vocala sau consoana\nTastati o litera: ");
    scanf(" %c", &litera);
    if (litera == 'a' || litera == 'e' || litera == 'i' || litera == 'o' || litera == 'u' ||
        litera == 'A' || litera == 'E' || litera == 'I' || litera == 'O' || litera == 'U')
        printf("Vocala\n");
    else
        printf("Consoana\n");

    // 10. Majuscula sau minuscula
    printf("\nProblema 10: Majuscula sau minuscula\n");
    if (litera >= 'A' && litera <= 'Z')
        printf("Majuscula\n");
    else
        printf("Minuscula\n");

    // 11. Ziua saptamanii
    int zi;
    printf("\nProblema 11: Zi a saptamanii\nIntroduceti numarul zilei (1-7): ");
    scanf("%d", &zi);
    switch (zi) {
    case 1: printf("Luni\n"); break;
    case 2: printf("Marti\n"); break;
    case 3: printf("Miercuri\n"); break;
    case 4: printf("Joi\n"); break;
    case 5: printf("Vineri\n"); break;
    case 6: printf("Sambata\n"); break;
    case 7: printf("Duminica\n"); break;
    default: printf("Zi invalida\n");
    }

    // 12. Zile luna
    int luna;
    printf("\nProblema 12: Zilele lunii\nIntroduceti numarul lunii (1-12): ");
    scanf("%d", &luna);
    switch (luna) {
    case 1:case 3:case 5:case 7:case 8:case 10:case 12:
        printf("31 zile\n"); break;
    case 4:case 6:case 9:case 11:
        printf("30 zile\n"); break;
    case 2:
        if (an % 4 == 0) printf("29 zile (an bisect)\n");
        else printf("28 zile\n");
        break;
    default: printf("Luna invalida\n");
    }

    // 14. Unghiurile triunghiului
    int u1, u2, u3;
    printf("\nProblema 14: Unghiurile unui triunghi\nIntroduceti 3 unghiuri: ");
    scanf("%d %d %d", &u1, &u2, &u3);
    if (u1 + u2 + u3 == 180 && u1 > 0 && u2 > 0 && u3 > 0)
        printf("Triunghi valid\n");
    else
        printf("Triunghi invalid\n");

    // 15 + 16. Laturile si tipul triunghiului
    int l1, l2, l3;
    printf("\nProblema 15 si 16: Triunghi dupa laturi\nIntroduceti 3 laturi: ");
    scanf("%d %d %d", &l1, &l2, &l3);
    if (l1 + l2 > l3 && l1 + l3 > l2 && l2 + l3 > l1) {
        printf("Triunghi valid\n");
        if (l1 == l2 && l2 == l3) printf("Echilateral\n");
        else if (l1 == l2 || l1 == l3 || l2 == l3) printf("Isoscel\n");
        else printf("Scalen\n");
    }
    else printf("Triunghi invalid\n");

    // 17. Ecuatia patratica
    double A, B, C, delta, x1, x2;
    printf("\nProblema 17: Ecuatia de gradul 2\nIntroduceti A B C: ");
    scanf("%lf %lf %lf", &A, &B, &C);

    if (A == 0) {
        if (B == 0) printf("Nu este ecuatie valida\n");
        else printf("Ecuatie liniara: x = %lf\n", -C / B);
    }
    else {
        delta = B * B - 4 * A * C;
        if (delta > 0) {
            x1 = (-B + sqrt(delta)) / (2 * A);
            x2 = (-B - sqrt(delta)) / (2 * A);
            printf("Radacini reale distincte: x1=%lf x2=%lf\n", x1, x2);
        }
        else if (delta == 0) {
            x1 = -B / (2 * A);
            printf("Radacina dubla: x=%lf\n", x1);
        }
        else printf("Nu exista solutii reale\n");
    }

    return 0;
}