#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void permutation(int* nums, int numsSize,
                 bool* visited, int *pos,
                 int **ret, int *row, int col) {

    int i;
    if (col < numsSize) {
        for (i = 0; i < numsSize; i++) {
            if (!visited[i]) {
                pos[col] = i;
                visited[i] = true;
                permutation(nums, numsSize, visited, pos, ret, row, col + 1);
                visited[i] = false;
            }
        }
    }
    else {
        for (i = 0; i < numsSize;i++)
            ret[*row][pos[i]] = nums[i];
        (*row)++;
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize) {
    if (nums == NULL || numsSize == 0) return NULL;

    (*returnSize) = 1;
    int i;
    for (i = 2; i <= numsSize; i++) {
        (*returnSize) *= i;
    }

    bool *visited = (bool *)calloc(numsSize, sizeof(bool));
    int *pos = (int *)calloc(numsSize, sizeof(int));

    int **ret = (int **)calloc(*returnSize, sizeof(int *));
    for (i = 0; i < *returnSize; i++) {
        ret[i] = (int *)calloc(numsSize, sizeof(int));
    }

    int row = 0;
    permutation(nums, numsSize, visited, pos, ret, &row, 0);

    free(visited);
    free(pos);

    return ret;
}

int main() {

    int nums[] = { 1, 2, 3 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;
    int **ret = permute(nums, numsSize, &returnSize);

    int i, j;
    for (i = 0; i < returnSize; i++) {
        for (j = 0; j < numsSize; j++) {
            printf("%d ", ret[i][j]);
        }
        free(ret[i]);
        printf("\n");
    }
    free(ret);

    return 0;
}
