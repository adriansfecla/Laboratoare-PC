#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define MAX 100

// ===================== FUNCȚII RECURSIVE =====================

// Afisare recursivă a elementelor
void afisareRec(int a[], int n, int i) {
    if (i < n) {
        printf("%d ", a[i]);
        afisareRec(a, n, i + 1);
    }
}

// Suma recursivă
int sumaRec(int a[], int n) {
    if (n == 0) return 0;
    return a[n - 1] + sumaRec(a, n - 1);
}

// Maxim recursiv
int maxRec(int a[], int n, int currMax) {
    if (n == 0) return currMax;
    if (a[n - 1] > currMax) currMax = a[n - 1];
    return maxRec(a, n - 1, currMax);
}

// Minim recursiv
int minRec(int a[], int n, int currMin) {
    if (n == 0) return currMin;
    if (a[n - 1] < currMin) currMin = a[n - 1];
    return minRec(a, n - 1, currMin);
}

// ===================== PROGRAM PRINCIPAL =====================

int main() {
    int a[MAX], b[MAX], c[MAX];
    int n, m, i, j;

    printf("Introdu numarul de elemente ale tabloului: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    // 1. Citirea și afișarea elementelor unui tablou (recursiv)
    printf("\n1. Elementele tabloului sunt: ");
    afisareRec(a, n, 0);

    // 2. Afișarea elementelor negative
    printf("\n2. Elementele negative: ");
    for (i = 0; i < n; i++)
        if (a[i] < 0) printf("%d ", a[i]);

    // 3. Suma elementelor (recursiv)
    printf("\n3. Suma elementelor = %d", sumaRec(a, n));

    // 4. Max și Min (recursiv)
    printf("\n4. Max = %d, Min = %d", maxRec(a, n, a[0]), minRec(a, n, a[0]));

    // 5. Al doilea cel mai mare element
    int max1 = a[0], max2 = a[0];
    for (i = 1; i < n; i++) {
        if (a[i] > max1) {
            max2 = max1;
            max1 = a[i];
        }
        else if (a[i] > max2 && a[i] != max1) {
            max2 = a[i];
        }
    }
    printf("\n5. Al doilea cel mai mare element = %d", max2);

    // 6. Număr elemente pare și impare
    int pare = 0, impare = 0;
    for (i = 0; i < n; i++) {
        if (a[i] % 2 == 0) pare++;
        else impare++;
    }
    printf("\n6. Pare = %d, Impare = %d", pare, impare);

    // 7. Număr elemente negative
    int neg = 0;
    for (i = 0; i < n; i++)
        if (a[i] < 0) neg++;
    printf("\n7. Nr. elemente negative = %d", neg);

    // 8. Copiere tablou
    for (i = 0; i < n; i++) b[i] = a[i];
    printf("\n8. Copie a tabloului: ");
    for (i = 0; i < n; i++) printf("%d ", b[i]);

    // 9. Inserare element pe poziție dată
    int val, pos;
    printf("\n\n9. Introdu valoarea si pozitia de inserat: ");
    scanf("%d %d", &val, &pos);
    for (i = n; i > pos; i--) a[i] = a[i - 1];
    a[pos] = val;
    n++;
    printf("Tablou dupa inserare: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);

    // 10. Ștergere element din poziție
    printf("\n\n10. Introdu pozitia de sters: ");
    scanf("%d", &pos);
    for (i = pos; i < n - 1; i++) a[i] = a[i + 1];
    n--;
    printf("Tablou dupa stergere: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);

    // 11. Frecvența fiecărui element
    int freq[MAX] = { 0 };
    printf("\n\n11. Frecventa fiecarui element:\n");
    for (i = 0; i < n; i++) freq[i] = -1;
    for (i = 0; i < n; i++) {
        int count = 1;
        for (j = i + 1; j < n; j++)
            if (a[i] == a[j]) {
                count++;
                freq[j] = 0;
            }
        if (freq[i] != 0) freq[i] = count;
    }
    for (i = 0; i < n; i++)
        if (freq[i] != 0)
            printf("%d apare de %d ori\n", a[i], freq[i]);

    // 12. Elemente unice
    printf("\n12. Elemente unice: ");
    for (i = 0; i < n; i++)
        if (freq[i] == 1) printf("%d ", a[i]);

    // 13. Număr elemente duplicate
    int duplic = 0;
    for (i = 0; i < n; i++)
        if (freq[i] > 1) duplic++;
    printf("\n13. Nr. elemente duplicate = %d", duplic);

    // 14. Ștergere elemente duplicate
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                for (int k = j; k < n - 1; k++)
                    a[k] = a[k + 1];
                n--;
                j--;
            }
        }
    }
    printf("\n14. Tablou fara duplicate: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);

    // 15. Îmbinare a doua tablouri
    printf("\n\n15. Introdu dimensiunea celui de-al doilea tablou: ");
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        printf("b[%d] = ", i);
        scanf("%d", &b[i]);
    }
    for (i = 0; i < n; i++) c[i] = a[i];
    for (j = 0; j < m; j++) c[n + j] = b[j];
    printf("Tablou rezultat: ");
    for (i = 0; i < n + m; i++) printf("%d ", c[i]);

    // 16. Inversarea tabloului
    printf("\n\n16. Tablou inversat: ");
    for (i = n - 1; i >= 0; i--) printf("%d ", a[i]);

    // 17. Separare pare și impare
    int ap[MAX], aim[MAX];
    int np = 0, ni = 0;
    for (i = 0; i < n; i++) {
        if (a[i] % 2 == 0) ap[np++] = a[i];
        else aim[ni++] = a[i];
    }
    printf("\n17. Elemente pare: ");
    for (i = 0; i < np; i++) printf("%d ", ap[i]);
    printf("\n Elemente impare: ");
    for (i = 0; i < ni; i++) printf("%d ", aim[i]);

    // 18. Căutare element
    printf("\n\n18. Introdu elementul de cautat: ");
    scanf("%d", &val);
    int gasit = 0;
    for (i = 0; i < n; i++)
        if (a[i] == val) {
            printf("Gasit la pozitia %d\n", i);
            gasit = 1;
        }
    if (!gasit) printf("Elementul nu exista in tablou.");

    // 19. Sortare crescător
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (a[i] > a[j]) {
                int aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
    printf("\n19. Sortat crescator: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);

    // 20. Sortare separată pare și impare
    for (i = 0; i < np - 1; i++)
        for (j = i + 1; j < np; j++)
            if (ap[i] > ap[j]) {
                int t = ap[i];
                ap[i] = ap[j];
                ap[j] = t;
            }
    for (i = 0; i < ni - 1; i++)
        for (j = i + 1; j < ni; j++)
            if (aim[i] > aim[j]) {
                int t = aim[i];
                aim[i] = aim[j];
                aim[j] = t;
            }
    printf("\n20. Pare sortate: ");
    for (i = 0; i < np; i++) printf("%d ", ap[i]);
    printf("\n Impare sortate: ");
    for (i = 0; i < ni; i++) printf("%d ", aim[i]);

    // 21. Rotire la stânga (ROL)
    int temp = a[0];
    for (i = 0; i < n - 1; i++) a[i] = a[i + 1];
    a[n - 1] = temp;
    printf("\n21. Rotire la stanga: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);

    // 22. Rotire la dreapta (ROR)
    temp = a[n - 1];
    for (i = n - 1; i > 0; i--) a[i] = a[i - 1];
    a[0] = temp;
    printf("\n22. Rotire la dreapta: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);

    printf("\n\nProgram finalizat.\n");
    return 0;
}


