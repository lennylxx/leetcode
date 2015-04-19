#include <stdio.h>

int removeElement(int A[], int n, int elem) {
    int i, j, len;
    j = n - 1;
    len = n;
    for (i = 0; i < len; i++) {
        if (A[i] == elem) {
            int t = A[j];
            A[j] = A[i];
            A[i] = t;
            len--;
            j--;
            i--;
        }
    }

    return len;
}

int main() {
    int A[] = { 3, 1, 2, 3, 3, 4, 5, 3, 6 };
    int new_len = removeElement(A, sizeof(A) / sizeof(A[0]), 3);

    int i;
    for (i = 0; i < new_len; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
