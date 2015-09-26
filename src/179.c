#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 12 /* max number of digits in 10-base integer */

int compare(int a, int b) {
    char stra[N] = { 0 };
    char strb[N] = { 0 };
    sprintf(stra, "%d", a);
    sprintf(strb, "%d", b);

    char aplusb[N + N] = { 0 };
    char bplusa[N + N] = { 0 };
    strcpy(aplusb, stra);
    strcat(aplusb, strb);

    strcpy(bplusa, strb);
    strcat(bplusa, stra);

    return strcmp(aplusb, bplusa);
}

void quicksort(int *nums, int left, int right) {
    if (left > right) return;

    int i = left;
    int j = right;
    int pivot = nums[left];
    while (i < j) {
        while (i < j && compare(nums[j], pivot) <= 0) j--;
        nums[i] = nums[j];
        while (i < j && compare(nums[i], pivot) >= 0) i++;
        nums[j] = nums[i];
    }
    nums[i] = pivot;
    quicksort(nums, left, i - 1);
    quicksort(nums, i + 1, right);
}

char* largestNumber(int* nums, int numsSize) {
    quicksort(nums, 0, numsSize - 1);
    char *ans = (char *)calloc(numsSize * N, sizeof(char));
    int i;
    for (i = 0; i < numsSize; i++) {
        char buf[N] = { 0 };
        sprintf(buf, "%d", nums[i]);
        strcat(ans, buf);
    }

    /* skip leading zeros */
    while (*ans == '0' && *(ans + 1) == '0') ans++;

    return ans;
}

int main() {
    int nums0[] = { 3, 30, 34, 5, 9 };
    printf("%s\n", largestNumber(nums0, sizeof(nums0) / sizeof(nums0[0])));

    int nums1[] = { 0, 0 };
    printf("%s\n", largestNumber(nums1, sizeof(nums1) / sizeof(nums1[0])));

    return 0;
}
