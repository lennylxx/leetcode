#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    if (x < 0) return false;

    int t = x;
    int mask = 1;
    while (t >= 10) {
        mask *= 10;
        t /= 10;
    }

    int l, r;
    while (x) {
        r = x % 10;
        l = x / mask;
        if (l != r) return false;
        x = (x % mask) / 10;
        mask /= 100;
    }

    return true;
}

int main(){
    int a = 1234321;
    printf("%d\n", isPalindrome(a));
    return 0;
}
