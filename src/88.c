#include <stdio.h>

void merge(int* nums1, int m, int* nums2, int n) {
    int i, j, k;
    i = m - 1;
    j = n - 1;
    k = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (nums2[j] > nums1[i]) {
            nums1[k] = nums2[j];
            j--;
        }
        else {
            nums1[k] = nums1[i];
            i--;
        }
        k--;
    }

    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main() {
    int nums1[] = { 4, 5, 6, 0, 0, 0 };
    int nums2[] = { 1, 2, 3 };
    int i;
    printf("nums1: ");

    for (i = 0; i < 3; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    printf("nums2: ");
    for (i = 0; i < 3; i++) {
        printf("%d ", nums2[i]);
    }
    printf("\n");

    merge(nums1, 3, nums2, 3);

    printf("merged: ");
    for (i = 0; i < 6; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    return 0;
}
