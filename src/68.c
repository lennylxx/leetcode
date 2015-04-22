#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *ans = (int *)malloc((digitsSize + 1) * sizeof(int));
    *returnSize = digitsSize;
    int i;
    int sum = 1; /* plus one */
    for (i = digitsSize - 1; i >= 0; i--) {
        sum += digits[i];
        ans[i + 1] = sum % 10;
        sum /= 10;
    }
    if (sum) {
        ans[0] = sum;
        *returnSize = *returnSize + 1;
        return ans;
    }
    else {
        return ans + 1;
    }
}

int main() {
    int A[] = { 9, 9, 9 };
    int retSize = 0;
    int *ans = plusOne(A, sizeof(A) / sizeof(A[0]), &retSize);
    int i;
    for (i = 0; i < retSize; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}
