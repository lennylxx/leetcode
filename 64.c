#include <stdio.h>
#include <stdlib.h>

int minPathSum(int **grid, int nRows, int nCols) {
    int i, j;
    for (i = 0; i < nRows; i++) {
        for (j = 0; j < nCols; j++) {
            if (i > 0 && j == 0)
                grid[i][j] += grid[i - 1][j];
            if (j > 0 && i == 0)
                grid[i][j] += grid[i][j - 1];
            if (i > 0 && j > 0) {
                if (grid[i][j - 1] < grid[i - 1][j])
                grid[i][j] += grid[i][j - 1];
                else
                grid[i][j] += grid[i - 1][j];
            }
        }
    }
    /*
    for (i = 0; i < nRows; i++) {
        for (j = 0; j < nCols; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    */
    return grid[nRows - 1][nCols - 1];
}

int main() {
    int m, n, i;
    m = n = 3;
    int **grid = (int **) calloc (m, sizeof(int *));
    
    for (i = 0; i < m; i++)
    grid[i] = (int *) calloc (n, sizeof(int));
    
    grid[0][0] = 1; grid[0][1] = 2; grid[0][2] = 3;
    grid[1][0] = 1; grid[1][1] = 2; grid[1][2] = 3;
    grid[2][0] = 1; grid[2][1] = 2; grid[2][2] = 3;
    
    printf("%d\n", minPathSum(grid, m, n));
    return 0;
}
