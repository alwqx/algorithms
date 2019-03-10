// https://pintia.cn/problem-sets/994805260223102976/problems/994805314941992960
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 81

void v1();
void v2();

int main() {
    v1();
    return 0;
}

void v1() {
    char c, *wordptr[41];
    char s[MAXN], a[MAXN];
    int i=0, j=0, cnt=0;

    while((c=getchar()) != '\n') {
        if(c != ' ') s[i++] = c;
        else {
            s[i] = '\0';
            char *t = (char *) malloc(sizeof(char)*i);
            wordptr[cnt++] = strcpy(t, s);
            i = 0;
        }
    }
    s[i] = '\0';
    char *t = (char *) malloc(sizeof(char)*i);
    wordptr[cnt++] = strcpy(t, s);

    for(i=cnt-1; i>=0; i--)
        if(i==0)    printf("%s\n", wordptr[i]);
        else        printf("%s ", wordptr[i]);
}

/*
not work.
scanf can not read multi string with space!
*/
void v2() {
    char c, *wordptr[41];
    char s[MAXN], a[MAXN];
    scanf("%s", s);

    int i=0, j=0, cnt=0;
    for(i=0; i<strlen(s); i++) {
        if(s[i] != ' ') a[j++] = s[i];
        else {
            a[j] = '\0';
            char *t = (char *) malloc(sizeof(char)*j);
            wordptr[cnt++] = strcpy(t, s);
            j = 0;
        }
    }
    a[j] = '\0';
    char *t = (char *) malloc(sizeof(char)*j);
    wordptr[cnt++] = strcpy(t, s);

    for(i=cnt-1; i>=0; i--)
        if(i==0)    printf("%s\n", wordptr[i]);
        else        printf("%s ", wordptr[i]);
}