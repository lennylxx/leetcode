#include <stdio.h>
#include <assert.h>

int addDigits0(int num) {
    int ans = 0;
    while (num > 0) {
        ans += num % 10;
        num /= 10;
        if (ans >= 10) {
            ans = ans / 10 + ans % 10;
        }
    }
    return ans;
}

int addDigits(int num) {
    return 1 + (num - 1) % 9;
}

int main() {

    assert(addDigits(0) == 0);
    assert(addDigits(1) == 1);
    assert(addDigits(9) == 9);
    assert(addDigits(38) == 2);
    assert(addDigits(12345) == 6);

    printf("all tests passed!\n");
    
    return 0;
}
