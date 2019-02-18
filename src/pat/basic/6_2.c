#include <stdio.h>
#define MAXN 10

// https://pintia.cn/problem-sets/14/problems/734


double f(int n, double a[], double x);

int main() {
    int n, i;
    double a[MAXN], x;

    scanf("%d %lf", &n, &x);
    for(i=0; i<n; i++)
        scanf("%lf", &a[i]);

    printf("%.1f\n", f(n, a, x));
    return 0;
}

double f(int n, double a[], double x) {
    double sum = 0.0;
    double sub_sum = 1.0;
    int i;
    for(i=0; i<=n; i++) {
        sum += a[i]*sub_sum;
        sub_sum *= x;
    }

    return sum;
}