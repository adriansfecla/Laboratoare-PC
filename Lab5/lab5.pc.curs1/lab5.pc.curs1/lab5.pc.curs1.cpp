#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//1: Lungimea unui sir
int lungimeSir(char s[]) {
    return strlen(s);
}

//2: Copierea unui sir
void copiazaSir(char dest[], char src[]) {
    strcpy(dest, src);
}

//5: mici → mari
void miciLaMari(char s[]) {
    for (int i = 0; s[i] != '\0'; i++)
        s[i] = toupper(s[i]);
}

//9: numar vocale
int numaraVocale(char s[]) {
    int cnt = 0;
    char voc[] = "aeiouAEIOU";

    for (int i = 0; s[i] != '\0'; i++)
        if (strchr(voc, s[i])) cnt++;

    return cnt;
}

//12: inversare sir 
void inverseaza(char s[]) {
    int i = 0, j = strlen(s) - 1;
    while (i < j) {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
        i++; j--;
    }
}

//13: palindrom
int estePalindrom(char s[]) {
    int i = 0, j = strlen(s) - 1;
    while (i < j) {
        if (s[i] != s[j]) return 0;
        i++; j--;
    }
    return 1;
}

//15: prima aparitie caracter
int primaAparitie(char s[], char c) {
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == c) return i;
    return -1;
}

//24: elimina toate aparitiile 
void eliminaCaracter(char s[], char c) {
    int k = 0;
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[k++] = s[i];

    s[k] = '\0';
}

//38: sterge spatii inceput + sfarsit 
void trimSpaces(char s[]) {
    int start = 0, end = strlen(s) - 1;

    while (s[start] == ' ') start++;
    while (end >= 0 && s[end] == ' ') end--;

    int k = 0;
    for (int i = start; i <= end; i++)
        s[k++] = s[i];

    s[k] = '\0';
}

//40: sortare cuvinte
void sortareCuvinte(char s[]) {
    char cuv[50][50];
    int n = 0;

    char* p = strtok(s, " ");
    while (p != NULL) {
        strcpy(cuv[n++], p);
        p = strtok(NULL, " ");
    }

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(cuv[i], cuv[j]) > 0) {
                char aux[50];
                strcpy(aux, cuv[i]);
                strcpy(cuv[i], cuv[j]);
                strcpy(cuv[j], aux);
            }

    printf("\nCuvinte sortate alfabetically:\n");
    for (int i = 0; i < n; i++)
        printf("%s ", cuv[i]);
    printf("\n");
}

int main() {
    char s[200], s2[200], c;
    int opt;

    do {
        printf("\n                MENIU STRINGURI                \n");
        printf("1. Lungimea unui sir\n");
        printf("2. Copierea unui sir\n");
        printf("5. Convertire mici -> mari\n");
        printf("9. Numarul de vocale\n");
        printf("12. Inversarea sirului\n");
        printf("13. Verificare palindrom\n");
        printf("15. Prima aparitie a unui caracter\n");
        printf("24. Eliminarea tuturor aparitiilor unui caracter\n");
        printf("38. Stergerea spatiilor de la inceput si sfarsit\n");
        printf("40. Sortare cuvinte\n");
        printf("0. Iesire\n");
        printf("Alege optiunea: ");
        scanf("%d", &opt);
        getchar();

        switch (opt) {

        case 1:
            printf("Introdu sirul: ");
            fgets(s, 200, stdin); s[strcspn(s, "\n")] = 0;
            printf("Lungimea este: %d\n", lungimeSir(s));
            break;

        case 2:
            printf("Introdu sirul de copiat: ");
            fgets(s, 200, stdin); s[strcspn(s, "\n")] = 0;
            copiazaSir(s2, s);
            printf("Copia: %s\n", s2);
            break;

        case 5:
            printf("Introdu sirul: ");
            fgets(s, 200, stdin); s[strcspn(s, "\n")] = 0;
            miciLaMari(s);
            printf("Rezultat: %s\n", s);
            break;

        case 9:
            printf("Introdu sirul: ");
            fgets(s, 200, stdin); s[strcspn(s, "\n")] = 0;
            printf("Numar de vocale: %d\n", numaraVocale(s));
            break;

        case 12:
            printf("Introdu sirul: ");
            fgets(s, 200, stdin); s[strcspn(s, "\n")] = 0;
            inverseaza(s);
            printf("Inversat: %s\n", s);
            break;

        case 13:
            printf("Introdu sirul: ");
            fgets(s, 200, stdin); s[strcspn(s, "\n")] = 0;
            if (estePalindrom(s)) printf("Sirul este palindrom.\n");
            else printf("Sirul NU este palindrom.\n");
            break;

        case 15:
            printf("Introdu sirul: ");
            fgets(s, 200, stdin); s[strcspn(s, "\n")] = 0;
            printf("Introdu caracterul: ");
            scanf("%c", &c);
            int poz;
            poz = primaAparitie(s, c);

            if (poz == -1) printf("Caracterul nu apare.\n");
            else printf("Prima aparitie este la pozitia %d.\n", poz);
            break;

        case 24:
            printf("Introdu sirul: ");
            fgets(s, 200, stdin); s[strcspn(s, "\n")] = 0;
            printf("Caracterul de eliminat: ");
            scanf("%c", &c);
            eliminaCaracter(s, c);
            printf("Rezultat: %s\n", s);
            break;

        case 38:
            printf("Introdu sirul: ");
            fgets(s, 200, stdin); s[strcspn(s, "\n")] = 0;
            trimSpaces(s);
            printf("Rezultat: [%s]\n", s);
            break;

        case 40:
            printf("Introdu sirul: ");
            fgets(s, 200, stdin); s[strcspn(s, "\n")] = 0;
            sortareCuvinte(s);
            break;

        case 0:
            printf("Iesire...\n");
            break;

        default:
            printf("Optiune invalida!\n");
        }

    } while (opt != 0);

    return 0;
}
