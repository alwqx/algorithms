/*
王道考研机试指南 p170

递归 素数环
*/
#include <stdio.h>

#define N 22

int n, ans[N];
bool mark[N];
int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41};

bool judge(int x) {
    int i;
    // prime len is 13
    for(i=0; i<13; i++)
        if(prime[i] == x) return true;
    return false;
}

void check() {
    if(!judge(ans[n]+ans[1])) return;
    int i;
    for(i=1; i<=n; i++) {
        if(i!=1) printf(" ");
        printf("%d", ans[i]);
    }

    putchar('\n');
}

void dfs(int num) {
    if(num>1)
        if(!judge(ans[num]+ans[num-1])) return;
    if(num==n) {
        check();
        return;
    }

    // num is 1
    int i;
    for(i=2; i<=n; i++) {
        if(!mark[i]) {
            mark[i] = true;
            ans[num+1] = i;
            dfs(num+1);
            mark[i] = false;
        }
    }
}

int main() {
    int i, cas=0;
    while(scanf("%d", &n) != EOF) {
        for(i=0; i<=n; i++) mark[i] = false;

        cas++;
        ans[1] = 1;
        printf("Case %d: \n", cas);
        mark[1] = true;
        dfs(1);
    }

    return 0;
}