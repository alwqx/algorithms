#include <stdio.h>
#include <string.h>

int dp[510][510];
char stra[510];
char strb[510];

int f(int i, int j) {
    if(stra[i-1] == strb[j-1]) return 0;
    return 1;
}

int mmin(int x, int y, int z) {
    int a = x<y?x:y;
    int b = x<z?x:z;

    return a<b?a:b;
}

int main() {
    int i, j, n, lena, lenb;
    scanf("%d", &n);
    while(n--) {
        scanf("%s", stra);
        scanf("%s", strb);
        lena = strlen(stra);
        lenb = strlen(strb);

        for(i=1; i<=lena; i++) dp[i][0] = i;
        for(i=1; i<=lenb; i++) dp[0][i] = i;
        dp[0][0] = 0;

        for(i=1; i<=lena; i++)
            for(j=1; j<=lenb; j++)
                dp[i][j] = mmin(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+f(i, j));
        printf("%d\n", dp[lena][lenb]);
    }

    return 0;
}