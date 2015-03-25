#include <stdio.h>
#include <stdlib.h>

/* space: O(m+n) time: O(m*n) */
void setZeroes_1(int **matrix, int m, int n) {
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

/* space: O(1) time: O(m*n)
 * use first column to set row flag
 * and first row to set column flag */
void setZeroes(int **matrix, int m, int n) {
    int first_col_zero, first_row_zero;
    first_col_zero = first_row_zero = 0;
    int i, j;
    /* scan first column */
    for (i = 0; i < m; i++) {
        if (matrix[i][0] == 0) {
            first_col_zero = 1;
            break;
        }
    }
    /* scan first row */
    for (j = 0; j < n; j++) {
        if (matrix[0][j] == 0) {
            first_row_zero = 1;
            break;
        }
    }
    /* scan the matrix */
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    /* set zeros except first column and first row */
    for (i = 1; i < m; i++) {
        for (j = 1; j < n; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    /* set first column and first row to zero */
    if (first_col_zero) {
        for (i = 0; i < m; i++) matrix[i][0] = 0;
    }
    if (first_row_zero) {
        for (j = 0; j < n; j++) matrix[0][j] = 0;
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
