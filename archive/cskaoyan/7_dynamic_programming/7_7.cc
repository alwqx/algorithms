/*
王道考研机试指南 p202

动态规划，0-1背包问题：采仙草
*/
#include <stdio.h>

int dp[101][1001];
struct E {
    int time; // 时间
    int value; // 价值
} list[101];

int max(int a, int b) {return a>b?a:b;}

int main() {
    int i, j, T, M, v, w;
    while(scanf("%d %d", &T, &M) != EOF) {
        for(i=1; i<=M; i++)
            scanf("%d %d", &list[i].time, &list[i].value);
        // init dp
        for(i=1; i<=T; i++) dp[0][i]=0;

        for(i=1; i<=M; i++)
            for(j=T; j>=list[i].time; j--)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-list[i].time]+list[i].value);
            for(j=list[i].time-1; j>=0; j--)
                dp[i][j] = dp[i-1][j];

        printf("%d\n", dp[M][T]);
    }

    return 0;
}