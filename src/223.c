#include <stdio.h>

#define max(a,b)    (((a) > (b)) ? (a) : (b))
#define min(a,b)    (((a) < (b)) ? (a) : (b))

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {

    int s1 = (C - A) * (D - B);
    int s2 = (G - E) * (H - F);

    /* intersect square */
    int s0 = 0;

    /* left-bottom */
    int x1 = max(A, E);
    int y1 = max(B, F);

    /* right-top */
    int x2 = min(C, G);
    int y2 = min(D, H);

    if ((x2 - x1 > 0) && (y2 - y1) > 0)
    {
        s0 = (x2 - x1) * (y2 - y1);
    }

    return s1 + s2 - s0;
}

int main() {

    /* should be 45 */
    printf("%d\n", computeArea(-3, 0, 3, 4, 0, -1, 9, 2));

    return 0;
}
