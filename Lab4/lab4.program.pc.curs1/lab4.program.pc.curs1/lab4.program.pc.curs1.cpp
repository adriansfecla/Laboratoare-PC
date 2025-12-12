#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 20

// afișează o matrice r x c
void printMat(int mat[MAX][MAX], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++)
            printf("%6d", mat[i][j]);
        printf("\n");
    }
}

// copie matrice
void copyMat(int src[MAX][MAX], int dst[MAX][MAX], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) for (j = 0; j < c; j++) dst[i][j] = src[i][j];
}

// calculează minorul: exclude row 0 and col 'col' pentru matrice n x n
void getMinor(int mat[MAX][MAX], int minor[MAX][MAX], int n, int col) {
    int i, j, r = 0, c = 0;
    for (i = 1; i < n; i++) {
        c = 0;
        for (j = 0; j < n; j++) {
            if (j == col) continue;
            minor[r][c] = mat[i][j];
            c++;
        }
        r++;
    }
}

// determinant recursiv (int). Atenție overflow pentru n mari.
int determinant(int mat[MAX][MAX], int n) {
    if (n == 1) return mat[0][0];
    if (n == 2) return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    int det = 0;
    int sign = 1;
    int minor[MAX][MAX];
    int col;
    for (col = 0; col < n; col++) {
        getMinor(mat, minor, n, col);
        det += sign * mat[0][col] * determinant(minor, n - 1);
        sign = -sign;
    }
    return det;
}

// rotire 90 deg dreapta (clockwise), rezultatul în dst (dst dimensiune = c x r)
void rotateRight(int src[MAX][MAX], int dst[MAX][MAX], int r, int c) {
    int i, j;
    for (i = 0; i < c; i++)
        for (j = 0; j < r; j++)
            dst[i][j] = src[r - 1 - j][i];
}

// rotire 90 deg stânga (counterclockwise)
void rotateLeft(int src[MAX][MAX], int dst[MAX][MAX], int r, int c) {
    int i, j;
    for (i = 0; i < c; i++)
        for (j = 0; j < r; j++)
            dst[i][j] = src[j][c - 1 - i];
}

// shift rows up circular cu 1
void shiftUp(int mat[MAX][MAX], int r, int c) {
    if (r <= 1) return;
    int first[MAX];
    int j;
    for (j = 0; j < c; j++) first[j] = mat[0][j];
    int i;
    for (i = 0; i < r - 1; i++)
        for (j = 0; j < c; j++) mat[i][j] = mat[i + 1][j];
    for (j = 0; j < c; j++) mat[r - 1][j] = first[j];
}

// shift rows down circular cu 1
void shiftDown(int mat[MAX][MAX], int r, int c) {
    if (r <= 1) return;
    int last[MAX];
    int j;
    for (j = 0; j < c; j++) last[j] = mat[r - 1][j];
    int i;
    for (i = r - 1; i > 0; i--)
        for (j = 0; j < c; j++) mat[i][j] = mat[i - 1][j];
    for (j = 0; j < c; j++) mat[0][j] = last[j];
}

// pooling 2x2 non-overlapping -> max
void maxPooling2x2(int src[MAX][MAX], int r, int c, int dst[MAX][MAX], int* rr, int* cc) {
    int i, j, ii, jj;
    int nr = r / 2, nc = c / 2;
    *rr = nr; *cc = nc;
    for (i = 0; i < nr; i++) for (j = 0; j < nc; j++) {
        int r0 = 2 * i, c0 = 2 * j;
        int m = src[r0][c0];
        for (ii = 0; ii < 2; ii++) for (jj = 0; jj < 2; jj++) {
            int val = src[r0 + ii][c0 + jj];
            if (val > m) m = val;
        }
        dst[i][j] = m;
    }
}

// pooling 2x2 non-overlapping -> average (int)
void avgPooling2x2(int src[MAX][MAX], int r, int c, int dst[MAX][MAX], int* rr, int* cc) {
    int i, j, ii, jj;
    int nr = r / 2, nc = c / 2;
    *rr = nr; *cc = nc;
    for (i = 0; i < nr; i++) for (j = 0; j < nc; j++) {
        int r0 = 2 * i, c0 = 2 * j;
        int sum = 0;
        for (ii = 0; ii < 2; ii++) for (jj = 0; jj < 2; jj++) sum += src[r0 + ii][c0 + jj];
        dst[i][j] = sum / 4; // integer average
    }
}

// fill matrix in spiral order from sorted array values[]
void fillSpiral(int mat[MAX][MAX], int r, int c, int values[], int total) {
    int top = 0, bottom = r - 1, left = 0, right = c - 1;
    int idx = 0;
    while (top <= bottom && left <= right && idx < total) {
        int j;
        for (j = left; j <= right && idx < total; j++) mat[top][j] = values[idx++];
        top++;
        for (j = top; j <= bottom && idx < total; j++) mat[j][right] = values[idx++];
        right--;
        if (top <= bottom) {
            for (j = right; j >= left && idx < total; j--) mat[bottom][j] = values[idx++];
            bottom--;
        }
        if (left <= right) {
            for (j = bottom; j >= top && idx < total; j--) mat[j][left] = values[idx++];
            left++;
        }
    }
}

// extrage toate elementele într-un vector
void flatten(int mat[MAX][MAX], int r, int c, int arr[]) {
    int idx = 0, i, j;
    for (i = 0; i < r; i++) for (j = 0; j < c; j++) arr[idx++] = mat[i][j];
}

// sortare simplă (qsort poate fi folosit, dar folosim bubble pentru claritate)
void sortArray(int arr[], int n) {
    int i, j, tmp;
    for (i = 0; i < n - 1; i++) for (j = 0; j < n - 1 - i; j++) if (arr[j] > arr[j + 1]) { tmp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = tmp; }
}


int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX], T[MAX][MAX];
    int r, c;
    int i, j, k;

    printf("Introdu dimensiunea matricei A (randuri coloane) (max %d): ", MAX);
    scanf("%d %d", &r, &c);
    if (r <= 0 || r > MAX || c <= 0 || c > MAX) { printf("Dimensiuni invalide\n"); return 0; }

    printf("Introdu elementele matricei A (linie cu linie):\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &A[i][j]);

    // 1. Adunarea a doua matrice (A + B)
    printf("\n1. Adunarea a doua matrice (A + B)\n");
    printf("Introdu dimensiunea matricei B (trebuie sa fie %dx%d): ", r, c);
    int r2, c2;
    scanf("%d %d", &r2, &c2);
    if (r2 != r || c2 != c) { printf("Dimensiuni incompatibile pentru adunare\n"); }
    else {
        printf("Introdu elementele matricei B:\n");
        for (i = 0; i < r; i++) for (j = 0; j < c; j++) scanf("%d", &B[i][j]);
        printf("A + B =\n");
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) printf("%6d", A[i][j] + B[i][j]);
            printf("\n");
        }
    }

    // 2. Scaderea a doua matrice (A - B)
    printf("\n2. Scaderea a doua matrice (A - B)\n");
    if (r2 != r || c2 != c) { printf("Dimensiuni incompatibile pentru scadere\n"); }
    else {
        printf("A - B =\n");
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) printf("%6d", A[i][j] - B[i][j]);
            printf("\n");
        }
    }

    // 3. Multiplicarea matricei cu un scalar
    printf("\n3. Multiplicarea matricei A cu un scalar\n");
    int scalar;
    printf("Introdu scalarul: ");
    scanf("%d", &scalar);
    printf("Scalar * A =\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) printf("%6d", scalar * A[i][j]);
        printf("\n");
    }

    // 4. Multiplicarea a doua matrice (A * B)
    printf("\n4. Multiplicarea a doua matrice (A * B)\n");
    int p;
    printf("Introdu numarul de coloane p pentru matricea B (B trebuie sa aiba %d coloane si %d randuri): ", c, c);
    scanf("%d", &p);
    if (r2 != c) {
        // cerem B acum cu r2==c
        printf("Notă: pentru A*B trebuie ca numarul de randuri al lui B sa fie %d. Cititi B cu %d randuri si %d coloane.\n", c, c, p);
        // citim B cu dimensiunile c x p
        for (i = 0; i < c; i++) for (j = 0; j < p; j++) { printf("B[%d][%d] = ", i, j); scanf("%d", &B[i][j]); }
    }
    else {
        // r2 == c; dar p poate fi citit; cerem B cu r2 x p
        for (i = 0; i < r2; i++) for (j = 0; j < p; j++) { printf("B[%d][%d] = ", i, j); scanf("%d", &B[i][j]); }
    }

    for (i = 0; i < r; i++) for (j = 0; j < p; j++) { C[i][j] = 0; for (k = 0; k < c; k++) C[i][j] += A[i][k] * B[k][j]; }
    printf("A * B =\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < p; j++) printf("%8d", C[i][j]);
        printf("\n");
    }

    // 5. Verificare daca doua matrice sunt egale
    printf("\n5. Verificare daca A si B (citita mai sus) sunt egale\n");
    int equal = 1;
    if (r2 != r || c2 != c) equal = 0;
    else {
        for (i = 0; i < r; i++) for (j = 0; j < c; j++) if (A[i][j] != B[i][j]) equal = 0;
    }
    if (equal) printf("Matricele sunt egale\n"); else printf("Matricele NU sunt egale\n");

    // 6. Suma elementelor diagonalei principale
    printf("\n6. Suma elementelor diagonalei principale (daca A este patratica)\n");
    if (r != c) printf("Matricea nu e patratica\n");
    else {
        int s = 0;
        for (i = 0; i < r; i++) s += A[i][i];
        printf("Suma diag principala = %d\n", s);
    }

    // 7. Suma elementelor diagonalei secundare
    printf("\n7. Suma elementelor diagonalei secundare (daca A este patratica)\n");
    if (r != c) printf("Matricea nu e patratica\n");
    else {
        int s = 0;
        for (i = 0; i < r; i++) s += A[i][r - 1 - i];
        printf("Suma diag secundara = %d\n", s);
    }

    // 8. Suma fiecarui rand si fiecarei coloane
    printf("\n8. Suma fiecarui rand si fiecarei coloane\n");
    int sumRow[MAX], sumCol[MAX];
    for (i = 0; i < r; i++) { sumRow[i] = 0; for (j = 0; j < c; j++) sumRow[i] += A[i][j]; }
    for (j = 0; j < c; j++) { sumCol[j] = 0; for (i = 0; i < r; i++) sumCol[j] += A[i][j]; }
    printf("Sume randuri:\n");
    for (i = 0; i < r; i++) printf("Row %d: %d\n", i, sumRow[i]);
    printf("Sume coloane:\n");
    for (j = 0; j < c; j++) printf("Col %d: %d\n", j, sumCol[j]);

    // 9. Schimbarea diagonalelor principale si secundare (doar patratica)
    printf("\n9. Schimbarea diagonalelor (main <-> secondary) daca A este patratica\n");
    if (r != c) printf("Matricea nu e patratica\n");
    else {
        for (i = 0; i < r; i++) {
            int tmp = A[i][i];
            A[i][i] = A[i][r - 1 - i];
            A[i][r - 1 - i] = tmp;
        }
        printf("Dupa interschimbare diagonale:\n"); printMat(A, r, c);
    }

    // 10. Matrice triunghiulara superioara (obtinere)
    printf("\n10. Matrice triunghiulara superioara (A -> Tsu)\n");
    int Tsu[MAX][MAX];
    for (i = 0; i < r; i++) for (j = 0; j < c; j++) {
        if (i <= j) Tsu[i][j] = A[i][j];
        else Tsu[i][j] = 0;
    }
    printMat(Tsu, r, c);

    // 11. Matrice triunghiulara inferioara
    printf("\n11. Matrice triunghiulara inferioara (A -> Tinf)\n");
    int Tinf[MAX][MAX];
    for (i = 0; i < r; i++) for (j = 0; j < c; j++) {
        if (i >= j) Tinf[i][j] = A[i][j];
        else Tinf[i][j] = 0;
    }
    printMat(Tinf, r, c);

    // 12. Suma matrice triunghiulara superioara
    printf("\n12. Suma elementelor tronsonului superior\n");
    long long ssu = 0;
    for (i = 0; i < r; i++) for (j = 0; j < c; j++) if (i <= j) ssu += Tsu[i][j];
    printf("Suma triunghiulara superioara = %lld\n", ssu);

    // 13. Suma matrice triunghiulara inferioara
    printf("\n13. Suma elementelor tronsonului inferior\n");
    long long sinf = 0;
    for (i = 0; i < r; i++) for (j = 0; j < c; j++) if (i >= j) sinf += Tinf[i][j];
    printf("Suma triunghiulara inferioara = %lld\n", sinf);

    // 14. Transpunerea unei matrice
    printf("\n14. Transpunerea matricei A\n");
    int At[MAX][MAX];
    for (i = 0; i < r; i++) for (j = 0; j < c; j++) At[j][i] = A[i][j];
    printf("A transpus (dim %dx%d):\n", c, r); printMat(At, c, r);

    // 15. Determinantul (doar daca patratica)
    printf("\n15. Determinantul matricei A\n");
    if (r != c) printf("Matricea nu e patratica\n");
    else {
        // facem o copie in T si apelam determinant
        int tmpMat[MAX][MAX];
        for (i = 0; i < r; i++) for (j = 0; j < r; j++) tmpMat[i][j] = A[i][j];
        int det = determinant(tmpMat, r);
        printf("Determinant = %d\n", det);
    }

    // 16. Verificare daca matricea este unitara
    printf("\n16. Verificare daca A este matrice identitate\n");
    int isIdentity = 1;
    if (r != c) isIdentity = 0;
    else {
        for (i = 0; i < r; i++) for (j = 0; j < c; j++) {
            if (i == j) { if (A[i][j] != 1) isIdentity = 0; }
            else { if (A[i][j] != 0) isIdentity = 0; }
        }
    }
    if (isIdentity) printf("Matricea este identitate\n"); else printf("Matricea NU este identitate\n");

    // 17. Verificare matrice rarefiata (sparse) - >= 70% zerouri
    printf("\n17. Verificare daca A este rarefiata (>=70%% zerouri)\n");
    int zeros = 0;
    for (i = 0; i < r; i++) for (j = 0; j < c; j++) if (A[i][j] == 0) zeros++;
    int total = r * c;
    double perc = (100.0 * zeros) / total;
    printf("Zerouri: %d / %d (%.2f%%)\n", zeros, total, perc);
    if (perc >= 70.0) printf("Matricea este rarefiata\n"); else printf("Matricea NU este rarefiata\n");

    // 18. Verificare simetrie (A == A^T)
    printf("\n18. Verificare daca A este simetrica\n");
    int symmetric = 1;
    if (r != c) symmetric = 0;
    else {
        for (i = 0; i < r; i++) for (j = 0; j < c; j++) if (A[i][j] != A[j][i]) symmetric = 0;
    }
    if (symmetric) printf("Matricea este simetrica\n"); else printf("Matricea NU este simetrica\n");

    // 19. Rotire la stânga (90°)
    printf("\n19. Rotire la stanga (90°)\n");
    int R1[MAX][MAX];
    rotateLeft(A, R1, r, c);
    printf("Rezultat (dim %dx%d):\n", c, r); printMat(R1, c, r);

    // 20. Rotire la dreapta (90°)
    printf("\n20. Rotire la dreapta (90°)\n");
    int R2[MAX][MAX];
    rotateRight(A, R2, r, c);
    printf("Rezultat (dim %dx%d):\n", c, r); printMat(R2, c, r);

    // 21. Rotire in sus (shift rows up)
    printf("\n21. Rotire in sus (shift rows up circular o pozitie)\n");
    int copyA[MAX][MAX];
    copyMat(A, copyA, r, c);
    shiftUp(copyA, r, c);
    printMat(copyA, r, c);

    // 22. Rotire in jos (circular o pozitie)
    // 22. Rotire in jos (circular o pozitie)
    printf("\n22. Rotire in jos (shift rows down circular o pozitie)\n");
    copyMat(A, copyA, r, c);
    shiftDown(copyA, r, c);
    printMat(copyA, r, c);

    // 23. Max-Pooling 2x2
    printf("\n23. Max-Pooling 2x2 (non-overlapping)\n");
    int Pm[MAX][MAX]; int pr, pc;
    if (r < 2 || c < 2) printf("Dimensiuni prea mici pentru pooling 2x2\n");
    else {
        maxPooling2x2(A, r, c, Pm, &pr, &pc);
        printf("Rezultat dim %dx%d:\n", pr, pc);
        printMat(Pm, pr, pc);
    }

    // 24. Average-Pooling 2x2
    printf("\n24. Average-Pooling 2x2 (non-overlapping)\n");
    int Pa[MAX][MAX]; int ar, ac;
    if (r < 2 || c < 2) printf("Dimensiuni prea mici pentru pooling 2x2\n");
    else {
        avgPooling2x2(A, r, c, Pa, &ar, &ac);
        printf("Rezultat dim %dx%d:\n", ar, ac);
        printMat(Pa, ar, ac);
    }

    // 25. Sortare elementelor matricii in spirală (extragem, sortam, reasamblam)
    printf("\n25. Sortare elementelor matricii in spirala (crescator)\n");
    int totalElems = r * c;
    int flat[MAX * MAX];
    flatten(A, r, c, flat);
    sortArray(flat, totalElems);
    int S[MAX][MAX];
    fillSpiral(S, r, c, flat, totalElems);
    printf("Matrice sortata in ordine spirala (plecand din coltul stanga-sus):\n");
    printMat(S, r, c);
    return 0;
}
