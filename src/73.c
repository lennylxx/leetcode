#include <stdio.h>
#include <stdlib.h>

/* space: O(m+n) */
void setZeroes(int **matrix, int m, int n) {
    int *row_flag = (int *)calloc(m, sizeof(int));
    int *col_flag = (int *)calloc(n, sizeof(int));

    int i, j, ii, jj;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                row_flag[i] = 1;
                col_flag[j] = 1;
            }
        }
    }
    for (j = 0; j < n; j++) {
        if (col_flag[j]) {
            for (ii = 0; ii < m; ii++) {
                matrix[ii][j] = 0;
            }
        }
    }
    for (i = 0; i < m; i++) {
        if (row_flag[i]) {
            for (jj = 0; jj < n; jj++) {
                matrix[i][jj] = 0;
            }
        }
    }
}

int main() {
    int m, n, i, j;
    m = 5;
    n = 4;

    int **matrix = (int **)calloc(m, sizeof(int *));
    for (i = 0; i < m; i++)
        matrix[i] = (int *)calloc(n, sizeof(int));

    matrix[0][0] = 0; matrix[0][1] = 0; matrix[0][2] = 0; matrix[0][3] = 5;
    matrix[1][0] = 4; matrix[1][1] = 3; matrix[1][2] = 1; matrix[1][3] = 4;
    matrix[2][0] = 0; matrix[2][1] = 1; matrix[2][2] = 1; matrix[2][3] = 4;
    matrix[3][0] = 1; matrix[3][1] = 2; matrix[3][2] = 1; matrix[3][3] = 3;
    matrix[4][0] = 0; matrix[4][1] = 0; matrix[4][2] = 1; matrix[4][3] = 1;

    setZeroes(matrix, m, n);

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
