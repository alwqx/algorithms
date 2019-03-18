/*
王道考研机试指南 p211

动态规划，多背包问题：买大米
*/
#include <stdio.h>

struct E {
    int price;
    int weight;
} list[2001];

int dp[101];

int max(int a, int b) {return a>b?a:b;}

int main() {
    int i, j, C, n, m, cnt;
    int price, weight, count; // 价格、重量、数量
    scanf("%d", &C);
    while(C--) {
        scanf("%d %d", &n, &m);
        cnt = 0;
        
        // 一组数据拆分成多个背包
        for(i=1; i<=m; i++) {
            scanf("%d %d %d", &price, &weight, &count);
            int c = 1;
            while(count-c>0) {
                count -= c;
                list[++cnt].price = c*price;
                list[cnt].weight = c*weight;
                c *= 2;
            }
            list[++cnt].weight = weight*count;
            list[cnt].price = price*count;
        }

        for(i=1; i<=n; i++) dp[i] = 0;
        for(i=1; i<=cnt; i++)
            for(j=n; j>=list[i].price; j--)
                dp[j] = max(dp[j], dp[j-list[i].price]+list[i].weight);

        printf("%d\n", dp[n]);
    }

    return 0;
}