#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValid(int *columns, int row) {
    int i;
    for (i = 0; i < row; i++) {
        if (columns[i] == columns[row]
            || (columns[i] - columns[row] == i - row)
            || (columns[i] - columns[row] == row - i)) {
                return false;
            }
    }
    return true;
}

void placeQueens(int *count, int *columns, int row, int n) {
    int j; /* column */
    if (row == n) { /* found one solution */
        (*count) ++;
        return;
    }
    for (j = 0; j < n; j++) {
        /* try to place a queen */
        columns[row] = j;
        if (isValid(columns, row)) {
            /* place another queen */
            placeQueens(count, columns, row + 1, n);
        }
    }
}

int totalNQueens(int n) {
    int count = 0;
    int *columns = (int *)calloc(n, sizeof(int));
    placeQueens(&count, columns, 0, n);
    return count;
}

int main() {
    printf("%d\n", totalNQueens(4)); /* should be 2 */
    printf("%d\n", totalNQueens(8)); /* should be 92 */
    return 0;
}
