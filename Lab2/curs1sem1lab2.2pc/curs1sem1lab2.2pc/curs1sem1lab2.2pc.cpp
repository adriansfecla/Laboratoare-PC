#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
    int n, i, numar, copie, k, suma, produs, cifra, prima, factorial, ultima, frecventa[10];
    char ch;

    // 1. Numere naturale 1..n
    printf("\nProblema 1: Afisarea numerelor naturale de la 1 la n\n");
    printf("Introduceti n: ");
    scanf("%d", &n);
    i = 1;
    while (i <= n) {
        printf("%d ", i);
        i++;
    }

    // 2. Numere invers n..1
    printf("\n\nProblema 2: Afisarea numerelor naturale de la n la 1\n");
    i = n;
    while (i >= 1) {
        printf("%d ", i);
        i--;
    }

    // 3. Alfabetul a..z
    printf("\n\nProblema 3: Alfabetul de la a la z\n");
    ch = 'a';
    while (ch <= 'z') {
        printf("%c ", ch);
        ch++;
    }

    // 4. Numere pare 1..100
    printf("\n\nProblema 4: Numere pare intre 1 si 100\n");
    i = 2;
    while (i <= 100) {
        printf("%d ", i);
        i += 2;
    }

    // 5. Numere impare 1..100
    printf("\n\nProblema 5: Numere impare intre 1 si 100\n");
    i = 1;
    while (i <= 100) {
        printf("%d ", i);
        i += 2;
    }

    // 6. Suma numerelor 1..n
    printf("\n\nProblema 6: Suma numerelor de la 1 la n\n");
    suma = 0;
    i = 1;
    while (i <= n) {
        suma += i;
        i++;
    }
    printf("Suma = %d\n", suma);

    // 7. Suma numerelor pare 1..n
    printf("\nProblema 7: Suma numerelor pare de la 1 la n\n");
    suma = 0;
    i = 2;
    while (i <= n) {
        suma += i;
        i += 2;
    }
    printf("Suma parelor = %d\n", suma);

    // 8. Suma numerelor impare 1..n
    printf("\nProblema 8: Suma numerelor impare de la 1 la n\n");
    suma = 0;
    i = 1;
    while (i <= n) {
        suma += i;
        i += 2;
    }
    printf("Suma imparelor = %d\n", suma);

    // 9. Tabel inmultire
    printf("\nProblema 9: Tabelul de inmultire\n");
    printf("Introduceti un numar: ");
    scanf("%d", &numar);
    i = 1;
    while (i <= 10) {
        printf("%d x %d = %d\n", numar, i, numar * i);
        i++;
    }

    // 10. Numar de cifre
    printf("\nProblema 10: Numarul de cifre ale unui numar\n");
    printf("Introduceti numarul: ");
    scanf("%d", &numar);
    copie = numar;
    int count = 0;
    while (copie != 0) {
        count++;
        copie /= 10;
    }
    printf("Numarul are %d cifre\n", count);

    // 11. Prima si ultima cifra
    printf("\nProblema 11: Prima si ultima cifra\n");
    ultima = numar % 10;
    copie = numar;
    while (copie >= 10) copie /= 10;
    prima = copie;
    printf("Prima cifra = %d, Ultima cifra = %d\n", prima, ultima);

    // 12. Suma primei si ultimei cifre
    printf("\nProblema 12: Suma primei si ultimei cifre\n");
    printf("Suma = %d\n", prima + ultima);

    // 13. Schimbarea primei si ultimei cifre
    printf("\nProblema 13: Schimbarea primei si ultimei cifre\n");
    int putere = 1;
    copie = numar;
    while (copie >= 10) {
        copie /= 10;
        putere *= 10;
    }
    prima = copie;
    ultima = numar % 10;
    int mijloc = (numar % putere) / 10;
    int nou = ultima * putere + mijloc * 10 + prima;
    printf("Numarul nou: %d\n", nou);

    // 14. Suma cifrelor
    printf("\nProblema 14: Suma cifrelor numarului\n");
    suma = 0;
    copie = numar;
    while (copie != 0) {
        suma += copie % 10;
        copie /= 10;
    }
    printf("Suma cifrelor = %d\n", suma);

    // 15. Produsul cifrelor
    printf("\nProblema 15: Produsul cifrelor numarului\n");
    produs = 1;
    copie = numar;
    while (copie != 0) {
        produs *= copie % 10;
        copie /= 10;
    }
    printf("Produsul cifrelor = %d\n", produs);

    // 16. Inversul numarului
    printf("\nProblema 16: Inversul numarului\n");
    k = 0;
    copie = numar;
    while (copie != 0) {
        k = k * 10 + copie % 10;
        copie /= 10;
    }
    printf("Numarul inversat este %d\n", k);

    // 17. Palindrom sau nu
    printf("\nProblema 17: Verificare palindrom\n");
    if (k == numar) printf("Numarul este palindrom\n");
    else printf("Numarul nu este palindrom\n");

    // 18. Frecventa cifrelor
    printf("\nProblema 18: Frecventa fiecarei cifre\n");
    for (i = 0; i < 10; i++) frecventa[i] = 0;
    copie = numar;
    while (copie != 0) {
        frecventa[copie % 10]++;
        copie /= 10;
    }
    for (i = 0; i < 10; i++) {
        if (frecventa[i] > 0)
            printf("Cifra %d apare de %d ori\n", i, frecventa[i]);
    }

    // 22. Factorii unui numar
    printf("\nProblema 22: Factorii unui numar\n");
    printf("Introduceti un numar: ");
    scanf("%d", &numar);
    printf("Factorii lui %d sunt: ", numar);
    i = 1;
    while (i <= numar) {
        if (numar % i == 0)
            printf("%d ", i);
        i++;
    }
    printf("\n");

    // 23. Factorial
    printf("\nProblema 23: Factorialul unui numar\n");
    printf("Introduceti un numar: ");
    scanf("%d", &numar);
    factorial = 1;
    for (int i = 1; i <= numar; i++)
        factorial *= i;
    printf("Factorial = %d \n", factorial);

    // 26. Numar prim
    printf("\nProblema 26: Verificare numar prim\n");
    printf("Introduceti un numar: ");
    scanf("%d", &numar);
    int S = 0;
    for (int i = 1; i <= numar; i++)
        if (numar % i == 0) S++;

    if (S == 2) printf("Numarul este prim\n");
    else printf("Numarul nu este prim\n");

    return 0;
}
