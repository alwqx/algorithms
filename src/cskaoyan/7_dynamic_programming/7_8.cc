/*
王道考研机试指南 p205

动态规划，0-1背包问题：采仙草一维数组优化
*/
#include <stdio.h>

#define INF 0x7ffffff

int max(int a, int b) {return a>b?a:b;}

struct E {
    int time; // 时间
    int value; // 价值
} list[101];

int dp[1001];

int main() {
    int i, j, T, M;
    while(scanf("%d %d", &T, &M) != EOF) {
        for(i=1; i<=M; i++)
            scanf("%d %d", &list[i].time, &list[i].value);
        for(i=0; i<=T; i++) dp[i] = 0;

        // start dp process
        for(i=1; i<=M; i++)
            for(j=T; j>=list[i].time; j--)
                dp[j] = max(dp[j-1], dp[j-list[i].time]+list[i].value);
        
        printf("%d\n", dp[T]);
    }

    return 0;
}