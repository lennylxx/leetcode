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

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* another method, diff from Hoare's quicksort */
int findKthLargest0(int* nums, int numsSize, int k) {
    if (k < 1 || k > numsSize) return 0;

    int pivotIndex = 0; /* select a pivot, simply use leftest elem */
    int pivotValue = nums[pivotIndex];
    int i = 0; /* store index */
    int j; /* sweep index */

    swap(&nums[pivotIndex], &nums[numsSize - 1]);

    for (j = 0; j < numsSize - 1; j++) {
        if (nums[j] <= pivotValue) {
            swap(&nums[j], &nums[i]);
            i++;
        }
    }

    swap(&nums[i], &nums[numsSize - 1]);

    int rightSize = numsSize - i - 1; /* size of right sub array */

    if (rightSize + 1 == k) { /* found, it's pivot */
        return nums[i];
    }

    if (rightSize >= k) {
        return findKthLargest0(nums + i + 1, rightSize, k); /* find in right half */
    }
    else {
        return findKthLargest0(nums, i, k - rightSize - 1); /* find in left half */
    }
}

int main() {

    int n[] = { 3, 7, 8, 1, 2, 5, 6, 9 };

    /* should be 7 */
    printf("%d\n", findKthLargest(n, sizeof(n) / sizeof(n[0]), 3));

    return 0;
}
