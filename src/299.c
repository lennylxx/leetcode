#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define min(a,b) ((a)<(b)?(a):(b))
char* getHint(char* secret, char* guess) {
    char hashs[10] = { 0 };
    char hashg[10] = { 0 };
    int len = strlen(secret);
    int bulls = 0, cows = 0;
    int i;
    for (i = 0; i < len; i++) {
        if (secret[i] == guess[i]) {
            bulls++;
        }
        else {
            hashs[secret[i] - '0']++;
            hashg[guess[i] - '0']++;
        }
    }
    for (i = 0; i < 10; i++) {
        cows += min(hashs[i], hashg[i]);
    }

    char *hint = (char *)malloc(5);
    sprintf(hint, "%dA%dB", bulls, cows);
    hint[5] = '\0';
    return hint;
}

int main() {
    assert(strcmp(getHint("1807", "7810"), "1A3B") == 0);
    assert(strcmp(getHint("1234", "0111"), "0A1B") == 0);
    assert(strcmp(getHint("1122", "2211"), "0A4B") == 0);

    printf("all tests passed!\n");

    return 0;
}
