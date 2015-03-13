#include <stdio.h>

int maxProduct(int A[], int n) {
    int i;
    int min, max, ret;
    ret = max = min = A[0];
    for (i = 1; i < n; i++) {
        int t_max = max;
        if (max * A[i] > A[i])
            max *= A[i];
        else
            max = A[i];
        /* A[i] is negative*/
        if (min * A[i] > max)
            max = min * A[i];
        
        if (min * A[i] < A[i])
            min *= A[i];
        else
            min = A[i];
        /* A[i] is negative*/
        if (t_max * A[i] < min)
            min = t_max * A[i];
        
        if (max > ret)
            ret = max;
    }
    return ret;
}

int main() {
    int A[] = {1, -2, 3, -2, -3};
    printf("%d\n", maxProduct(A, 5));

    return 0;
}
