/*
王道考研机试指南 p190

动态规划，最长递增子序列
*/
#include <stdio.h>
#define MAXN 26

int max(int a, int b) {return a>b?a:b;}

int main() {
    int i, j, k, dp[MAXN], heights[MAXN];
    scanf("%d", &k);
    for(i=1; i<=k; i++) scanf("%d", &heights[i]);
    
    int tmax;
    for(i=1; i<=k; i++) {
        tmax = 1;
        for(j=1; j<i; j++)
            if(heights[i]<=heights[j]) tmax = max(tmax, dp[j]+1);
        dp[i] = tmax;
    }

    // find tmax
    int ans = -1;
    for(i=1; i<=k; i++) ans = max(ans, dp[i]);
    printf("%d\n", ans);
    
    return 0;
}