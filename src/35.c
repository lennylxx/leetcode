#include <stdio.h>

int searchInsert(int A[], int n, int target) {
    int l, r, m;
    l = 0;
    r = n - 1;
    while (l <= r) {
        m = (l + r) / 2;
        if (A[m] == target) {
            return m;
        }
        else if (A[m] < target) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return l;
}

int main() {
    int num[] = {1};
    /* should be 1 */
    printf("%d\n", searchInsert(num, sizeof(num)/sizeof(num[0]), 4));
    return 0;
}
