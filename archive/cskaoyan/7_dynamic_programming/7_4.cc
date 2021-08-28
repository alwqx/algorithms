/*
王道考研机试指南 p192

动态规划，最长公共子序列
*/
#include <stdio.h>
#include <string.h>

#define MAXN 101

int max(int a, int b) {return a>b?a:b;}

int main() {
    int i, j, k, dp[MAXN][MAXN];
    char s1[MAXN], s2[MAXN];
    int len1, len2;

    while(scanf("%s %s", s1, s2) != EOF) {
        for(i=0; i<MAXN; i++) {
            dp[0][i] = 0;
            dp[i][0] = 0;
        }
        len1=strlen(s1);
        len2=strlen(s2);
        
        for(i=1; i<=len1; i++)
            for(j=1; j<=len2; j++)
                if(s1[i-1] == s2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        
        printf("%d\n", dp[len1][len2]);
    }

    return 0;
}