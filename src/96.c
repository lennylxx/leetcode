#include <stdio.h>
#include <stdlib.h>

/* 
    Catalan Number Catalan(n) = 2(2n-1)/(n+1)*Catalan(n-1)
                              = C(2n, n)/(n+1) = (2n)!/(n+1)!n!  
    http://mathworld.wolfram.com/CatalanNumber.html
*/

int numTrees(int n) {
    if (n < 3) return n;
    
    int *d = (int *) calloc(n + 1, sizeof(int));
    int i, j;
    d[0] = 1; /* dummy */
    d[1] = 1;
    d[2] = 2;
    for (i = 3; i <= n; i++) {
        for (j = 0; j < i; j++) {
            d[i] += d[j] * d[i - 1 - j];
        }
    }
    return d[n];
}

int main() {
    printf("%d\n", numTrees(4));
    return 0;
}
