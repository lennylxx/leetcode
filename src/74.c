#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    bool found = false;
    int lr = 0;
    int hr = matrixRowSize - 1;
    int r = 0;
    while (lr <= hr) {
        int mr = lr + (hr - lr) / 2;
        if (target >= matrix[mr][0] && target <= matrix[mr][matrixColSize - 1]) {
            found = true;
            r = mr;
            break;
        }
        else if (target < matrix[mr][0])
            hr = mr - 1;
        else
            lr = mr + 1;
    }

    if (found) {
        int lc = 0;
        int hc = matrixColSize - 1;

        while (lc <= hc) {
            int mc = lc + (hc - lc) / 2;
            if (matrix[r][mc] == target)
                return true;
            else if (target < matrix[r][mc])
                hc = mc - 1;
            else
                lc = mc + 1;
        }

        return false;
    }

    return false;
}

int main() {
    int rows = 3;
    int cols = 4;

    int **matrix = (int **)malloc(rows * sizeof(int *));
    int i;
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    matrix[0][0] = 1; matrix[0][1] = 3; matrix[0][2] = 5; matrix[0][3] = 7;
    matrix[1][0] = 10; matrix[1][1] = 11; matrix[1][2] = 16; matrix[1][3] = 20;
    matrix[2][0] = 23; matrix[2][1] = 30; matrix[2][2] = 34; matrix[2][3] = 50;

    assert(searchMatrix(matrix, rows, cols, 16) == true);
    assert(searchMatrix(matrix, rows, cols, 15) == false);

    printf("all tests passed!\n");

    return 0;
}
