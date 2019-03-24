#include <stdio.h>

int prime[10001];
bool mark[10001];
int psize;

void init() {
    int i, j;
    psize = 0;
    for(i=0; i<10001; i++) mark[i] = false;

    for(i=2; i<10001; i++) {
        if(mark[i]) continue;
        prime[psize++] = i;
        for(j=i*i; j<10001; j+=i) mark[j] = true;
    }
}

bool judge(int n) {
    int i, x;
    
    while(n) {
        x = n%10;
        if(x == 8) return true;
        n /= 10;
    }

    return false;
}

int main() {
    init();
    int i, n, flag, t;
    while(scanf("%d", &n) != EOF) {
        flag = 0;
        if(judge(n)) {
            printf("Yes\n");
            continue;
        }

        for(i=1; prime[i]<n; i++) {
            if(n%prime[i]==0 && judge(prime[i])) {
                printf("Yes\n");
                flag = 1;
            }
        }
        if(!flag) printf("No\n");
    }

    return 0;
}