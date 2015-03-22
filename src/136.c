#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int singleNumber(int A[], int n) {
    int one = 0;
    int i;
    for (i = 0; i < n; i++) {
        one = one ^ A[i];
    }
    return one;
}

int main()
{
    int A[] = {1, 2, 1, 3, 4, 3, 4};
    printf("%d\n", singleNumber(A, sizeof(A)/sizeof(A[0])));
    return 0;
}
