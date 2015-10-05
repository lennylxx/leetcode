#include <stdio.h>
#include <assert.h>

static inline int min(int a, int b) {
    return (a < b) ? a : b;
}

/* from current position to the end, we can caculate an hIndex array
   the hIndex will first ascend and then descend
   so the problem is to find the peak of the hIndex array
   we use binary search */

int hIndex(int* citations, int citationsSize) {
    if (citations == NULL || citationsSize == 0) return 0;

    if (citationsSize == 1) return min(citations[0], 1);

    int i = 0, j = citationsSize - 1;
    int h_prev, h_middle, h_next;

    while (i <= j) {
        int m = i + (j - i) / 2;
        h_prev = min(citations[m - 1], citationsSize - m + 1);
        h_middle = min(citations[m], citationsSize - m);
        h_next = min(citations[m + 1], citationsSize - m - 1);
        if (h_prev <= h_middle && h_middle > h_next) {
            break;
        }
        else if (h_middle <= h_next) {
            i = m + 1;
        }
        else if (h_middle > h_next) {
            j = m - 1;
        }
        else {
            i++;
        }
    }

    return h_middle;
}

int hIndex0(int* citations, int citationsSize) {
    if (citations == NULL || citationsSize == 0) return 0;

    int i = 0, j = citationsSize - 1;
    while (i <= j) {
        int m = i + (j - i) / 2;
        if (citations[m] >= citationsSize - m) {
            j = m - 1;
        }
        else {
            i = m + 1;
        }
    }

    return citationsSize - i;
}

int main() {

    int citations0[] = { 0, 1, 3, 5, 6 };
    int citations1[] = { 0, 3, 3, 3, 4 };
    int citations2[] = { 0, 3, 4, 4, 4, 4, 5, 5 };

    assert(hIndex(citations0, sizeof(citations0) / sizeof(citations0[0])) == 3);
    assert(hIndex(citations1, sizeof(citations1) / sizeof(citations1[0])) == 3);
    assert(hIndex(citations2, sizeof(citations2) / sizeof(citations2[0])) == 4);

    printf("all tests passed!\n");

    return 0;
}
