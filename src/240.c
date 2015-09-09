#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

bool searchMatrix(int **matrix, int matrixRowSize, int matrixColSize, int target) {
    int i, j;
    i = 0; j = matrixColSize - 1; /* right-top */
    bool found = false;
    while (i < matrixRowSize && j >= 0) {
        if (matrix[i][j] == target) {
            found = true;
            break;
        }
        if (matrix[i][j] < target)
            i++;
        else
            j--;
    }

    return found;
}

int main() {
    int rows = 5;
    int cols = 5;

    int **matrix = (int **)malloc(rows * sizeof(int *));
    int i;
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    matrix[0][0] = 1; matrix[0][1] = 4; matrix[0][2] = 7; matrix[0][3] = 11; matrix[0][4] = 15;
    matrix[1][0] = 2; matrix[1][1] = 5; matrix[1][2] = 8; matrix[1][3] = 12; matrix[1][4] = 19;
    matrix[2][0] = 3; matrix[2][1] = 6; matrix[2][2] = 9; matrix[2][3] = 16; matrix[2][4] = 22;
    matrix[3][0] = 10; matrix[3][1] = 13; matrix[3][2] = 14; matrix[3][3] = 17; matrix[3][4] = 24;
    matrix[4][0] = 18; matrix[4][1] = 21; matrix[4][2] = 23; matrix[4][3] = 26; matrix[4][4] = 30;

    assert(searchMatrix(matrix, rows, cols, 5) == true);
    assert(searchMatrix(matrix, rows, cols, 20) == false);

    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    printf("all tests passed!\n");

    return 0;
}
