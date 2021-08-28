/*
王道考研机试指南 p170

递归 枚举法
*/
#include <stdio.h>
#include <algorithm>

#define N 22

using namespace std;

int n;
bool mark[N];
int ans[N];
int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41};

bool judge(int x) {
    int i;
    // prime len is 13
    for(i=0; i<13; i++)
        if(prime[i] == x) return true;
    return false;
}

void printPrime() {
    int i;
    bool ok;
    for(i=1; i<=n; i++) ans[i] = i;

    do{
        ok = true;
        for(i=1; i<n; i++) {
            int index = ans[i]+ans[i+1];
            if(!judge(index)) {
                ok = false;
                break;
            }
        }

        if(!judge(ans[1]+ans[n])) ok = false;
        if(ok) {
            for(i=1; i<=n; i++) {
                if(i!=1) printf(" ");
                printf("%d", ans[i]);
            }
            printf("\n");
        }
    }while(next_permutation(ans+2, ans+n+1));
}
int main() {
    int i;
    while(scanf("%d", &n) != EOF)
        printPrime();

    return 0;
}