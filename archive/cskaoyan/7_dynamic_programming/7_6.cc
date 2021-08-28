/*
王道考研机试指南 p199

动态规划，扁担等分橘子问题，难度较大
*/
#include <stdio.h>

#define OFFSET 2000
#define INF 0x7ffffff

int dp[101][4001];
int list[101];

int main() {
    int i, j, t, n, cnt, cas=0;
    bool haszero;
    int tmp1, tmp2;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        haszero = false;
        cnt = 0;

        for(i=1; i<=n; i++) {
            scanf("%d", &list[++cnt]);
            if(list[cnt] == 0) {
                cnt--;
                haszero = true;
            }
        }
        n = cnt;
        for(i=-2000; i<=2000; i++)
            dp[0][i+OFFSET] = -INF;
        dp[0][0+OFFSET] = 0;
        for(i=1; i<=n; i++)
            for(j=-2000; j<=2000; j++) {
                tmp2 = tmp1 = -INF;
                if(j+list[i]<=2000 && dp[i-1][j+list[i]+OFFSET] != -INF)
                    tmp1 = dp[i-1][j+list[i]+OFFSET]+list[i];
                if(j-list[i]>=-2000 && dp[i-1][j-list[i]+OFFSET] != -INF)
                    tmp2 = dp[i-1][j-list[i]+OFFSET]+list[i];
                if(tmp1<tmp2) tmp1=tmp2;
                if(tmp1<dp[i-1][j+OFFSET]) tmp1=dp[i-1][j+OFFSET];
                dp[i][j+OFFSET] = tmp1;
            }
        
        printf("Case %d: ", ++cas);
        if(!dp[n][0+OFFSET])    puts(haszero?"0":"-1");
        else                    printf("%d\n", dp[n][0+OFFSET]/2);
    }
    
    return 0;
}