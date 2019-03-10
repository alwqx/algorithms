// https://pintia.cn/problem-sets/994805260223102976/problems/994805323154440192
#include <stdio.h>

#define MAXN 100

int check(char *s);

int main() {
    printf("Not implement\n");
    return 0;

    int i, N;
    char s[MAXN];
    scanf("%d", &N);

    for(i=0; i<N; i++) {
        scanf("%s", s);
        if(check(s))    printf("YES\n");
        else            printf("NO\n");
    }
    return 0;
}

int check(char *s) {
    return 1;
}