#include <stdio.h>
#include <stdlib.h>

void rotate(int **matrix, int n) {
    int i, j, k;
    int a, b;

    for (k = 0, i = n - 1; i >= 0; i -= 2, k++) {
        for (j = 0; j < i; j++) {
            /* left-up to right-up */
            a = matrix[k + j][i + k];
            matrix[k + j][i + k] = matrix[k][k + j];

            /* right-up to right-down */
            b = matrix[i + k][i + k - j];
            matrix[i + k][i + k - j] = a;

            /* right-down to left-down */
            a = matrix[i + k - j][k];
            matrix[i + k - j][k] = b;

            /* left-down to left-up */
            matrix[k][k + j] = a;
        }
    }
}

int main() {
    int i, j, n;
    n = 5;
    int **mat = (int **)calloc(n, sizeof(int *));
    for (i = 0; i < n; i++) {
        mat[i] = (int *)calloc(n, sizeof(int));
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            mat[i][j] = n * i + j + 1;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%2d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("--------------\n");

    rotate(mat, n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%2d ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
