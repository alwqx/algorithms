// https://eoj.i64d.com/problem/2569/
#include <stdio.h>
#include <ctype.h>

#define MAXN 100000

int main() {
    char c, s[MAXN];
    int i, len=0;
    while((c=getchar())!=EOF)
        s[len++] = c;
    for(i=0; s[i]; i++)
        if(s[i] != ' ') s[i] = toupper(s[i]);

    printf("%s\n", s);
}