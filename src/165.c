#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
int compareVersion(char *version1, char *version2){
    #define MAX 1024
    int v1[MAX] = {0};
    int v2[MAX] = {0};
    char *pch = strtok(version1, ".");
    int i = 0;
    while (pch != NULL) {
        v1[i] = atoi(pch);
        pch = strtok(NULL, ".");
        i++;
    }

    pch = strtok(version2, ".");
    i = 0;
    while (pch != NULL) {
        v2[i] = atoi(pch);
        pch = strtok(NULL, ".");
        i++;
    }
    for (i = 0; i < MAX; i++) {
        if (v1[i] > v2[i]) return 1;
        else if (v1[i] < v2[i]) return -1;
    }
    return 0;
}
*/

int compareVersion(char *version1, char *version2){
    int i, j, v1, v2, len1, len2;
    i = j = v1 = v2 = 0;
    len1 = strlen(version1);
    len2 = strlen(version2);

    while (i < len1 || j < len2) {
        while (i < len1 && version1[i] != '.') {
            v1 = v1 * 10 + (version1[i] - '0');
            i++;
        }
        while (j < len2 && version2[j] != '.') {
            v2 = v2 * 10 + (version2[j] - '0');
            j++;
        }
        if (v1 > v2) return 1;
        else if (v1 < v2) return -1;
        else {
            v1 = v2 = 0;
            i++;
            j++;
        }
    }
    return 0;
}

int main() {
    char v1[] = "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.00.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000";
    char v2[] = "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000";

    printf("%d\n", compareVersion(v1, v2));
    return 0;
}
