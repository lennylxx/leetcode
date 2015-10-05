#include <stdio.h>
#include <assert.h>

void quicksort(int *nums, int start, int end);

static inline int min(int a, int b) {
    return (a < b) ? a : b;
}

int hIndex(int* citations, int citationsSize) {
    if (citations == NULL || citationsSize == 0) return 0;
    quicksort(citations, 0, citationsSize);

    int hIndex = 0;
    int i;
    for (i = 0; i < citationsSize; i++) {
        int h = min(citations[i], citationsSize - i);
        if (h > hIndex) hIndex = h;
        if (citationsSize - i < citations[i]) {
            break;
        }
    }

    return hIndex;
}

void quicksort(int *nums, int start, int end) {
    if (start >= end) return;

    int i = start;
    int j = end - 1;
    int sentinal = nums[start];
    while (i < j) {
        while (i < j && nums[j] >= sentinal) j--;
        nums[i] = nums[j];
        while (i < j && nums[i] <= sentinal) i++;
        nums[j] = nums[i];
    }

    nums[i] = sentinal;
    quicksort(nums, start, i);
    quicksort(nums, i + 1, end);
}

int hIndex0(int* citations, int citationsSize) {
    if (citations == NULL || citationsSize == 0) return 0;
    quicksort(citations, 0, citationsSize);

    int hIndex = 0;
    int i;
    for (i = citationsSize - 1; i >= 0; i--) {
        if (citations[i] > hIndex) {
            hIndex++;
        }
        else {
            break;
        }
    }

    return hIndex;
}

int main() {

    int citations0[] = { 3, 0, 6, 1, 5 };
    int citations1[] = { 0 };
    int citations2[] = { 1 };
    int citations3[] = { 1, 2, 2 };
    int citations4[] = { 2, 2 };

    assert(hIndex(citations0, sizeof(citations0) / sizeof(citations0[0])) == 3);
    assert(hIndex(citations1, sizeof(citations1) / sizeof(citations1[0])) == 0);
    assert(hIndex(citations2, sizeof(citations2) / sizeof(citations2[0])) == 1);
    assert(hIndex(citations3, sizeof(citations3) / sizeof(citations3[0])) == 2);
    assert(hIndex(citations4, sizeof(citations4) / sizeof(citations4[0])) == 2);

    printf("all tests passed!\n");

    return 0;
}
