// https://pintia.cn/problem-sets/14/problems/2990
#include <stdio.h>
#define MAXN 1010

int num[MAXN];
int N, sum=0, pos=0, col=0;

void dfs(int x) {
    if(sum>N) return;
    else if(sum==N) {
        col++;
        printf("%d=%d", N, num[0]);
        for(int i=1; i<pos; i++)
            printf("+%d", num[i]);
        if(col%4==0 || pos==1)  putchar('\n');
        else                    putchar(';');
    } else
        for(int i=x; i<=N; i++) {
            sum+=i;
            num[pos++] = i;
            dfs(i);
            sum-=i;
            pos--;
        }
}

int main() {
    // extern int N;
    scanf("%d", &N);
    dfs(1);
    return 0;
}