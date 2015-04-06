#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char ch2lower(char ch) {
    if (ch >= 'A' && ch <= 'Z')
        ch += 0x20;

    return ch;
}

bool isPalindrome(char *s) {
    int len = strlen(s);
    int head, tail;
    head = tail = 0;
    tail = len - 1;

    while (head <= tail) {
        while (ch2lower(s[head]) < '0'
            || (ch2lower(s[head]) > '9' && ch2lower(s[head]) < 'a')
            || ch2lower(s[head]) > 'z')
        {
            head++;
            if (head > tail) break;
        }

        while (ch2lower(s[tail]) < '0'
            || (ch2lower(s[tail]) > '9' && ch2lower(s[tail]) < 'a')
            || ch2lower(s[tail]) > 'z')
        {
            tail--;
            if (head > tail) break;
        }

        if (head > tail) break;

        if (ch2lower(s[head]) != ch2lower(s[tail])) return false;

        head++;
        tail--;
    }

    return true;
}

int main() {
    char s1[] = "A man, a plan, a canal: Panama";
    char s2[] = "race a car";
    char s3[] = "";
    char s4[] = "a";
    char s5[] = ".,";
    char s6[] = ".";
    char s7[] = " ";

    printf("%d\n", isPalindrome(s1));
    printf("%d\n", isPalindrome(s2));
    printf("%d\n", isPalindrome(s3));
    printf("%d\n", isPalindrome(s4));
    printf("%d\n", isPalindrome(s5));
    printf("%d\n", isPalindrome(s6));
    printf("%d\n", isPalindrome(s7));

    return 0;
}
