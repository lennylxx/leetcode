#include <stdio.h>
#include <assert.h>

int minSubArrayLen(int s, int* nums, int numsSize) {
    int i = 0, j = 0;
    int sum = 0;
    int min = numsSize + 1;
    while (j < numsSize) {
        sum += nums[j];
        while (sum >= s) {
            if (j - i + 1 < min) {
                min = j - i + 1;
            }
            sum -= nums[i];
            i++;
        }
        j++;
    }

    return min == numsSize + 1 ? 0 : min;
}

int main() {
    int nums[] = { 2, 3, 1, 2, 4, 3 };
    assert(minSubArrayLen(7, nums, sizeof(nums) / sizeof(nums[0])) == 2);

    printf("all tests passed\n");

    return 0;
}
