// https://pintia.cn/problem-sets/994805260223102976/problems/994805323154440192
#include <stdio.h>
#include <string.h>

#define MAXN 101

int main() {
    int i, N;
    char s[MAXN];
    char *sp;
    scanf("%d", &N);

    int a, b, c;
    for(i=0; i<N; i++) {
        scanf("%s", s);
        if(strcmp(s, "PAT") == 0) {
            printf("YES\n");
            continue;
        }
        
        a=b=c=0;
        sp = s;
        while(*sp == 'A') {
            a++;
            sp++;
        }
        if(*sp == 'P') {
            sp++;
            while(*sp == 'A') {
                b++;
                sp++;
            }
            if(*sp == 'T') {
                sp++;
                while(*sp == 'A') {
                    c++;
                    sp++;
                }
                if(!(*sp) && b>0 && c==a*b) {
                    printf("YES\n");
                    continue;
                }
            }
        }

        printf("NO\n");
    }

    return 0;
}