// https://eoj.i64d.com/problem/2571/
#include <stdio.h>

int gcd(int a, int b);
int lcm(int a, int b);

int main() {
    int i, n;
    scanf("%d", &n);
    int a, b;
    for(i=0; i<n; i++) {
        scanf("%d %d", &a, &b);
        printf("%d %d\n", gcd(a, b), lcm(a, b));
    }
    return 0;
}

int gcd(int a, int b) {
    int c;
    while(b) {
        c = a%b;
        a = b;
        b = c;
    }

    return a;
}

int lcm(int a, int b) {
    return a*b/gcd(a, b);
}