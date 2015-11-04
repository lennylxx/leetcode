#include <stdio.h>

void rotate(int nums[], int n, int k) {
    int i, j, c;
    i = j = 0;
    int pre = nums[i];
    int t;
    for(c = 0; c < n; c++) {
        i = (i + k) % n;
        t = nums[i];
        nums[i] = pre;
        pre = t;
        if (i == j) {
            i = ++j;
            pre = nums[i];
        }
    }
}

/*
 Cyclic group generator to do matrix transpose.
 use a 1-dimension array to reprents m*n matrix.
 the result is an n*m matrix.
 */

void transpose(int *matrix, int m, int n) {
    int i, j, c;
    i = j = 0;
    int pre = matrix[0];
    int t;
    for (c = 0; c < m * n - 1; c++) { /* pay attention it's m*n-1 */
        i = (i % n) * m + (i / n);
        t = matrix[i];
        matrix[i] = pre;
        pre = t;
        if (i == j) {
            i = ++j;
            pre = matrix[i];
        }
    }
}

void print(int nums[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main()
{
    int a[7] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    int k = 4;

    rotate(a, n, k);
    print(a, n);

    int b[6] = {1, 2, 3, 4, 5, 6};
    n = 6;
    k = 3;

    rotate(b, n, k);
    print(b, n);

    return 0;
}
