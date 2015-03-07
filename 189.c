#include <stdio.h>

void rotate(int nums[], int n, int k) {
    int i, j, c;
    i = j = 0;
    int x = nums[i];
    int t;
    for(c = 0; c < n; c++)
    {
        i = (i + k) % n;
        t = nums[i];
        nums[i] = x;
        x = t;
        if (i == j)
        {
            i = ++j;
            x = nums[i];
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
