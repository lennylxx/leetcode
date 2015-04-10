#include <stdio.h>
#include <stdlib.h>

int *getRow(int rowIndex) {
    int k = rowIndex;
    int *ans = (int *)calloc(k + 1, sizeof(int));
    int i, j;
    int prev = 0, cur = 0;
    ans[0] = 1;
    for (i = 1; i < k + 1; i++) {
        prev = ans[0];
        for (j = 1; j < i; j++) {
            cur = ans[j];
            ans[j] += prev;
            prev = cur;
        }
        ans[i] = 1;
    }
    return ans;
}

int main() {
    int k = 5;
    int *ans = getRow(k);
    int i;
    for (i = 0; i < k + 1; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}
