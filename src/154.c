#include <stdio.h>
#include <assert.h>

int findMin(int *nums, int numsSize) {
    int l = 0;
    int r = numsSize - 1;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (nums[l] > nums[m]) { /* right side is sorted */
            r = m;
        }
        else if (nums[r] < nums[m]) { /* left side is sorted */
            l = m + 1;
        }
        else { /* the sub-array is not rotated, 1 step to deal with dups */
            r--;
        }
    }
    return nums[l];
}

int main() {
    int nums[] = { 3, 3, 1, 3 };

    assert(findMin(nums, sizeof(nums) / sizeof(nums[0])) == 1);

    printf("all tests passed!\n");

    return 0;
}
