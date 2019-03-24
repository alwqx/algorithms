/*
计算机专硕 上机题目
Problem B:分形代码
*/
#include <stdio.h>
#include <math.h>

void fractal(int n, int level) {
    int d;
    if(level == 1) {
        d = pow(3, n);
        printf("FD 1/%d\n", d);
        printf("LT 60\n");
        printf("FD 1/%d\n", d);
        printf("LT 240\n");
        printf("FD 1/%d\n", d);
        printf("LT 60\n");
        printf("FD 1/%d\n", d);
    } else {
        fractal(n, level-1);
        printf("LT 60\n");
        fractal(n, level-1);
        printf("LT 240\n");
        fractal(n, level-1);
        printf("LT 60\n");
        fractal(n, level-1);
    }
}

int main() {
    int i, n;
    while(scanf("%d", &n) != EOF)
        fractal(n, n);

    return 0;
}