#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

bool isNumber(char* s) {
    if (s == NULL) return false;

    while (*s == ' ') {
        s++;
    }
    if (*s == '\0') return false;

    char *start = s;
    char *t = s + strlen(s) - 1;
    while (*t == ' ') {
        t--;
    }

    bool dot = false;
    bool exp = false;
    bool num = false;

    while (*s != '\0' && s != t + 1) {
        if (*s >= '0' && *s <= '9') {
            num = true;
        }
        else if (*s == '.') {
            if (exp || dot) return false;
            dot = true;
        }
        else if (*s == 'e') {
            if (!num || exp) return false;
            exp = true;
            num = false;
        }
        else if (*s == '-' || *s == '+') {
            if (s != start && *(s - 1) != 'e') return false;
        }
        else return false;

        s++;
    }

    return num;
}


int main() {
    assert(isNumber("0") == true);
    assert(isNumber("0!") == false);
    assert(isNumber(" 0.1 ") == true);
    assert(isNumber("abc") == false);
    assert(isNumber("1 a") == false);
    assert(isNumber("2e10") == true);
    assert(isNumber("2e10e10") == false);
    assert(isNumber("2e") == false);
    assert(isNumber("e10") == false);
    assert(isNumber("005047e+6") == true);
    assert(isNumber("3.2e6") == true);
    assert(isNumber("3.2e0.6") == false);
    assert(isNumber(".e06") == false);
    assert(isNumber("-1234") == true);
    assert(isNumber("+1234") == true);
    assert(isNumber("6+1") == false);
    assert(isNumber("1.2.3") == false);
    assert(isNumber("") == false);
    assert(isNumber(" ") == false);
    assert(isNumber(" . ") == false);
    assert(isNumber(" + ") == false);
    assert(isNumber("+1+2") == false);
    assert(isNumber(" e ") == false);
    assert(isNumber(".23") == true);
    assert(isNumber("00.") == true);
    assert(isNumber(" -54.53061") == true);

    printf("all tests passed!\n");
    return 0;
}
