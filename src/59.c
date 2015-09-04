#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n) {
    int **matrix = (int **)malloc(n * sizeof(int *));
    if (n == 0) return matrix;

    int i;
    for (i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    int left = 0;
    int right = n - 1;
    int up = 0;
    int down = n - 1;
    int k = 1;

    while (left <= right && up <= down) {
        if (left == right && up == down) {
            matrix[left][up] = k++;
        }
        else {
            for (i = left; i <= right - 1; i++)
                matrix[up][i] = k++;
            for (i = up; i <= down - 1; i++)
                matrix[i][right] = k++;
            for (i = right; i >= left + 1; i--)
                matrix[down][i] = k++;
            for (i = down; i >= up + 1; i--)
                matrix[i][left] = k++;
        }
        left++;
        right--;
        up++;
        down--;
    }
    return matrix;
}

int main() {
    int n = 3;
    int **m = generateMatrix(n);

    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}
