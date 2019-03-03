// https://pintia.cn/problem-sets/14/problems/811

#include <stdio.h>
#include <string.h>

#define MAXN 100

int main() {
    char s[MAXN], tmp;
    int j, N, len_s=0, i=0;
    while((tmp=getchar()) != '\n') {
        s[i++] = tmp;
        len_s++;
    }
    s[i] = '\n';
    scanf("%d", &N);

    for(i=0; i<N; i++) {
        tmp = s[0];
        for(j=0; j<len_s-1; j++)
            s[j] = s[j+1];
        s[len_s-1] = tmp;
    }

    printf("%s", s);
    return 0;
}