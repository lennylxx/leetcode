#include <stdio.h>

int search(int A[], int n, int target) {
    int l, r, m;
    l = 0;
    r = n - 1;
    while (l <= r) {
        m = (l + r) / 2;
        if (A[m] == target) return m;
        
        if (A[l] <= A[m]) { /* left half is sorted */
            if (A[l] <= target && target < A[m]) { /* target in left half */
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        else { /* right half is sorted */
            if (A[m] < target && target <= A[r]) { /* target in right half */
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        } 
    }
    return -1;
}

int main() {
    int num[] = { 1, 3, 5 };
    /* should be 0 */
    printf("%d\n", search(num, sizeof(num)/sizeof(num[0]), 1));
    return 0;
}
