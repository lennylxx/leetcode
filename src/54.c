#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *spiralOrder(int **matrix, int matrixRowSize, int matrixColSize) {
    int *ret = (int *)malloc(matrixRowSize * matrixColSize * sizeof(int));
    if (matrix == NULL || matrixRowSize == 0 || matrixColSize == 0)
        return ret;

    int left = 0;
    int right = matrixColSize - 1;
    int up = 0;
    int down = matrixRowSize - 1;

    int k = 0;
    int i;

    while (left <= right && up <= down) {
        if (left == right && up == down) {
            ret[k++] = matrix[left][up];
        }
        else if (left == right) {
            for (i = up; i <= down; i++)
                ret[k++] = matrix[i][right];
        }
        else if (up == down) {
            for (i = left; i <= right; i++)
                ret[k++] = matrix[up][i];
        }
        else {
            for (i = left; i <= right - 1; i++)
                ret[k++] = matrix[up][i];
            for (i = up; i <= down - 1; i++)
                ret[k++] = matrix[i][right];
            for (i = right; i >= left + 1; i--)
                ret[k++] = matrix[down][i];
            for (i = down; i >= up + 1; i--)
                ret[k++] = matrix[i][left];
        }
        left++;
        right--;
        up++;
        down--;
    }

    return ret;
}

int main() {
    int rows = 4;
    int cols = 3;
    int **matrix = (int **)malloc(rows * sizeof(int *));
    int i, j;
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j + 1;
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("------\n");

    int *ret = spiralOrder(matrix, rows, cols);

    int size = rows * cols;
    for (i = 0; i < size; i++) {
        printf("%d ", ret[i]);
    }
    printf("\n");

    return 0;
}
