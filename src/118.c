#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes, int* returnSize) {
    *returnSize = numRows;
    int **ans = (int **)calloc(*returnSize, sizeof(int *));
    (*columnSizes) = (int *)calloc(*returnSize, sizeof(int));

    int i, j;

    for (i = 0; i < *returnSize; i++) {
        (*columnSizes)[i] = i + 1;
        ans[i] = (int *)calloc((*columnSizes)[i], sizeof(int));
        ans[i][0] = 1;
        for (j = 1; j < i; j++) {
            ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
        ans[i][i] = 1;
    }

    return ans;
}

int main() {

    int returnSize = 0;
    int *columnSizes = NULL;
    int **ret = generate(5, &columnSizes, &returnSize);

    int i, j;
    for(i = 0; i < returnSize; i++) {
        for (j = 0; j < columnSizes[i]; j++) {
            printf("%d ", ret[i][j]);
        }
        printf("\n");
    }

    return 0;
}
