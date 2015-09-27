#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (nums == NULL || numsSize == 0) return 0;

    int storeIndex = 0;
    int i = 0;
    while (i < numsSize) {
        int count = 1;
        while (i < numsSize - 1 && nums[i] == nums[i + 1]) {
            i++;
            count++;
            if (i >= numsSize) goto OUT;
        }
        if (count >= 2) {
            nums[storeIndex++] = nums[i];
            nums[storeIndex++] = nums[i];
        }
        else {
            nums[storeIndex++] = nums[i];
        }
        i++;
    }
OUT:
    return storeIndex;
}

int main() {
    int nums[] = { 1, 1, 1, 2, 2, 3, 3, 3, 4, 5, 5 };
    int new_len = removeDuplicates(nums, sizeof(nums) / sizeof(nums[0]));

    int i;
    for (i = 0; i < new_len; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
