#include <stdio.h>
#include <stdlib.h>

int nthUglyNumber(int n) {
    if (n < 2) return 1;
    int *nums = (int *)malloc(n * sizeof(int));
    nums[0] = 1;
    int i2 = 0, i3 = 0, i5 = 0; /* index of 2, 3, 5 respectively */
    int k = 1; /* store index */

    while (k < n) {
        int min = 0;
        if (nums[i2] * 2 <= nums[i3] * 3) {
            min = nums[i2] * 2;
        }
        else {
            min = nums[i3] * 3;
        }

        if (nums[i5] * 5 < min) {
            min = nums[i5] * 5;
        }

        nums[k++] = min;

        if (nums[i2] * 2 == min) i2++;
        if (nums[i3] * 3 == min) i3++;
        if (nums[i5] * 5 == min) i5++;
    }

    int ans = nums[n - 1];
    free(nums);

    return ans;
}

int main() {

    int n = 10;
    int i;
    for (i = 1; i <= n; i++) {
        printf("%d ", nthUglyNumber(i));
    }
    printf("\n");

    return 0;
}
