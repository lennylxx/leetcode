#include <stdio.h>
#include <stdlib.h>

void print_tri(int **triangle, int numRows) {
    int i, j;
    for (i = 0; i < numRows; i++) {
        for (j = 0; j < numRows; j++) {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }
}

int minimumTotal(int **triangle, int numRows) {
    int i, j;
    for (i = numRows - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (triangle[i][j] < triangle[i][j + 1])
                triangle[i-1][j] += triangle[i][j];
            else
                triangle[i-1][j] += triangle[i][j + 1];
            //print_tri(triangle, numRows);
        }
    }
    return triangle[0][0];
}

int main() {
    int row = 3;
    int **triangle = (int **)calloc(row, sizeof(int *));
    int i;
    for (i = 0; i < row; i++) {
        triangle[i] = (int *)calloc(row, sizeof(int));
    }
    triangle[0][0] = -1;
    triangle[1][0] = 2; triangle[1][1] = 3;
    triangle[2][0] = 1; triangle[2][1] = -1; triangle[2][2] = -3;

    printf("%d\n", minimumTotal(triangle, row));
    return 0;
}
