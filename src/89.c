#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize) {
    *returnSize = 1 << n;
    int *gray = (int *)malloc(*returnSize * sizeof(int));

    int i;
    for (i = 0; i < *returnSize; i++) {
        gray[i] = (i >> 1) ^ i;
    }

    return gray;
}

int main() {
    int n = 2;
    int returnSize = 0;

    int* ans = grayCode(n, &returnSize);
    int i;
    for (i = 0; i < returnSize; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    free(ans);

    return 0;
}
