// https://pintia.cn/problem-sets/14/problems/809

#include <stdio.h>
#include <string.h>

#define MAXN 80

void readline(char s[]);

int main() {
    char *w, S1[MAXN], S2[MAXN], c[MAXN+1];
    readline(S1); readline(S2);

    int i, j;
    for(i=0;;i++) {
        if((strstr(S1, S2)==NULL))
            break;
        else {
            w = strstr(S1, S2);
            *w = '\0';
            strcpy(c, w+strlen(S2));
            strcat(S1, c);
        }
    }

    puts(S1);
    return 0;
}

void readline(char s[]) {
    int c, i = 0;
    while((c=getchar()) != '\n')
        s[i++] = c;

    s[i] = '\0';
}