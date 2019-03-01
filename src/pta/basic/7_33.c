// https://pintia.cn/problem-sets/14/problems/813

#include <stdio.h>

int find(int, int);

int main() {
    int a1, b1, a2, b2, a3, b3;
    scanf("%d/%d %d/%d", &a1, &b1, &a2, &b2);
    
    b3 = b1*b2;
    a3 = a1*b2 + a2*b1;
    int n = find(a3, b3);
    a3 /= n;
    b3 /= n;
    if(b3 == 1) {
        printf("%d", a3);
    } else {
        printf("%d/%d", a3, b3);
    }
    
    return 0;
}

int find(int a, int b) {
    int c;

    while(b != 0) {
        c = a%b;
        a = b;
        b = c;
    }

    return a;
}