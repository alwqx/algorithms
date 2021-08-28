/*
王道考研机试指南 p196

动态规划，搬物体最优解
*/
#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAXN 2001
#define MAXM 1001
#define INF 0x7ffffff

int main() {
    int i, j, n, k, tmp;
    int ws[MAXN], dp[MAXM][MAXN];
    while(scanf("%d %d", &n, &k) != EOF) {
        for(i=1; i<=n; i++)
            scanf("%d", &ws[i]);
        sort(ws+1, ws+1+n);

        // init dp
        for(i=1; i<=n; i++)
            dp[0][i] = 0;
        
        for(i=1; i<=k; i++)
            for(j=2*i; j<=n; j++) {
                if(j>2*i) dp[i][j] = dp[i][j-1];
                else dp[i][j] = INF;
                
                // 比较
                tmp = dp[i-1][j-2]+(ws[j]-ws[j-1])*(ws[j]-ws[j-1]);
                if(dp[i][j]>tmp) dp[i][j] = tmp;
            }
        
        printf("%d\n", dp[k][n]);
    }

    return 0;
}