#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    printf("Dati numarul de linii a tabloului bidimensional: ");
    scanf("%d", &n);
    printf("Dati numarul de coloane a tabloului bidimensional: ");
    scanf("%d", &m);

    int A[100][100];
    int C[100];

    for (int i = 1; i <= n; i++) {
        printf("Tastati linia %d: ", i);
        for (int j = 1; j <= m; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    for (int j = 1; j <= m; j++) {
        C[j] = 0;
        for (int i = 1; i <= n; i++) {
            if (A[i][j] < 0) {
                C[j]++;
            }
        }
    }

    for (int j = 1; j <= m - 1; j++) {
        for (int k = 1; k <= m - j; k++) {
            if (C[k] > C[k + 1]) {
                int tmpC = C[k];
                C[k] = C[k + 1];
                C[k + 1] = tmpC;

                for (int i = 1; i <=n; i++) {
                    int tmp = A[i][k];
                    A[i][k] = A[i][k + 1];
                    A[i][k + 1] = tmp;
                }
            }
        }
    }

    printf("\nMatricea sortata dupa numarul de elemente negative pe coloana:\n");
    for (int i = 1; i <=n; i++) {
        for (int j = 1; j <=m; j++) {
          if (A[i][j] <= 0) printf("%d ", A[i][j]);
          else printf(" %d ", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}
