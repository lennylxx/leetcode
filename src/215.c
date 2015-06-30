#include <stdio.h>

int findKthLargest(int* nums, int numsSize, int k) {
    if (k < 1 || k > numsSize) return 0;

    int pivot = nums[0];
    int i = 0, j = numsSize - 1;

    while (i < j) {
        while (i < j && nums[j] >= pivot)
            j--;

        nums[i] = nums[j];

        while (i < j && nums[i] <= pivot)
            i++;

        nums[j] = nums[i];
    }

    nums[i] = pivot;

    int rightSize = numsSize - i - 1; /* size of right sub array */

    if (rightSize + 1 == k) { /* found, it's pivot */
        return nums[i];
    }

    if (rightSize >= k) {
        return findKthLargest(nums + i + 1, rightSize, k); /* find in right half */
    }
    else {
        return findKthLargest(nums, i, k - rightSize - 1); /* find in left half */
    }
}

int main() {

    int n[] = { 3, 7, 8, 1, 2, 5, 6, 9 };

    /* should be 7 */
    printf("%d\n", findKthLargest(n, sizeof(n) / sizeof(n[0]), 3));

    return 0;
}
