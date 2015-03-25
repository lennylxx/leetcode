#include <stdio.h>

int trailingZeroes(int n) {
    int c = 0;
    while (n) {
        n /= 5;
        c += n;
    }
    return c;
}

int main() {
    printf("%d\n", trailingZeroes(1808548329));
    return 0;
}
