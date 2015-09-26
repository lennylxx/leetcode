#include <stdio.h>

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void nextPermutation(int* nums, int numsSize) {
    if (nums == NULL || numsSize == 0) return;

    int i, j;
    int left, right;

    /* from right to left, find first i for nums[i] < nums[i+1] */
    for (i = numsSize - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) break;
    }

    /* can't find such i, reverse whole array and return */
    if (i == -1) {
        left = 0;
        right = numsSize - 1;
        for (i = left; i <= left + (right - left) / 2; i++) {
            swap(&nums[i], &nums[right - i + left]);
        }
        return;
    }

    /* from right to left, find first j for nums[j] > nums[i] */
    for (j = numsSize - 1; j >= 0; j--) {
        if (nums[j] > nums[i]) break;
    }

    /* swap nums[i] and nums[j] */
    swap(&nums[i], &nums[j]);

    /* reverse nums[i+1] to nums[n-1] */
    left = i + 1;
    right = numsSize - 1;
    for (i = left; i <= left + (right - left) / 2; i++) {
        swap(&nums[i], &nums[right - i + left]);
    }
}

int main() {
    int nums[] = { 1, 2, 3, 4 };
    int size = sizeof(nums) / sizeof(nums[0]);
    int i = size;
    int count = 1;
    while (i) {
        count *= i;
        i--;
    }

    count++; /* test lowest possible order case */
    while (count--){
        for (i = 0; i < size; i++){
            printf("%d ", nums[i]);
        }
        printf("\n");
        nextPermutation(nums, size);
    }

    return 0;
}
