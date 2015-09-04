#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
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
*/

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void permutation(int *nums, int l, int r, int **ret, int *row) {
    if (l == r) {
        memcpy(ret[(*row)++], nums, (r + 1) * sizeof(int));
    }
    else {
        int i;
        for (i = l; i <= r; i++) {
            swap(nums + l, nums + i);
            permutation(nums, l + 1, r, ret, row);
            swap(nums + l, nums + i);
        }
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

    int **ret = (int **)calloc(*returnSize, sizeof(int *));
    for (i = 0; i < *returnSize; i++) {
        ret[i] = (int *)calloc(numsSize, sizeof(int));
    }

    int row = 0;
    permutation(nums, 0, numsSize - 1, ret, &row);

    return ret;
}

int main() {
    int numsSize = 3;
    int *nums = (int *)malloc(numsSize * sizeof(int));
    int i, j;
    for (i = 0; i < numsSize; i++) {
        nums[i] = i + 1;
    }

    int returnSize = 0;
    int **ret = permute(nums, numsSize, &returnSize);

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
