// https://pintia.cn/problem-sets/14/problems/806

#include <stdio.h>

#define MAXN 100

int main() {
    char c = 0;
    int a[MAXN], i, cnt=0;
    for(i=0; i<MAXN; i++)
        a[i] = 0;
    i = 0;

    while((c=getchar()) != '.') {
        if(c != ' ') {
            cnt++;
            a[i] = cnt;
        } else if(cnt != 0) {
            a[i]=cnt;
            i++;
            cnt=0;
        }
    }
    
    i = 0;
    if(a[i] == 0)
        return 0;
    else
        while(a[i] != 0) {
            if(i==0)
                printf("%d", a[i]);
            else
                printf(" %d", a[i]);
            i++;
        }

    return 0;
}
