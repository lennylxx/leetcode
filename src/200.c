#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void dfs(char **grid, bool **visited, int i, int j, int numRows, int numColumns) {
    if (i >= 0 && i < numRows && j >= 0 && j < numColumns && !visited[i][j]) {
        visited[i][j] = 1;
        if (grid[i][j] == '1') { /* island */
            dfs(grid, visited, i, j - 1, numRows, numColumns); /* left */
            dfs(grid, visited, i, j + 1, numRows, numColumns); /* right */
            dfs(grid, visited, i - 1, j, numRows, numColumns); /* up */
            dfs(grid, visited, i + 1, j, numRows, numColumns); /* down */
        }
    }
}

int numIslands(char **grid, int numRows, int numColumns) {
    if (grid == NULL || numRows == 0 || strlen(grid[0]) == 0)
        return 0;

    int i, j;
    int count = 0;

    bool **visited = (bool **)calloc(numRows, sizeof(bool *));
    for (i = 0; i < numRows; i++) {
        visited[i] = (bool *)calloc(numColumns, sizeof(bool));
    }

    for (i = 0; i < numRows; i++) {
        for (j = 0; j < numColumns; j++) {
            if (!visited[i][j]) { /* has not been visited */
                if (grid[i][j] == '1') /* it's an island */
                    count++;
                dfs(grid, visited, i, j, numRows, numColumns);
            }
        }
    }
    return count;
}

int main() {
    int row = 3;
    int col = 3;
    char **grid = (char **)calloc(1, sizeof(char *));

    grid[0] = "111";
    grid[1] = "010";
    grid[2] = "111";

    /* should be 1 */
    printf("%d\n", numIslands(grid, row, col));
    return 0;
}
