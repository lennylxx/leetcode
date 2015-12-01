#include <stdio.h>
#include <assert.h>

int findPeakElement(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1, mid;
    while (left < right) {
        mid = left + (right - left) / 2;
        if ((mid == 0 && nums[mid] > nums[mid + 1])
            || (mid == numsSize - 1 && nums[mid] > nums[mid - 1])
            || (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]))
        {
            return mid;
        }
        else if (nums[mid] < nums[mid + 1]) {
            left = mid + 1;
        }
        else if (nums[mid] < nums[mid - 1]) {
            right = mid - 1;
        }
    }

    return left;
}

int main() {
    int nums0[] = { 1, 2, 3, 1 };
    int nums1[] = { 1, 2 };
    assert(findPeakElement(nums0, sizeof(nums0) / sizeof(nums0[0])) == 2);
    assert(findPeakElement(nums1, sizeof(nums1) / sizeof(nums1[0])) == 1);
    return 0;
}
