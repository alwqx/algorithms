// https://pintia.cn/problem-sets/14/problems/812
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 500000
#define WORDN 100

int readlines(char *lineptr[]);

int main() {
    char *lineptr[MAXN];
    int wn = readlines(lineptr);
    int i;
    for(i=wn-1; i>=0; i--) {
        if(i==0)
            printf("%s", lineptr[i]);
        else
            printf("%s ", lineptr[i]);
    }
    return 0;
}

int readlines(char *lineptr[]) {
    char c, lastc, *p, word[MAXN];
    int cn=0, wn=0;
    lastc = c = getchar();
    while(c != '\n') {
        if(c != ' ') {
            word[cn] = c;
            cn++;
        } else {
            if(lastc != ' ') {
                word[cn] = '\0';
                p = (char *) malloc(sizeof(char)*cn);
                strcpy(p, word);
                lineptr[wn++] = p;
                cn = 0;
            }
        }
        lastc = c;
        c = getchar();
    }
    // add missing word
    if(cn != 0) {
        word[cn] = '\0';
        p = (char *) malloc(sizeof(char)*cn);
        strcpy(p, word);
        lineptr[wn++] = p;
    }

    // printf("number of word is %d\n", wn);

    return wn;
}