/*
王道考研机试指南 p202

动态规划，完全背包问题：存钱罐
*/
#include <stdio.h>
#define INF 0x7ffffff

int min(int a, int b) {return a<b?a:b;}
int dp[10001]; // 总重量不超过j时，所能达到的最小价值，计算的是剩余重量
struct E {
    int coin;
    int weight;
} list[501];

int main() {
    int i, j, T, n;
    int ew, cw, yw; // 空重，当前重，剩余重
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &ew, &cw);
        yw = cw-ew;
        scanf("%d", &n);
        for(i=1; i<=n; i++)
            // 按照价格（coin）递增输入
            scanf("%d %d", &list[i].coin, &list[i].weight);
        
        // init dp
        for(i=0; i<=yw; i++) dp[i] = INF;
        dp[0] = 0;

        // 遍历所有物品，可能不满足正好装满的情况，则打印impossible
        for(i=1; i<=n; i++)
            for(j=list[i].weight; j<=yw; j++)
                if(dp[j-list[i].weight] != INF)
                    dp[j] = min(dp[j-list[i].weight]+list[i].coin, dp[j]);

        // 存在背包恰好装满的情况，则输出
        if(dp[yw] != INF)
                printf("The minimum amount of money in the piggy-bank is %d.\n", dp[yw]);
        else    printf("This is impossible.\n");
    }

    return 0;
}