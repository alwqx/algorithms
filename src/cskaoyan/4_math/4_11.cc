/*
王道考研机试指南 p99

整除问题
*/
#include <stdio.h>
#include <string.h>

#define MAXN 1010

int prime[MAXN];
bool mark[MAXN];
int psize;

void init() {
    int i, j;
    psize = 0;
    for(i=2; i<MAXN; i++) {
        if(mark[i]) continue;
        prime[psize++] = i;
        mark[i] = true;
        for(j=i*i; j<MAXN; j+=i)
            mark[j] = true;
    }
}

int cntn[MAXN];
int cnta[MAXN];

int main() {
    init();
    int i, j, n, a, ans, t;
    while(scanf("%d %d", &n, &a) == 2) {
        for(i=0; i<MAXN; i++)
            cnta[i] = cntn[i] = 0;

        for(i=0; i<psize; i++) {
            t = n;
            while(t) {
                cntn[i] += t/prime[i];
                t /= prime[i];
            }
        }

        ans = 123123123;
        for(i=0; i<psize; i++) {
            while(a%prime[i] == 0) {
                cnta[i]++;
                a /= prime[i];
            }
            if(cnta[i] == 0) continue;
            if(ans>(cntn[i]/cnta[i]))
                ans = cntn[i]/cnta[i];
        }

        printf("%d\n", ans);
    }

    return 0;
}