#include <stdio.h>
#include <stdbool.h>

bool search(int A[], int n, int target) {
    int l, r, m;
    l = 0;
    r = n - 1;
    while (l <= r) {
        m = (l + r) / 2;
        if (A[m] == target) return true;

        if (A[l] < A[m]) { /* left half is sorted */
            if (A[l] <= target && target < A[m]) { /* target in left half */
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        else if (A[l] > A[m]){ /* right half is sorted */
            if (A[m] < target && target <= A[r]) { /* target in right half */
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        else {      /* we don't know which side is sorted */
            l++;    /* Q: why use 'l++' instead of 'r--' ?            */
                    /* A: 'cos value of division always take floor of */
                    /*    result, m may equals to l.                  */
                    /*    e.g. l=3,r=4,m:=(3+4)/2=3                   */
                    /*    use 'r--', m will never equals to 4         */
        }
    }
    return false;
}

int main() {
    int num[] = { 1, 3, 1, 1, 1 };
    /* should be true */
    printf("%d\n", search(num, sizeof(num) / sizeof(num[0]), 3));
    return 0;
}
