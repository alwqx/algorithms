/*
王道考研机试指南 p87

GCD
*/
#include <stdio.h>

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

int gcd1(int a, int b) {
    int t;
    while(b) {
        t = a%b;
        a = b;
        b = t;
    }
}

int main() {
    int a, b;
    while(scanf("%d %d", &a, &b) != EOF)
        printf("%d\n", gcd(a, b));
    
    return 0;
}