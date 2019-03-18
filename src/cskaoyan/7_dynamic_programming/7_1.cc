/*
王道考研机试指南 p186

动态规划，N阶楼梯问题
*/
#include <stdio.h>

long long ans[91];

int dp(int x) {
    if(x<1) return 0;
    if(x == 1) return 1;
    if(x == 2) return 2;

    return dp(x-1)+dp(x-2);
}

void v1();
void v2();

int main() {
    // v1();
    v2();
    
    return 0;
}

void v1() {
    int n;
    while(scanf("%d", &n) != EOF)
        printf("%d\n", dp(n));
}

void v2() {
    int i, n;

    ans[1] = 1;
    ans[2] = 2;
    for(i=3; i<=90; i++)
        ans[i] = ans[i-1] + ans[i-2];

    while(scanf("%d", &n) != EOF)
        printf("%lld\n", ans[n]);
}