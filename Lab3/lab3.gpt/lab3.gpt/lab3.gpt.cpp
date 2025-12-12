#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int n, m;
    printf("Introduceti numarul de linii n: ");
    scanf("%d", &n);
    printf("Introduceti numarul de coloane m: ");
    scanf("%d", &m);

    int a[100][100]; // presupunem n,m <= 100
    printf("Introduceti elementele matricei:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // 1. Num?r?m elementele negative pe fiecare coloan?
    int neg[100];
    for (int j = 0; j < m; j++) {
        neg[j] = 0;
        for (int i = 0; i < n; i++) {
            if (a[i][j] < 0)
                neg[j]++;
        }
    }

    // 2. Sort?m coloanele dup? neg[j] (bubble sort)
    for (int x = 0; x < m - 1; x++) {
        for (int y = x + 1; y < m; y++) {
            if (neg[x] > neg[y]) {
                // schimb?m neg[x] cu neg[y]
                int temp = neg[x];
                neg[x] = neg[y];
                neg[y] = temp;

                // schimb?m coloanele x ?i y în matrice
                for (int i = 0; i < n; i++) {
                    int t = a[i][x];
                    a[i][x] = a[i][y];
                    a[i][y] = t;
                }
            }
        }
    }

    // 3. Afi??m matricea rezultat?
    printf("\nMatricea dupa ordonarea coloanelor:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}