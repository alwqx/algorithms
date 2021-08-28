/*
王道考研机试指南 p188

动态规划，信封错排
*/
#include <stdio.h>

long long ans[21];

int main() {
    int i, n;
    // init ans
    ans[1]=0; ans[2]=1; ans[3]=2;
    for(i=4; i<=20; i++)
        ans[i] = (i-1)*ans[i-1]+(i-1)*ans[i-2];

    while(scanf("%d", &n) != EOF)
        printf("%lld\n", ans[n]);

    return 0;
}