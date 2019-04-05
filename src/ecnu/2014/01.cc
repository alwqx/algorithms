#include <stdio.h>
#include <algorithm>

using namespace std;

int a[100];

bool check(int *a, int num, int len) {
    int i, cnt=0;

    for(i=0; i<len; i++)
        if(a[i]==0 && a[i+1]==1) cnt++;
    if(cnt>num) return true;
    return false;
}

int main() {
    int i, j, m, n, tot;

    while(scanf("%d %d", &n, &m) != EOF) {
        tot = 0;
        for(i=0; i<100; i++) a[i] = 0;

        for(i=m; i<=n-m; i++){
            for(j=1; j<=i; j++) a[n-j] = 1;
            do{
                if(check(a, m, n)) tot++;
            }while(next_permutation(a, a+n));
        }

        printf("%d\n", tot);
    }

    return 0;
}