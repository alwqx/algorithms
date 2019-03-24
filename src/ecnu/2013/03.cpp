/*
去重排序
*/
#include <stdio.h>
#include <algorithm>

using namespace std;

int cmp(int a, int b) {
    if(a%10 != b%10) return a%10 < b%10;
    return a<b;
}

int num[101];
bool mark[101];

int main() {
    int i, j, t, n, m, cnt;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        cnt = 0;

        for(i=0; i<n; i++) mark[i] = false;
        for(i=0; i<n; i++) {
            scanf("%d", &m);
            if(mark[m]) continue;
            mark[m] = true;
            num[cnt++] = m;
        }

        sort(num, num+cnt, cmp);
        for(i=0; i<cnt; i++)
            if(i==0) printf("%d", num[i]);
            else printf(" %d", num[i]);
        putchar('\n');
    }

    return 0;
}