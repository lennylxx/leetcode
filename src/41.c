#include <stdio.h>
#include <assert.h>

int firstMissingPositive(int* nums, int numsSize) {
    int i;
    for (i = 0; i < numsSize; i++) {
        while (nums[i] > 0 && nums[i] < numsSize && nums[nums[i] - 1] != nums[i]) {
            int t = nums[i];
            nums[i] = nums[t - 1];
            nums[t - 1] = t;
        }
    }

    for (i = 0; i < numsSize; i++) {
        if (nums[i] != i + 1)
            break;
    }

    return i + 1;
}

int main() {

    int nums0[] = { 1, 2, 0 };
    int nums1[] = { 3, 4, -1, 1 };
    int nums2[] = { -1, 4, 2, 1, 9, 10 };
    int nums3[] = { 1, 1 };

    assert(firstMissingPositive(nums0, sizeof(nums0) / sizeof(nums0[0])) == 3);
    assert(firstMissingPositive(nums1, sizeof(nums1) / sizeof(nums1[0])) == 2);
    assert(firstMissingPositive(nums2, sizeof(nums2) / sizeof(nums2[0])) == 3);
    assert(firstMissingPositive(nums3, sizeof(nums3) / sizeof(nums3[0])) == 2);

    printf("all tests passed!\n");

    return 0;
}
