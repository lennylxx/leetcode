#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

int minDistance(char *word1, char *word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    
    /* these two lines can be commented out */
    if (len1 == 0) return len2;
    if (len2 == 0) return len1;
    
    int(*d)[len2 + 1] = (int (*)[len2 + 1])calloc((len1 + 1) * (len2 + 1), sizeof(int));
    int i, j;
    
    d[0][0] = 0; /* dummy */
    for (i = 1; i <= len1; i++) d[i][0] = i;
    for (j = 1; j <= len2; j++) d[0][j] = j;
    
    for (i = 1; i <= len1; i++){
        for (j = 1; j <= len2; j++) {
            /* d[i][j] represents distance of word1[0..i-1] and word2[0..j-1] */
            if (word1[i - 1] == word2[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            }
            else {
                d[i][j] = min(
                    d[i][j - 1] + 1, /* insert a character(word2[j-1]) to the tail of word1[0..i-1] */
                    d[i - 1][j] + 1, /* delete a character(word1[i-1]) from the tail of word1[0..i-1] */
                    d[i - 1][j - 1] + 1 /* replace a character in tail of word1[0..i-1] */
                    );
            }
        }
    }
    return d[len1][len2];
}

int main() {
    printf("%d %d\n", minDistance("word", "wood"), 1);
    printf("%d %d\n", minDistance("word", "woord"), 1);
    printf("%d %d\n", minDistance("d", "word"), 3);
    printf("%d %d\n", minDistance("", "word"), 4);
    printf("%d %d\n", minDistance("abcd", "word"), 3);
    printf("%d %d\n", minDistance("ffff", "word"), 4);
    return 0;
}
