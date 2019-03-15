/*
王道考研机试指南 p94

素因数的个数
*/
#include <stdio.h>

#define MAXN 10001
bool mark[MAXN];
int prime[MAXN];
int psize;

void init() {
    int i, j;
    for(i=2; i<MAXN; i++)
        mark[i] = false;
    psize = 0;
    for(i=2; i<MAXN; i++) {
        if(mark[i]) continue;
        prime[psize++] = i;
        for(j=i*i; j<MAXN; j+=i) mark[j] = true;
    }
}

int main() {
    init();
    int i, n;

    int tmp, size, ans[40], e[40];
    while(scanf("%d", &n) != EOF) {
        size = 0;
        tmp = n;
        for(i=0; i<psize && prime[i]<=tmp; i++) {
            if(n%prime[i] == 0) {
                ans[size] = prime[i];
                e[size] = 0;
                while(n%prime[i] == 0) {
                    e[size]++;
                    n /= prime[i];
                }
            }
            size++;
            if(n == 1) break;
        }

        if(n != 1) {
            ans[size] = n;
            e[size++] = 1;
        }

        int sum = 0;
        for(i=0; i<size; i++)
            sum += e[i];
        
        printf("%d\n", sum);
    }

    return 0;
}