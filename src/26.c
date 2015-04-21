#include <stdio.h>

int removeDuplicates(int A[], int n) {
    if (n == 0) return 0;
    int i, j;
    i = 1, j = 1;
    while (j < n) {
        while (A[j - 1] == A[j]) {
            j++;
            if (j >= n) goto OUT;
        }
        A[i] = A[j];
        i++;
        j++;
    }

OUT:
    return i;
}

int main() {
    int A[] = { 1, 1, 1, 2, 2, 2, 3, 3, 4, 5, 5 };
    int new_len = removeDuplicates(A, sizeof(A) / sizeof(A[0]));

    int i;
    for (i = 0; i < new_len; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
