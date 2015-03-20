#include <stdio.h>
#include <stdlib.h>

int uniquePathsWithObstacles(int **obstacleGrid, int m, int n){
    int (*p)[n] = (int (*)[n]) calloc(m * n, sizeof(int));
    p[0][0] = 1;
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (obstacleGrid[i][j]) {
                p[i][j] = 0;
            }
            else {
                if (i > 0 && j == 0)
                    p[i][j] = p[i - 1][j];
                if (j > 0 && i == 0)
                    p[i][j] = p[i][j - 1];
                if (i > 0 && j > 0)
                    p[i][j] = p[i][j - 1] + p[i - 1][j];
            }
        }
    }

    return p[m - 1][n - 1];
}

int main(){
    int m, n, i;
    m = n = 3;
    int **obstacleGrid = (int **) calloc (m, sizeof(int *));
    
    for (i = 0; i < m; i++)
        obstacleGrid[i] = (int *) calloc (n, sizeof(int));
    
    obstacleGrid[1][1] = 1;

    printf("%d\n", uniquePathsWithObstacles(obstacleGrid, m, n));
    return 0;
}
