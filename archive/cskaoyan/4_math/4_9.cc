/*
王道考研机试指南 p92

素数筛
*/
#include <stdio.h>

#define MAXN 10000

int prime[MAXN];
int psize;
bool mark[MAXN+1];

void init() {
    int i, j;
    for(i=1; i<=MAXN; i++)
        mark[i] = false;
    psize = 0;

    for(i=2; i<MAXN; i++) {
        if(mark[i]) continue;
        prime[psize++] = i;
        for(j=i*i; j<=MAXN; j+=i)
            mark[j] = true;
    }
}

int main() {
    init();
    int i, n;
    bool isoutput;
    while(scanf("%d", &n) != EOF) {
        isoutput = false;
        for(i=0; i<psize && prime[i]<n; i++)
            if(prime[i]%10==1)
                if(!isoutput) {
                    printf("%d", prime[i]);
                    isoutput = true;
                }
            else printf(" %d", prime[i]);
        
        if(!isoutput)   printf("-1\n");
        else            putchar('\n');
    }
    
    return 0;
}