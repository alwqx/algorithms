/*
王道考研机试指南 p77

数位拆解
*/
#include <stdio.h>

int main() {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    int bufa[20], bufb[20], sa=0, sb=0;
    while(a) {
        bufa[sa++] = a%10;
        a /= 10;
    }
    while(b) {
        bufb[sb++] = b%10;
        b /= 10;
    }

    int i, j, sum=0;
    for(i=0; i<sa; i++)
        for(j=0; j<sb; j++)
            sum += bufa[i]*bufb[j];
    
    printf("%d\n", sum);
    return 0;
}