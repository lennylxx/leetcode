#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maximumGap(int num[], int n) {
    if (n < 2) return 0;

    /* radix sort */
    int *sorted_num = (int *)calloc(n, sizeof(int));
    int *temp = (int *)calloc(n, sizeof(int));

    memcpy(sorted_num, num, sizeof(int) * n);
    
    int i, j;
    int shift;
    for (shift = 0; shift < 32; shift += 8) {
        int count[0x100] = {};

        for (i = 0; i < n; i++) {
            count[(sorted_num[i] >> shift) & 0xFF] ++;
        }

        int idx = 0, t = 0;
        for (j = 0; j < 0x100; j++) {
            t = count[j];
            count[j] = idx;
            idx += t;
        }

        for (i = 0; i < n; i++) {
            temp[count[(sorted_num[i] >> shift) & 0xFF] ++] = sorted_num[i];
        }

        int *p = sorted_num;
        sorted_num = temp;
        temp = p;
    }

    int max_diff = 0;
    for (i = 1; i < n; i++) {
        if (sorted_num[i] - sorted_num[i - 1] > max_diff) {
            max_diff = sorted_num[i] - sorted_num[i - 1];
        }
    }

    free(sorted_num);
    free(temp);
    return max_diff;
}

int main() {
    int A[] = { 4, 5, 3, 2, 9, 12, 32, 5 };

    /* should be 20 = abs(12 - 32) */
    printf("%d\n", maximumGap(A, sizeof(A)/sizeof(A[0])));

    return 0;
}
